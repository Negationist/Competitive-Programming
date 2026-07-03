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
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

void solve(){
    int n;
    cin >> n;
    int ans = 0;
    priority_queue<int> q;
    for(int i=0;i<n;i++){
        int z; cin >> z;
        if(q.size() && q.top()+z>0){
            ans+=q.top();
            q.pop();
            ans+=z;
            q.push(-z);
        }
        q.push(-z);
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}