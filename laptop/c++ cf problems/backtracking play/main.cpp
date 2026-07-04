#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int ans = 0;
vi diag1 (13,0);
vi diag2 (13,0);
vi col (13,0);
void solve(vector<vector<int>> arr, int y, int n){
    if(y==n){

    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(true){
        int n,m;
        cin >> n >> m;
        if(n==0 && m==0){
            return 0;
        }
        else
            vector<vector<int>> board(n, vector<int> (n,0));
            while(m--){
                int x,y;
                cin >> x >> y;
                board[x][y] = 1;
            }
            solve(board, n, 0);
        }
        ans 0;
    }
}
