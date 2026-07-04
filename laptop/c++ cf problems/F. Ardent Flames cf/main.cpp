#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define ld long double
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
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    vi h(n),x(n);
    for(int i=0;i<n;i++) cin >> h[i];
    for(int i=0;i<n;i++) cin >> x[i];
    auto check = [&](int a){
        bool win = false;
        vi suff = h, pref = h;
        for(int i=0;i<n;i++){
            suff[i]+=(x[i]*a);
            pref[i]+=((1e9-x[i])*a);
        }
        vi suffnum(n),prefnum(n);
        ordered_set<int> prefset, suffset;
        for(int i=0;i<n;i++){
            int goal = (1e9-x[i]+m)*a;
            //cout << "on pref " << i << ". goal is " << goal << "\n";
            prefnum[i] = prefset.order_of_key(goal+1);
            //cout << "got " << prefnum[i] << "\n";
            prefset.insert(pref[i]);
        }
        for(int i=n-1;i>=0;i--){
            suffset.insert(suff[i]);
            int goal = (x[i]+m)*a;
            //cout << "on suff " << i << ". goal is " << goal << "\n";
            suffnum[i] = suffset.order_of_key(goal+1);
            //cout << "got " << suffnum[i] << "\n";
        }
        for(int i=0;i<n;i++){
            if(prefnum[i]+suffnum[i]>=k){
                win = true;
            }
        }
        return win;
    };
    /*int lo = 1, hi = 1e9+10;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(check(mid)){
            hi = mid-1;
        } else{
            lo = mid+1;
        }
    }
    if(lo>1e9){
        cout << -1 << "\n";
    } else{
        cout << lo << "\n";
    }*/
    check(15);
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
