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
    int x,n,ans=0;
    cin >> n >> x;
    for(int i=max(x,2LL);i<=n;i++){
        if(x%(2*i-2)==0){
            ans+=(n%(2*i-2)==0);
            continue;
        }
        int copyN = n;
        copyN%=(2*i-2);
        if(copyN==0) copyN = 2*i-2;
        ans+=(abs(copyN-i)==i-x);
    }
    cout << ans << "\n";
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
