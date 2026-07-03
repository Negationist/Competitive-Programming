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
    if(b%a==0) return a;
    return gcd(b%a,a);
}


void solve(){
    int n;
    cin >> n;
    int a[n];
    int GCD;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(!i) continue;
        if(i==1) GCD = gcd(a[0],a[1]);
        else GCD = gcd(GCD,a[i]);
    }
    cout << a[n-1]/GCD << "\n";
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
