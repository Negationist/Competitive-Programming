#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

struct CustomComparator {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return a.second < b.second;
    }
};

void solve(){
    int n;
    cin >> n;
    map<pii,int> ans;
    vii c;
    vii og;
    set<pii> seen;
    map<pii,int> cnt;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        if(seen.find({a,b})==seen.end()){
            c.pb({a,b});
            seen.insert({a,b});
        }
        og.pb({a,b});
        cnt[{a,b}]++;
    }
    sort(c.begin(), c.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    });
    set<pii, CustomComparator> cur;
    set<pii, CustomComparator> bye;
    multiset<int> left;
    left.insert(-1);

    for(int i=0;i<n;i++){
        int l = c[i].ff, r=c[i].ss;
        vii gone;
        for(auto x : bye){
            if(x.ss<l){
                gone.pb(x);
            } else break;
        }
        for(auto x : gone){
            cur.erase(x);
            bye.erase(x);
            left.erase(left.find(x.ff));
        }
        auto it = cur.lower_bound({0,r});
        if(it!=cur.end()){
            int right = it->second;
            int leftbound = *left.rbegin();
            int res = (right-leftbound+1)-(r-l+1);
            ans[{l,r}]=res;
        }
        cur.insert({l,r});
        bye.insert({l,r});
        left.insert(l);
    }
    for(int i=0;i<n;i++){
        if(cnt[og[i]]>1) cout << 0 << "\n";
        else cout << ans[og[i]] << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
