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
    vector<tuple<int,int,int>> p(n);
    priority_queue<tuple<int,int,int>> pq;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin >> a >> b >> c;
        p[i] = {a,b,c};
    }
    for(int i=1;i<n;i++){
        int dis = p[i].first - p[i-1].first;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
