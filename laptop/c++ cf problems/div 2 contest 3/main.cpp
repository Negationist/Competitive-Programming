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
    int n,sum=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        sum+=((2*i-1)*i);
    }
    cout << sum << " " << 2*n << endl;
    for(int i=n;i>0;i--){
        for(int j=1;j<3;j++){
            cout << j << " " << i << " ";
            for(int k=1;k<n+1;k++){
                cout << k << " ";
            }
            cout << "\n";
        }
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
