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
    int prod = 1;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        if(z==0){
            prod = 0;
        }
        if(!prod) continue;
        prod*=(z/abs(z));
    }
    if(prod <= 0){
        cout << "0\n";
    } else{
        cout << "1\n 1 0\n";
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
