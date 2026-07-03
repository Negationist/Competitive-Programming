#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
const int inf = 1LL<<60;
void solve(){
    int n,k;
    string s;
    cin >> n >> k >> s;
    vector<int> sum;
    int cur = 0;
    priority_queue<int> q;
    for(int i=n-1;i>0;i--){
        cur+=(s[i]=='1'?1:-1);
        q.push(cur);
    }
    int ans = 1;
    int *ptr = &ans;
    while(q.size() && q.top()>0){
        k-=q.top();
        q.pop();
        (*ptr)++;
        if(k<=0){
            cout << ans << "\n";
            return;
        }
    }
    cout << -1 << "\n";
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
