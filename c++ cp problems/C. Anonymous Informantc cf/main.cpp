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
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int last = n-1;
    for(int i=0;i<min(n,k);i++){
        if(a[last]>n){
            cout << "No\n";
            return;
        } else{
            last = (last-a[last]+n)%n;
        }
    }
    cout << "Yes\n";
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
