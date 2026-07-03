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

void solve(){
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> vis(n+1,vi(n+1,0));
    vector<vector<ll>> res(n+1,vi(n+1));
    bool win = true;
    for(int i=0;i<m;i++){
        ll l,r,s;
        cin >> l >> r >> s;
        if(!vis[l][r]){
            vis[l][r] = 1;
            res[l][r] = s;
        } else{
            if(res[l][r]!=s){
                win = false;
            }
        }
    }
    if(!win){
        cout << "NO\n";
        return;
    }
    for(int j=n;j>=1;j--){
        int ref = -1;
        for(int i=j;i>=1;i--){
            if(vis[i][j]){
                if(ref==-1){
                    ref = i;
                } else{
                    int new_s = res[i][j] - res[ref][j];
                    if(!vis[i][ref-1]){
                        vis[i][ref-1] = 1;
                        res[i][ref-1] = new_s;
                    } else{
                        if(res[i][ref-1]!=new_s){
                            win = false;
                        }
                    }
                    vis[i][j] = 0;
                }
            }  
        }
    }
    if(!win){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<ll> ans(n+1),pref(n+1);
    pref[0] = 0;
    for(int j=1;j<=n;j++){
        bool seen = false;
        for(int i=1;i<=j;i++){
            if(vis[i][j]){
                //cout << "considering " << i << " " << j << "\n";
                ll need = res[i][j] - (pref[j-1]-pref[i-1]);
                ans[j] = need;
                pref[j] = pref[j-1]+ans[j];
                seen = true;
            }
        }
        if(!seen){
            ans[j] = 0;
            pref[j] = pref[j-1];
        }
        cout << ans[j] << " ";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}