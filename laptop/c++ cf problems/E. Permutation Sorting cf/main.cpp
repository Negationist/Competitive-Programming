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

template <typename T>
using o_Tree = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

void solve(){
    int n;
    cin >> n;
    vii segs;
    vi a(n+1);
    vi ans(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(i<=a[i]){
            segs.pb({i,a[i]});
            segs.pb({i+n,a[i]+n});
        } else{
            segs.pb({i,a[i]+n});
        }
    }
    sort(segs.begin(),segs.end(),
        [](const pii &a, const pii &b){
                return a.ss<b.ss;
            }
         );
    o_Tree<int> tree;
    for (auto [l,r] : segs){
        int len = r-l;
        if(l<=n){
            int res = (int)(tree.size())-tree.order_of_key(l);
            ans[a[l]] = len-res;
        }
        tree.insert(l);
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
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
