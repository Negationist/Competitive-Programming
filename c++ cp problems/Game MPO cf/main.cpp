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
using u128 = unsigned __int128;
using i128 = __int128;
void solve(){
    int n;
    cin >> n;
    vector<string> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<vi> visited(n,vi(n,0));
    priority_queue<tuple<int,int,int>> q;
    auto is_in = [&](int x, int y){
        return (x>=0 && x<n && y>=0 && y<n);
    };
    auto eval = [&](int x, int y)->void{
        int res = 0;
        if(a[x][y]=='o'){
            ++res;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(is_in(x+i,y+j)){
                        res+=(a[x+i][y+j] == 'O');
                    }
                }
            }
        } else if(a[x][y]=='m'){
            ++res;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(is_in(x+i,y+j)){
                        res+=(a[x+i][y+j] == 'P');
                    }
                }
            }
        } else if(a[x][y] == 'p'){
            ++res;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(is_in(x+i,y+j)){
                        res+=(a[x+i][y+j] == 'M');
                    }
                }
            }
        }
        if(res>1){
            q.push({res,x,y});
        }
    };
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            eval(i,j);
            if(a[i][j] == 'O'){
                ++ans;
                if(is_in(i+1,j-1)){
                    ans+=(a[i+1][j-1] =='O');
                }
                if(is_in(i+1,j)){
                    ans+=(a[i+1][j] =='O');
                }
                if(is_in(i+1,j+1)){
                    ans+=(a[i+1][j+1] =='O');
                }
                if(is_in(i,j-1)){
                    ans+=(a[i][j-1] =='O');
                }
            } else if(a[i][j] == 'P'){
                ++ans;
                if(is_in(i+1,j-1)){
                    ans+=(a[i+1][j-1] =='M');
                }
                if(is_in(i+1,j)){
                    ans+=(a[i+1][j] =='M');
                }
                if(is_in(i+1,j+1)){
                    ans+=(a[i+1][j+1] =='M');
                }
                if(is_in(i,j-1)){
                    ans+=(a[i][j-1] =='M');
                }
            } else if(a[i][j] == 'M'){
                ++ans;
                if(is_in(i+1,j-1)){
                    ans+=(a[i+1][j-1] =='P');
                }
                if(is_in(i+1,j)){
                    ans+=(a[i+1][j] =='P');
                }
                if(is_in(i+1,j+1)){
                    ans+=(a[i+1][j+1] =='P');
                }
                if(is_in(i,j-1)){
                    ans+=(a[i][j-1] =='P');
                }
            }
        }
    }
    cout << ans << " ";
    while(q.size()){
        auto [x,y,z] = q.top();
        q.pop();
        if(visited[y][z]==1) continue;
        ans+=x;
        visited[y][z]=1;
        a[y][z]-=32;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(!i && !j) continue;
                if(is_in(y+i,z+j)){
                    eval(y+i,z+j);
                }
            }
        }
    }
    cout << ans << "\n";
    for(string s : a){
        cout << s << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
