#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

int n;
double dp[301][301][301];
double ans(int x, int y, int z){
    if(!x && !y && !z) return 0.0;
    if(dp[x][y][z]) return dp[x][y][z];
    double chance1 = double(x)/double(n);
    double chance2 = double(y)/double(n);
    double chance3 = double(z)/double(n);
    double chance4 = 1-chance1-chance2-chance3;
    double sum = 1.0;
    if(chance1){
        sum+=chance1*ans(x-1,y,z);
    }
    if(chance2){
        sum+=chance2*ans(x+1,y-1,z);
    }
    if(chance3){
        sum+=chance3*ans(x,y+1,z-1);
    }
    dp[x][y][z] = sum/(1-chance4);
    return dp[x][y][z];
}

void solve(){
    vi num(4);
    cin >> n;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        ++num[z];
    }
    cout << fixed << setprecision(12) << ans(num[1],num[2],num[3]) << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}