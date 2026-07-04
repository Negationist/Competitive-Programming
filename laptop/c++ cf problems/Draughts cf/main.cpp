#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

vector<string>board(10);
int ans;

void dfs(int i, int j, int sum){
    char restore = board[i][j];
    ans = max(ans,sum);
        if(i>1 && j<8){
        if(board[i-1][j+1] == 'B' && board[i-2][j+2]!='W' && board[i-2][j+2]!='B'){
            board[i][j] = '.';
            board[i-1][j+1] = '.';
            dfs(i-2,j+2,sum+1);
            board[i][j] = restore;
            board[i-1][j+1] = 'B';
        }
        }
        if(i<8 && j<8){
        if(board[i+1][j+1] == 'B' && board[i+2][j+2]!='W' && board[i+2][j+2]!='B'){
            board[i][j] = '.';
            board[i+1][j+1] = '.';
            dfs(i+2,j+2,sum+1);
            board[i][j] = restore;
            board[i+1][j+1] = 'B';
        }
        }
        if(i>1 && j>1){
        if(board[i-1][j-1] == 'B' && board[i-2][j-2]!='W' && board[i-2][j-2]!='B'){
            board[i][j] = '.';
            board[i-1][j-1] = '.';
            dfs(i-2,j-2,sum+1);
            board[i][j] = restore;
            board[i-1][j-1] = 'B';
        }
        }
        if(i<8 && j>1){
        if(board[i+1][j-1] == 'B' && board[i+2][j-2]!='W' && board[i+2][j-2]!='B'){
            board[i][j] = '.';
            board[i+1][j-1] = '.';
            dfs(i+2,j-2,sum+1);
            board[i][j] = restore;
            board[i+1][j-1] = 'B';
        }
        }
}

void solve(){
    ans = 0;
    for(int i=0;i<10;i++){
        cin >> board[i];
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(board[i][j] == 'W'){
                dfs(i,j,0);
            }
        }
    }
    cout << ans << endl;
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
