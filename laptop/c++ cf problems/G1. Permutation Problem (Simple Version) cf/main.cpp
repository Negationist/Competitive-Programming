#include <bits/stdc++.h>
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
using ll = long long;
const int maxN = 1e5+5;
int cnt[maxN] = {};
void solve(){
    int n;
    cin >> n;
    vector<vi> extra(n+1);
    vector<vi> divisors(n+1);
    vii a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i].ff;
        a[i].ss = i;
    }
    for(int i=1;i<=n;i++){
        int z = __gcd(a[i].ff,a[i].ss);
        a[i].ff/=z;
        a[i].ss/=z;
        extra[a[i].ff].pb(a[i].ss);
        for(int j=1;j<=sqrt(a[i].ff);j++){
            if(a[i].ff%j==0){
                divisors[i].pb(a[i].ff/j);
                if(j!=sqrt(a[i].ff)){
                    divisors[i].pb(j);
                }
            }
        }
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        unordered_map<int,bool> visited; //make ordered?
        for(int x : extra[i]){
            if(!visited[x]){
                visited[x] = true;
                cnt[x] = 1;
            } else{
                ++cnt[x];
            }
        }
        for(int j=i;j<=n;j+=i){
            if(i%a[j].ss!=0) continue; //extra divides need
            else{
                for(int x : divisors[i]){
                    if(!visited[x]){
                        cnt[x] = 0;
                    }
                    ans+=cnt[x];
                }
            }
        }
        cout << "ans is now " << ans << "\n";
    }
    for(int i=0;i<=n;i++){
        if(a[i].ss==1){
            --ans;
        }
    }
    cout << ans/2 << "\n";
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
