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
    if(n<5){
        cout << -1 << "\n";
        return;
    }
    for(int i=1;i<=n;i++){
        if(i%2==1 && i!=5){
            cout << i << " ";
        }
    }
    cout << "5 4 ";
    for(int i=1;i<=n;i++){
        if(i%2==0 && i!=4){
            cout << i << " ";
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
