#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;

void solve(){
    int n,m;
    cin >> n >> m;
    vector<vi> grid(n+1,vi(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> grid[i][j];
        }
    }
    vector<vi> a(n+1,vi(m+1,0));
    vector<vi> b(n+1,vi(m+1,0));
    vector<vi> c(n+1,vi(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i+1<=n && j+1<=m){
                 a[i][j] = (grid[i][j]==grid[i][j+1] && grid[i+1][j]==grid[i+1][j+1] && grid[i][j]==grid[i+1][j]);

            }
            if(j+2<=m){
                b[i][j] = (grid[i][j]==grid[i][j+1] && grid[i][j]==grid[i][j+2]);
            }
            if(i+2<=n){
                c[i][j] = (grid[i][j]==grid[i+1][j] && grid[i][j]==grid[i+2][j]);
            }
        }
    }
    vector<vi> pref1(n+1,vi(m+1,0));
    vector<vi> pref2(n+1,vi(m+1,0));
    vector<vi> pref3(n+1,vi(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            pref1[i][j] = pref1[i-1][j]+pref1[i][j-1]-pref1[i-1][j-1]+a[i][j];
            pref2[i][j] = pref2[i-1][j]+pref2[i][j-1]-pref2[i-1][j-1]+b[i][j];
            pref3[i][j] = pref3[i-1][j]+pref3[i][j-1]-pref3[i-1][j-1]+c[i][j];
        }
    }
    /*for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout << pref1[i][j] << " \n"[j==m];
        }
    }
    cout << "_______________________________\n";
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout << pref2[i][j] << " \n"[j==m];
        }
    }
    cout << "_______________________________\n";
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout << pref3[i][j] << " \n"[j==m];
        }
    }
    cout << "_______________________________\n";*/
    int q;
    cin >> q;
    while(q--){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ++x1;
        ++x2;
        ++y1;
        ++y2;
        int num1=0,num2=0,num3=0;
        if(x2>1 && y2>1){
            num1 = pref1[x2-1][y2-1]-pref1[x1-1][y2-1]-pref1[x2-1][y1-1]+pref1[x1-1][y1-1];
        }
        if(y2-y1>=2){
            num2 = pref2[x2][y2-2]-pref2[x1-1][y2-2]-pref2[x2][y1-1]+pref2[x1-1][y1-1];
        }
        if(x2-x1>=2){
            num3 = pref3[x2-2][y2]-pref3[x1-1][y2]-pref3[x2-2][y1-1]+pref3[x1-1][y1-1];
        }
        int bad = max(num1,max(num2,num3));
        if(bad){
            cout << "NO\n";
        } else{
            cout << "YES\n";
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
