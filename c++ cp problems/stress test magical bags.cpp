#include <bits/stdc++.h>
#define int long long
using namespace std;

// ----------- BRUTE FORCE SOLUTION -------------
int solve_brute(const vector<vector<int>>& bag) {
    int n = bag.size();
    // Determine which pairs are originally good
    vector<vector<bool>> originally_good(n, vector<bool>(n,false));
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            bool have_less = false, have_greater = false;
            for(int x: bag[i]) for(int y: bag[j]) {
                if(x < y) have_less = true;
                if(x > y) have_greater = true;
            }
            originally_good[i][j] = originally_good[j][i] = (have_less && have_greater);
        }
    }
    // Try all non‑empty subsets of each bag
    int best = INT_MAX;
    vector<int> sizes(n), masks(n);
    for(int i=0; i<n; i++) {
        sizes[i] = bag[i].size();
        masks[i] = (1<<sizes[i]) - 1;
    }
    vector<vector<int>> cur = bag;
    function<void(int)> dfs = [&](int i){
        if(i == n){
            // Check each bag is nonempty
            int total = 0;
            for(int t=0; t<n; t++) {
                if(cur[t].empty()) return;
                total += cur[t].size();
            }
            // Check every originally good pair remains good
            for(int p=0; p<n; p++){
                for(int q=p+1; q<n; q++){
                    if(originally_good[p][q]) {
                        bool less=false, greater=false;
                        for(int x:cur[p]) for(int y:cur[q]){
                            if(x < y) less = true;
                            if(x > y) greater = true;
                        }
                        if(!(less && greater)) return;
                    }
                }
            }
            best = min(best, total);
            return;
        }
        // iterate over all nonempty subsets of bag i
        for(int m=1; m<=masks[i]; m++){
            cur[i].clear();
            for(int b=0; b<sizes[i]; b++){
                if(m & (1<<b)) cur[i].push_back(bag[i][b]);
            }
            dfs(i+1);
        }
    };
    dfs(0);
    return best;
}

// -------- YOUR OPTIMIZED SOLUTION (adapted) -------------
void solve_opt(istream& in, ostream& out) {
    using ll = long long;
    const int INF = 1e10;
    int n;
    in >> n;
    vector<int> color(n,2);  // 0 = white, 1 = black, 2 = uncolored
    vector<pair<pair<int,int>, set<int>>> b(n);
    set<int> openings, closings, whites;
    for(int i=0;i<n;i++){
        int k; in >> k;
        while(k--){
            int x; in >> x;
            b[i].second.insert(x);
        }
        b[i].first.first = *b[i].second.begin();
        b[i].first.second = *b[i].second.rbegin();
        if(b[i].second.size()==1){
            color[i] = 0;
            whites.insert(b[i].first.first);
        }
    }
    whites.insert(-INF);
    whites.insert(INF);
    // classify simple blacks
    for(int i=0;i<n;i++){
        if(color[i]==2){
            auto it = whites.lower_bound(b[i].first.first);
            if(it!=whites.end() && *it < b[i].first.second){
                color[i] = 1;
            } else {
                openings.insert(b[i].first.first);
                closings.insert(b[i].first.second);
            }
        }
    }
    // prepare the “can_be” set
    auto cmp = [&](auto &A, auto &B){
        if(A.second==B.second) return A.first < B.first;
        return A.second < B.second;
    };
    set<pair<int,int>, decltype(cmp)> can_be(cmp);
    map<pair<int,int>,int> idx_of;
    for(int i=0;i<n;i++){
        if(color[i]!=2) continue;
        int l = b[i].first.first, r = b[i].first.second;
        // find first closing > l
        auto itc = closings.upper_bound(l);
        int fc = (itc==closings.end() ? r : *itc);
        // find last opening < r
        auto ito = openings.lower_bound(r);
        int lo = (ito==openings.begin() ? l : *prev(ito));
        bool no_close = (fc==r);
        bool no_open  = (lo==l);
        if(!no_close && !no_open){
            int lo2 = *b[i].second.lower_bound(lo);
            if(lo2 <= fc){
                can_be.insert({l,r});
                idx_of[{l,r}] = i;
            } else {
                color[i] = 1;
            }
        } else {
            can_be.insert({l,r});
            idx_of[{l,r}] = i;
        }
    }
    // propagate colors
    while(!can_be.empty()){
        auto cur = *can_be.begin();
        can_be.erase(can_be.begin());
        int id = idx_of[cur];
        color[id] = 0;
        while(true){
            auto it = can_be.lower_bound(cur);
            if(it==can_be.end() || it->first > cur.second) break;
            color[idx_of[*it]] = 1;
            can_be.erase(it);
        }
    }
    int ans = 0;
    for(int c: color) ans += (c + 1);
    out << ans << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    mt19937 rng(123456);
    const int TESTS = 10000;

    for(int t=1; t<=TESTS; t++){
        // generate random small case
        int n = rng()%3 + 2;          // 2..4 bags
        vector<vector<int>> bags(n);
        set<int> used;
        for(int i=0; i<n; i++){
            int sz = rng()%3 + 1;     // 1..3 items
            while((int)bags[i].size() < sz){
                int x = rng()%20 + 1;
                if(used.insert(x).second){
                    bags[i].push_back(x);
                }
            }
            sort(bags[i].begin(), bags[i].end());
        }

        // build input string
        stringstream sinp;
        sinp << n << "\n";
        for(auto &v : bags){
            sinp << v.size();
            for(int x: v) sinp << " " << x;
            sinp << "\n";
        }
        string inp = sinp.str();

        // run optimized
        stringstream in_opt(inp), out_opt;
        solve_opt(in_opt, out_opt);
        int ans_opt = stoi(out_opt.str());

        // run brute
        int ans_br = solve_brute(bags);

        if(ans_opt != ans_br){
            cout << "❌ Mismatch on test #" << t << "\n";
            cout << "Input:\n" << inp;
            cout << "Optimized: " << ans_opt << "\n";
            cout << "Brute:     " << ans_br << "\n";
            return 0;
        }
        if(t % 1000 == 0) {
            cout << "✅ Passed " << t << " tests\n";
        }
    }
    cout << "🎉 All " << TESTS << " tests passed!\n";
    return 0;
}
