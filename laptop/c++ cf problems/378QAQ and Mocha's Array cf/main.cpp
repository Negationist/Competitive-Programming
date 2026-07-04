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
    int a[n], mn, next;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    mn = a[0];
    bool found = false;
    for(int i=0;i<n;i++){
        if(!found){
        if(a[i]%mn != 0){
           next = a[i];
           found = true;
        }
        } else{
           if(a[i]%mn != 0 && a[i]%next != 0){
            cout << "No\n";
            return;
           }
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
