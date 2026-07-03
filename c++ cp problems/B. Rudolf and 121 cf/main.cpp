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
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=1;i<n-1;i++){
        int num = a[i-1];
        a[i-1]-=num;
        a[i]-=2*num;
        a[i+1]-=num;
        if(a[i]<0||a[i+1]<0){
            cout << "no\n";
            return;
        }
    }
    if(a[n-1]||a[n-2]){
        cout << "no\n";
        return;
    }
    cout << "yes\n";
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
