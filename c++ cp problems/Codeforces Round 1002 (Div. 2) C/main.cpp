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
    vector<vi> a(n,vi(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=n-1;j>=0;j--){
            if(a[i][j]==1) ++cnt;
            else break;
        }
        pq.push(cnt);
    }
    int cur = 0;
    while(pq.size()){
        if(pq.top()>=cur){
            ++cur;
        }
        pq.pop();
    }
    cout << cur << "\n";
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
