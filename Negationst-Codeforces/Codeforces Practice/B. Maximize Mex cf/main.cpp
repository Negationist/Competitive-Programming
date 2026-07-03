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
    int n,x;
    cin >> n >> x;
    map<int,int> m;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        m[a]++;
    }
    for(int i=0;i<LLONG_MAX;i++){
        if(m[i]==0){
            cout << i << "\n";
            return;
        } else{
            m[i+x]+=(m[i]-1);
        }
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
