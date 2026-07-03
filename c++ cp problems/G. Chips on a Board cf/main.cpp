#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
using ld = long double;
const int maxN = 2e3+5;
void solve(){
    int n,m;
    cin >> n >> m;
    int cnt[maxN] = {};
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        ++cnt[z];
    }
    cnt[0] = 0;
    for(int i=1;i<maxN;i++){
        cnt[i]+=cnt[i-1];
    }
    int x[maxN][18];
    for(int i=1;i<maxN;i++){
        x[i][0] = 0;
    }
    for(int j=1;j<18;j++){
        for(int i=1;i<maxN;i++){
           if(i+(1LL<<j)-1>maxN) continue;
           x[i][j] = x[i][j-1]^x[i+(1LL<<(j-1))][j-1];
           int num = cnt[i+(1LL<<j)-1]-cnt[i+(1LL<<(j-1))-1];
           if(num&1){
                x[i][j]^=(1LL<<(j-1));
           }
        }
    }
    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        int g = 0;
        for(int i=17;i>=0;i--){
            if(l+(1LL<<i)<=r){
                g^=x[l][i];
                int num = cnt[r]-cnt[l+(1LL<<i)-1];
                if(num&1){
                    g^=(1LL<<i);
                }
                l+=(1LL<<i);
            }
        }
        cout << "AB"[g==0];
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
