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
    int n,l,r;
    cin >> n >> l >> r;
    --l;
    --r;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    priority_queue<int, vector<int>, greater<int>> minq;
    for(int i=0;i<=r;i++){
        minq.push(a[i]);
    }
    int inc = 0;
    int ans1 = 0;
    while(inc<(r-l+1)){
        ans1+=minq.top();
        minq.pop();
        inc++;
    }
    while(minq.size()) minq.pop();
    for(int i=l;i<n;i++){
        minq.push(a[i]);
    }
    inc = 0;
    int ans2 = 0;
    while(inc<(r-l+1)){
        ans2+=minq.top();
        minq.pop();
        inc++;
    }
    cout << min(ans1,ans2) << "\n";
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
