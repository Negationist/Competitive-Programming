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
    int n, num = 0;
    cin >> n;
    vi p(n), ans(n+1,0);
    for(int i=0;i<n;i++){
        p[i] = i+1;
    }
    do{
        int mn = 1e10, cnt, index;
        for(int i=0;i<n;i++){
            int res = (i+1)*(p[i]);
            if(res<mn){
                mn = res;
                cnt = 1;
                index = i+1;
            } else if(res==mn){
                ++cnt;
            }
        }
        if(cnt==1){
            ans[index]++;
        } else{
            ++num;
        }
    } while(next_permutation(p.begin(), p.end()));
    for(int i=1;i<=n;i++){
        cout << "ans for " << i << " is " << ans[i] << "\n";
    }
    cout << "number of useless is " << num << "\n";
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    while(true){
        solve();
    }
    return 0;
}
