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
    int n,q;
    cin >> n >> q;
    vi a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<vi> num(n, vi(n));
    for(int i=0;i<n-1;i++){
        m.clear();
        for(int j=i+1;j<n;j++){
            int res = -a[i]-a[j];
            num[i][j] = m[res];
            m[a[j]]++;
        }
    }
    vector<vi> ans(n,vi(n));
    for(int i=0;i<n;i++){
        ans[i][i] = 0;
        num[i][i] = 0;
        if(i!=n-1){
            ans[i][i+1] = 0;
            num[i][i+1] = 0;
        }
    }
    for(int j=2;j<n;j++){
        for(int i=0;i+j<n;i++){
            int k = i+j;
            ans[i][k] = num[i][k] + ans[i][k-1] + ans[i+1][k] - ans[i+1][k-1];
        }
    }
    while(q--){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        cout << ans[a][b] << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("threesum.in","r",stdin);
    freopen("threesum.out", "w", stdout);
    solve();
    return 0;
}
