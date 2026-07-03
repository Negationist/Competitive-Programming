using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 755
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll dp[2][8][101][101];
int main()
{
    freopen("cbarn2.in","r",stdin);
    freopen("cbarn2.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k; cin >> n >> k;
    vector<ll> a(n + 1);
    vector<ll> ps(n + 1);
    vector<ll> ps2(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ps[i] = ps[i - 1] + a[i];
        ps2[i] = ps2[i - 1] + i * a[i];
    }
    dp[0][1][1][1] = 0;
    ll res = 1e18;
    for(ll i1 = 2; i1 <= n; i1++){
        for(ll j = 1; j <= min(i1, k); j++){
            for(ll s = 1; s <= i1 - j + 1; s++){
                ll track = 1e18;
                for(ll e = s + j - 1; e <= i1; e++){
                    if(j == i1){
                        dp[1][j][s][e] = 0;
                    }
                    else if(j == 1 && s != e){
                        dp[1][j][s][e] = 1e18;
                    }
                    else if(e != i1){
                        dp[1][j][s][e] = dp[0][j][s][e] + a[i1] + ps[s - 1]; //calculated before
                        track = min(dp[0][j - 1][s][e] - abs(i1 - 1 - e) * ps[s - 1] - ps2[s - 1], track);
                    }
                    else{
                        if(j == 1){
                            dp[1][j][s][i1] = ps2[s - 1];
                        }
                        else{
                            dp[1][j][s][i1] = ps2[s - 1] + track;
                        }

                    }
                    //cerr << i1 << " " << j << " " << s << " " << e << " " << dp[1][j][s][e] << "\n";
                }
            }
        }
        //cerr << "chicken\n";
        for(ll j = 1; j <= min(i1, k); j++){
            for(ll s = 1; s <= i1 - j + 1; s++){
                for(ll e = s + j - 1; e <= i1; e++){
                    dp[0][j][s][e] = dp[1][j][s][e];
                    dp[1][j][s][e] = 0;
                    if(i1 == n) res = min(res, dp[0][j][s][e]);
                    //cerr << i1 << " " << j << " " << s << " " << e << " " << dp[1][j][s][e] << "\n";
                }
            }
        }

    }
    cout << res << "\n";

}
