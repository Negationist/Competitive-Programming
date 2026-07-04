#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

const int maxN = 40;

void solve(){
    int k;
    cin >> k;
    char out[maxN][maxN];
    for(int i=0;i<maxN;i++){
        for(int j=0;j<maxN;j++){
            out[i][j] = '.';
        }
    }
    int start = 0;
    auto num = [&](int x, int y)->int{
        int prod = x*y;
        int res = (prod*(prod-1))/2; //get rid of all skinny ones
        int horz = x*(y)*(y-1)/2;
        int vert = y*(x)*(x-1)/2;
        return res-horz-vert;
    };
    cout << num(2,2) << "!\n";
    /*while(k){
        int len = min(maxN,(ll)sqrt(k)+1);
        int y = -1;
        int best;
        for(int i=1;i<=maxN;i++){
            int res = num(len,i);
            if(res<=k){
                y = i;
                best = res;
            } else{
                break;
            }
        }
        k-=best;
            for(int i=0;i<y;i++){
            for(int j=0;j<len;j++){
                out[start+i][j] = '#';
            }
        }
        start+=(y+1);
    }
    cout << maxN << " " << maxN << "\n";
    for(int i=0;i<maxN;i++){
        for(int j=0;j<maxN;j++){
            cout << out[i][j] << " \n"[j==maxN-1];
        }
    }*/
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    solve();
    return 0;
}
