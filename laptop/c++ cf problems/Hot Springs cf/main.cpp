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
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    deque<int> dq;
    for(int i=0;i<n;i++){
        dq.push_back(a[i]);
    }
    int cur = 0;
    vi ans;
    while(dq.size()){
        if(cur%2==0){
            ans.pb(dq.back());
            dq.pop_back();
        } else{
            ans.pb(dq.front());
            dq.pop_front();
        }
        cur = 1-cur;
    }
    for(int i=n-1;i>=0;i--){
        cout << ans[i] << " ";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
