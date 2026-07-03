using namespace std;
#include <bits/stdc++.h>
#define ld double
#define ll long long
#define MAXN 100005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long double,long double>
#define vi vector<long double>
#define vii vector<pair<long double,long double>>
ll ps[MAXN][51], M;
pair<ll, ll> dp[50][64];
int main()
{
    M = 998244353;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q; cin >> n >> q;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= 50; j++){
            ps[i + 1][j] = ps[i][j];
        }
        ps[i + 1][a[i]]++;
    }
    for(int i = 0; i < q; i++){
        ll l, r; cin >> l >> r;
        if(ps[r][0] - ps[l - 1][0] > 0){
            cout << r - l << " " << ps[r][0] - ps[l - 1][0] << "\n";
            continue;
        }
        ll res = 0;
        for(int i = 1; i <= 50; i++){
            if(ps[r][i] - ps[l - 1][i] > 1){
                res += (ps[r][i] - ps[l - 1][i]) * (ps[r][i] - ps[l - 1][i] - 1)/2;
                res %= M;
                if(res < 0) res += M;
            }
        }
        if(res > 0){
            cout << r - l - 1 << " " << res << "\n";
            continue;
        }
        for(int i = 0; i <= r - l; i++){
            for(int j = 0; j < 64; j++){
                dp[i][j] = {60, -1};
            }
        }
        l--; r--;
        dp[0][a[l]] = {1, 1};
        for(int i = 1; i <= r - l; i++){
            for(int j = 0; j < 64; j++){
                if(j == a[l + i]){
                    dp[i][j] = {1, 1};
                    continue;
                }
                if(dp[i - 1][j ^ a[l + i]].ff + 1 < dp[i][j].ff){
                    dp[i][j] = {dp[i - 1][j ^ a[l + i]].ff + 1, 1};
                }
                else if(dp[i - 1][j ^ a[l + i]].ff + 1 == dp[i][j].ff){
                    dp[i][j] = {dp[i - 1][j ^ a[l + i]].ff + 1, (dp[i][j].ss + 1) % M};
                }
            }
        }
        if(dp[r - l][0].ff > r - l + 1){ //there is too many elements
            cout << "-1\n";
            continue;
        }
        cout << (r - l + 1) - dp[r - l][0].ff << " " << dp[r - l][0].ss << "\n";
        // minimum number of elements
        // consider dp[i][j]  number of ways for the first i element to xor to j in the minimum possible number of elements
        //
        //note r - l + 1 <= 50
    }
}
