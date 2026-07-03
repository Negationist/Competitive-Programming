#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int MOD  = 1e9+7;

void solve(){
    vector<int> pow(100010);
    pow[0] = 1;
    for(int i=1;i<100010;i++){
        pow[i] = (pow[i-1]*2)%MOD;
    }
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
    }
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        cout << pow[a] << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
