#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n,k;
    cin >> n >> k;
    priority_queue<int> q;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        q.push(z);
    }
    ++k;
    int ans = 0;
    while(q.size() && k--){
        ans+=q.top();
        q.pop();
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
