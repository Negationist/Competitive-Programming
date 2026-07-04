#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int gcd(int a, int b){
    if(a==0) return b;
    return gcd(b%a,a);
}

void solve(){
    int n;
    cin >> n;
    vi a(n);
    int z;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(i==0) z=a[i];
        else z = gcd(z,a[i]);
    }
    for(int i=0;i<n;i++){
        a[i]/=z;
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
