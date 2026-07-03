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
    int n,x,y;
    cin >> n >> x >> y;
    x--;
    y--;
    vi ans(n);
    for(int i=0;i<n;i++){
        ans[(x+i)%n] = i%2;
    }
    if(n%2==1 || (x-y)%2==0){
        ans[x] = 2;
    }
    for(int x : ans){
        cout << x << " ";
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
