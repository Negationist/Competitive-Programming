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
    vii jobs(n);
    for(int i=0;i<n;i++){
        int s,t;
        cin >> s >> t;
        jobs[i] = {s,s+t-1};
    }
    sort(jobs.begin(),jobs.end());
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i=0;i<n;i++){

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
