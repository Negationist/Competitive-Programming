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
    int n,m,q;
    cin >> n >> m >> q;
    vector<vi> a(n+2, vi(m));
    for(int i=0;i<m;i++) a[0][i] = -1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<m;i++) a[n+1][i] = 1LL<<60;
    for(int i=0;i<m;i++){
        for(int j=2;j<=n;j++){
            a[j][i] = (a[j-1][i] | a[j][i]);
        }
    }
    while(q--){
        int M;
        cin >> M;
        int mn = 1, mx = n;
        while(M--){
            int x,y; char o;
            cin >> x >> o >> y;
            x--;
            if(o=='>'){
                int l = 1, r = n+1;
                while(l<=r){
                    int mid = l+(r-l)/2;
                    if(a[mid][x]>y){
                        r = mid-1;
                    } else{
                        l = mid+1;
                    }
                }
                mn = max(mn, l);
            } else{
                int l = 1, r = n+1;
                while(l<=r){
                    int mid = l+(r-l)/2;
                    if(a[mid][x]<y){
                        l = mid+1;
                    } else{
                        r = mid-1;
                    }
                }
                mx = min(mx, r);
            }
        }
        if(mn<=mx && mn<=n){
            cout << mn << "\n";
        } else cout << -1 << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
