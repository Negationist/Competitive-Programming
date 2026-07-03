#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

const double eps = 1e-9;

void solve(){
    cout << fixed << setprecision(18);
    int n,k;
    cin >> n >> k;
    vector<double> p(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        p[i] = atan2(b,a);
    }
    sort(p.begin(),p.end());
    for(int i=0;i<n;i++){
        p.pb(p[i]+2*M_PI);
    }
    double ans = 0;
    for(int i=0;i<n;i++){
        if(i && abs(p[i]-p[i-1])<eps) continue;
        else{
            int j = i+k;
            ans = max(ans,p[j]-p[i]);
        }
    }
    reverse(p.begin(),p.end());
    for(int i=0;i<n;i++){
        if(i && abs(p[i]-p[i-1])<eps) continue;
        else{
            int j = i+k;
            ans = max(ans,p[i]-p[j]);
        }
    }
    cout << (ans?ans:2*M_PI) << "\n";
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
