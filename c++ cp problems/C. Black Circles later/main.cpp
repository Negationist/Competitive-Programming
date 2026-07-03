#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
//how far we've come
using namespace std;

void solve(){
    int n;
    cin >> n;
    vii e(n);
    for(int i=0;i<n;i++){
        cin >> e[i].ff >> e[i].ss;
    }
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int dis = (a-c)*(a-c)+(b-d)*(b-d);
    for(int i=0;i<n;i++){
        int res = (e[i].ff-c)*(e[i].ff-c)+(e[i].ss-d)*(e[i].ss-d);
        if(res<=dis){
            cout << "no\n";
            return;
        }
    }
    cout << "yes\n";
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
