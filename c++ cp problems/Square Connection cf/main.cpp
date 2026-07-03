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
void solve(){
    int s,t;
    cin >> s >> t;
    i128 lo = 1, hi = sqrt(1e10);
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if((mid*mid)<=s+t){
            lo = mid+1;
        } else{
            hi = mid-1;
        }
    }
    if(hi*hi==(s+t)){
        cout << "1 " << t << "\n";
        return;
    }
    int rev = (s<t);
    if(rev) swap(s,t);
    int d = (s-t)%4, u = 0;
    if(!d){
        u = 1+(s-t)/4;
    } else if(d==1 || d==3){
        u = (1+s-t)/2;
    }
    if(u*u>s){
        cout << "2 " << u*u-s << " " << (rev?s:t) << "\n";
        return;
    }
    if(rev) swap(s,t);
    int parity = (!(t&1)^(s&1)); //U = 2*x+parity
    lo = 0; hi = 1e9;
    while(lo<=hi){
        i128 mid = lo+(hi-lo)/2;
        i128 U = 2*mid+parity, u1 = U*U-s, a = (u1-t+1)/2, u2 = a*a-u1;
        if(u1<=0){
            lo = mid+1;
        } else if(max(u1,u2)>(i128)(4e18)){
            hi = mid-1;
        } else{
            cout << "3 " << (ll)u1 << " " << (ll)u2 << " " << t << "\n";
            return;
        }
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
