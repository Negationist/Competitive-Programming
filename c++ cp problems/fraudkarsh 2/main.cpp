using namespace std;
#include <bits/stdc++.h>
#define ll int
#define MAXN 405
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        vector<ll> ps(n + 1);
        for(int i = 1; i <= n; i++){
            ps[i] = ps[i - 1] + a[i - 1];
        }
        ll res = 0; ll delta = a[1] - a[0];
        ll p2 = 0; ll adelta = 0; ll prev = 0;
        for(int i = 0; i < n - 1; i++){
            ll delta = a[i + 1] * (i + 1) - ps[i + 1];
            //cout << delta << "\n";
            if(prev > 0){
                adelta -= prev*(a[i + 1] - a[i]); prev--;
            }
            else{
                p2 = i + 1;
                prev = 0;
            }
            while(p2 < n && adelta + a[p2] - a[i + 1] < delta){
                adelta += a[p2] - a[i + 1];
                prev++; p2++;
                //cout << adelta << " " << delta << "\n";
            }
            res = max(res, prev);
            //cout << i << " " << prev << "\n";
            if(p2 == n) break;
        }
        cout << res << "\n";
    }
}
