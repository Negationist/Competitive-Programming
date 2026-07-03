#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

vector<vi> a(256, vi(256));

void make(){
    for(int i=0;i<256;i++){
        for(int j=0;j<256;j++){
            int num = 4*((i/2)+(j/2)*256);
            if(i%2==0 && j%2==0){
                a[i][j] = num;
            } else if(i%2==1 && j%2==0){
                a[i][j] = num+1;
            }
            else if(i%2==0 && j%2==1){
                a[i][j] = num+2;
            } else{
                a[i][j] = num+3;
            }
        }
    }
}

void solve(){
    int n,m;
    cin >> n >> m;
    cout << n*m << "\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << a[i][j] << " \n"[j==m-1];
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    make();
    while(t--){
        solve();
    }
    return 0;
}
