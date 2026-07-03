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
    int sum = 0;
    int mx = 0;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        mx = max(mx,z);
        sum+=z;
    }
    int res = sum-mx;
    if(res>=n || mx==0){
        cout << "Puss in Boots\n";
    } else{
        cout << "Donkey\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
