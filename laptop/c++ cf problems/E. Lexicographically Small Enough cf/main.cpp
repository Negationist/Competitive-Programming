#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

using ordered_set = tree<
    pair<int, int>,                  // Pair of integers
    null_type,                            // No mapped type
    less<std::pair<int, int>>,       // Comparator
    rb_tree_tag,                          // Red-Black tree
    tree_order_statistics_node_update     // Order-statistics support
>;
const int inf = 1e13;
void solve(){
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    set<int> p[26];
    ordered_set tree;
    for(int i=0;i<n;i++){
        p[s[i]-'a'].insert(i);
        tree.insert({i,s[i]-'a'});
    }
    int ans = inf;
    int n_loss = 0;
    for(int i=0;i<n;i++){
        int cur = t[i]-'a';
        pii best = {inf,inf};
        for(int j=0;j<cur;j++){
            if(p[j].size()){
                int x = *p[j].begin();
                if(x<best.ff){
                    best = {x,j};
                }
            }
        }
        int num = tree.order_of_key(best);
        if(best.ff!=inf){
            ans = min(ans,n_loss+num);
        }
        if(p[cur].size() && n_loss!=inf){
             int y = *p[cur].begin();
             int num2 = tree.order_of_key({y,cur});
             n_loss+=num2;
             p[cur].erase(y);
             tree.erase({y,cur});
        } else{
            n_loss = inf;
        }
    }
    cout << (ans!=inf?ans:-1) << "\n";
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
