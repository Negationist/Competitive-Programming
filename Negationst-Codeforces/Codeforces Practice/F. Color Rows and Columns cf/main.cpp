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
    priority_queue<pair<int,tuple<int,int,int>>> q;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        q.push({min(a,b),{a,b,0}});
    }
    int sum = 0;
    while(q.size() && sum<k){

    }
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
