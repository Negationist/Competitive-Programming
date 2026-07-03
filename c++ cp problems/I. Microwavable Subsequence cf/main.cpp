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
    int n,m;
    cin >> n >> m;
    map<tuple<int,int,int>,int>> tot;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(i>0 && a[i]){
            int first
            tuple<int,int,int> cur = {a[i-1],a[i],cur};
        }
    }

}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
