#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
using ld = long double;

int dict[4] = {1,0,3,2};

void solve(){
    int n,q;
    cin >> n >> q;
    vector<string> b(n);
    for(int i=0;i<n;i++) cin >> b[i];
    vector<vector<vector<int>>> ans(n, vector<vector<int>>(n, vector<int>(4, 0)));
    auto check = [&](int x, int y, int c){
        if(c==0){
            if(x-1<0) return 2;
            else if(b[x-1][y]=='.') return 1;
            else return 0;
        } else if(c==1){
            if(y+1>=n) return 2;
            else if(b[x][y+1]=='.') return 1;
            else return 0;
        } else if(c==2){
            if(x+1>=n) return 2;
            else if(b[x+1][y]=='.') return 1;
            else return 0;
        } else{
            if(y-1<0) return 2;
            else if(b[x][y-1]=='.') return 1;
            else return 0;
        }
    };
    auto getdir = [&](int x, int y, int k)->int{
        for(int shift : dict){
            int temp = (k+shift)%4;
            if(check(x,y,temp)) return temp;
        }
        return -1;
    };
    auto dfs = [&](auto self, int x, int y, int c){
        if(c==0){
            if(x+1>=n) return;
            else if(b[x+1][y]=='#') return;
            else{
                for(int i=0;i<4;i++){
                    int z = getdir(x+1,y,i);
                    if(z==c){
                        ans[x+1][y][i] = ans[x][y][c]+1;
                        self(self,x+1,y,i);
                    }
                }
            }
        } else if(c==1){
            if(y-1<0) return;
            else if(b[x][y-1]=='#') return;
            else{
                for(int i=0;i<4;i++){
                    int z = getdir(x,y-1,i);
                    if(z==c){
                        ans[x][y-1][i] = ans[x][y][c]+1;
                        self(self,x,y-1,i);
                    }
                }
            }
        } else if(c==2){
            if(x-1<0) return;
            else if(b[x-1][y]=='#') return;
            else{
                for(int i=0;i<4;i++){
                    int z = getdir(x-1,y,i);
                    if(z==c){
                        ans[x-1][y][i] = ans[x][y][c]+1;
                        self(self,x-1,y,i);
                    }
                }
            }
        } else{
            if(y+1>=n) return;
            else if(b[x][y+1]=='#') return;
            else{
                for(int i=0;i<4;i++){
                    int z = getdir(x,y+1,i);
                    if(z==c){
                        ans[x][y+1][i] = ans[x][y][c]+1;
                        self(self,x,y+1,i);
                    }
                }
            }
        }
    };
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(b[i][j]=='#') continue;
            for(int k=0;k<4;k++){
                for(int x : dict){
                    int temp = (k+x)%4;
                    if(check(i,j,temp)==1) break;
                    else if(check(i,j,temp)==2){
                        ans[i][j][k] = 1;
                        dfs(dfs,i,j,k);
                        break;
                    }
                }
            }
        }
    }
    while(q--){
        int r,c;
        cin >> r >> c;
        --r; --c;
        char e;
        cin >> e;
        if(e=='U'){
            cout << (ans[r][c][0]?ans[r][c][0]:-1) << "\n";
        }
        if(e=='R'){
            cout << (ans[r][c][1]?ans[r][c][1]:-1) << "\n";
        }
        if(e=='D'){
            cout << (ans[r][c][2]?ans[r][c][2]:-1) << "\n";
        }
        if(e=='L'){
            cout << (ans[r][c][3]?ans[r][c][3]:-1) << "\n";
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
