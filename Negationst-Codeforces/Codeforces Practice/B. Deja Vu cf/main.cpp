#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void solve(){
    int n,q;
    cin >> n >> q;
    vi a(n), x;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int mn = LLONG_MAX;
    for(int i=0;i<q;i++){
        int z;
        cin >> z;
        if(z<mn){
            mn = z;
            x.pb(z);
        }
    }
    for(int i=0;i<x.size();i++){
        for(int j=0;j<n;j++){
            if(a[j]%(1<<x[i])==0){
                a[j]+=(1<<(x[i]-1));
            }
        }
    }
    for(int x : a){
        cout << x << " ";
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
