#include <bits/stdc++.h>
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
    vector<string> s(2);
    cin >> s[0] >> s[1];
    vl a,b,c,d;
    ll x0 = 0, y0 = 0, x1 = 0, y1 = 0;
    ll ans = 0;
    for(int i=0;i<n;i++){
        if(s[0][i]=='0'){
            ++x0; 
        } else{
            ++y0;
        }
        ans+=(min(x0,y0)*n);
        if(x0>y0){
            a.pb(x0-y0);
        } else if(x0<y0){
            b.pb(y0-x0);
        }
        if(s[1][i]=='0'){
            ++x1; 
        } else{
            ++y1;
        }
        ans+=(min(x1,y1)*n);
        if(x1>y1){
            c.pb(x1-y1);
        } else if(x1<y1){
            d.pb(y1-x1);
        }
    }
    sort(all(a));
    sort(all(b));
    sort(all(c));
    sort(all(d));
    if(sz(a) && sz(d)){
        ll j = -1, sum = 0;
        for(int i=0;i<sz(a);i++){
            while(j+1<sz(d) && d[j+1]<=a[i]){
                ++j;
                sum+=d[j];
            }
            ll res = sum+(sz(d)-(j+1))*a[i];
            ans+=res;
        }
    }
    if(sz(b) && sz(c)){
        ll j = -1, sum = 0;
        for(int i=0;i<sz(b);i++){
            while(j+1<sz(c) && c[j+1]<=b[i]){
                ++j;
                sum+=c[j];
            }
            ll res = sum+(sz(c)-(j+1))*b[i];
            ans+=res;
        }
    }
    cout << ans << "\n";
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