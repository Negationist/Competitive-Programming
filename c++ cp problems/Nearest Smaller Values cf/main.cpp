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
    vi ans(n,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    stack<pii> s;
    for(int i=n-1;i>=0;i--){
        while(s.size() && s.top().ff>a[i]){
            ans[s.top().ss] = i+1;
            s.pop();
        }
        s.push({a[i],i});
    }
    ans[0] = 0;
    for(int i=0;i<n;i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
