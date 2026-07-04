#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

void solve(){
    int n,k;
    cin >> n >> k;
    vi cands;
    int temp = n-(k+1);
    while(temp>=0){
        cands.pb(temp);
        temp-=(k+1);
    }
    reverse(cands.begin(),cands.end());
    priority_queue<int> q;
    int j = 0;
    int sze = cands.size();
    int ans = 0;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        q.push(z);
        if(j<sze && i==cands[j]){
            ans+=q.top();
            q.pop();
            ++j;
        }
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
