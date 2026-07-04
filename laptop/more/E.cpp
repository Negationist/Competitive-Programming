#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
struct RollbackUF {
    vi e;
    RollbackUF(int n) : e(n, -1){}
    int size(int x) {return -e[find(x)];}
    int find(int x) {return e[x] < 0 ? x : find(e[x]);}
    bool join(int a, int b){
        a = find(a), b = find(b);
        if(a == b) return false;
        if(e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }

};
int main()
{
    int t; cin >> t;
    while(t-->0){
        int n, m, k; cin >> n >> m >> k;
        int tmp = n;
        RollbackUF dsu(n);
        vector<pair<int, pair<pii, int>>> edges;
        vector<ll> indices;
        ll res = 0;
        for(int i = 0; i < m; i++){
            int u, v, w; cin >> u >> v >> w;
            u--; v--;
            if(w == 0){
                if(dsu.join(u, v)){
                    n -= 1;
                    indices.push_back(i + 1);
                }
            }
            else{
                edges.push_back({w, {{u, v}, i + 1}});
            }
        }
        //cerr << "Hello\n";
        sort(edges.begin(), edges.end());
        ll cnt = 0; ll i1 = 0;
        while(cnt < n - k - 1){
            int n1 = edges[i1].second.first.first;
            int n2 = edges[i1].second.first.second;
            cerr << n1 << " " << n2 << "\n";
            if(dsu.join(n1, n2)){
                //cerr << "checking\n";
                res += edges[i1].first;
                cnt += 1;
                indices.push_back(edges[i1].second.second);
            }
            i1 += 1;
        }
        //cerr << "Hello\n";
        vector<pair<ll, ll>> new_edges;
        ll cnt2 = 0;
        for(int i = 0; i < tmp - 1; i++){
            if(dsu.join(i, i + 1)){
                new_edges.push_back({i + 1, i + 2});
                res += 1;
                indices.push_back(m + cnt2 + 1);
                cnt2 += 1;
            }
        }
        cout << new_edges.size() << "\n";
        for(int i = 0; i < new_edges.size(); i++){
            cout << new_edges[i].first << " " << new_edges[i].second << "\n";
        } 
        cout << res << "\n";
        for(int i = 0; i < indices.size(); i++){
            cout << indices[i] << " ";
        }
        cout << "\n";

    }
}