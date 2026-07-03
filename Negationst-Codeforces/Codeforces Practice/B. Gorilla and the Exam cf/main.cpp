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
    int n,k;
    cin >> n >> k;
    map<int,int> cnt;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        cnt[z]++;
    }
    priority_queue<int, vector<int>, greater<int>> mnq;
    for(auto x : cnt){
        mnq.push(x.ss);
    }
    while(mnq.size() && k>=mnq.top()){
        k-=mnq.top();
        mnq.pop();
    }
    int x = mnq.size();
    cout << max(x,1LL) << "\n";
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
