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
    int k,q;
    cin >> k >> q;
    int a[k];
    for(int i=0;i<k;i++){
        cin >> a[i];
    }
    for(int i=0;i<q;i++){
        int n;
        cin >> n;
        if(n<a[0]){
            cout << n << " ";
        } else{
            cout << a[0]-1 << " ";
        }
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
