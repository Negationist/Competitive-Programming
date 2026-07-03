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
    int n,k;
    cin >> n >> k;
    int inc = 1;
    vi a(n,-1);
    for(int i=k-1;i<n;i+=k){
        a[i] = inc++;
    }
    for(int i=0;i<n;i++){
        if(a[i]==-1){
            a[i] = inc++;
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
