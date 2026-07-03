#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
#define vll vector<pair<long long,long long>>
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

void solve(){
   int n;
   cin >> n;
   ll ans = 0;
   vi l(n), r(n);
   set<int> used;
   vii tot;
   for(int i=0;i<n;i++){
        cin >> l[i] >> r[i];
        tot.pb({l[i]+r[i], i});
        ans+=r[i];
        ans+=(r[i]-l[i]);
   }
   if(n==1){
        cout << r[0]-l[0] << "\n";
        return;
   }
   sort(all(tot));
   for(int i=0;i<n/2;i++){
        ans-=tot[i].ff;
        used.insert(tot[i].ss);
   }
   ll r_ans = 0;
   if(n&1){
        for(int i=0;i<n;i++){
            if(used.find(i) == used.end()){
                r_ans = max(r_ans, ans - r[i]);
            } else{
                ll temp_ans = ans+(l[i]+r[i])-(tot[n/2].ff)-r[i];
                r_ans = max(r_ans, temp_ans);
            }
        }
        cout << r_ans << "\n";
   } else{
        cout << ans << "\n";
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