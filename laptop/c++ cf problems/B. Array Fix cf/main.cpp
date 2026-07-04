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
    int mn = a.back();
    for(int i=n-2;i>=0;i--){
        if(a[i]>mn){
            if(a[i]<10){
                cout << "NO\n";
                return;
            } else{
                int f = a[i]%10;
                int s = a[i]/10;
                if(f<=mn && s<=mn && s<=f){
                    mn = s;
                } else{
                    cout << "NO\n";
                    return;
                }
            }
        }
        else mn = a[i];
    }
    cout << "YES\n";
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
