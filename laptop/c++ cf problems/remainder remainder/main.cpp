#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int modInv(int b, int m){

}

void solve(){
    int a,b,c,a1,a2,a3,g;
    cin >> a >> b >> c >> d >> e >> f >> g;
    int mx1,mx2,mx3;
    int i = 1;
    while(true){
        int res = (a-2*i)*(b-2*i)*i;
        if(res<=0) break;
        if(res>mx1){
            mx3 = mx2;
            mx2 = mx1;
            mx1 = res;
        } else if(res>mx2){
            mx3 = mx2;
            mx2 = res;
        } else if (res>mx3){
            mx3 = res;
        }
        i++;
    }
    int M = mx1*mx2*mx3;
    int res1 = a1*(M/mx1)*modInv(M/mx1,mx1);
    int res2 = a2*(M/mx2)*modInv(M/mx2,mx2);
    int res3 = a3*(M/mx3)*modInv(M/mx1,mx3);
    int ans = res1+res2+res3;

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
