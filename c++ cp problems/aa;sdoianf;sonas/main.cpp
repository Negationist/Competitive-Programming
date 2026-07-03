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
        ll res = 0;
        for(int i = 0; i < n - 1; i++){
            ll delta = a[i + 1] * (i + 1) - ps[i + 1];
            if(delta == 0) continue;
            ll low = i + 1; ll high = n - 1;
            while(low < high){
                ll mid = (low + high + 1)/2;
                ll adelta = (ps[mid + 1] - ps[i + 1]) - (mid - i)*a[i + 1];
                if(adelta < delta){
                    low = mid;
                }
                else{
                    high = mid - 1;
                }
                //new delta is just
            }
            //cout << i << " " << low << " " << high << "\n";
            res = max(res, low-i);
        }
        cout << res << "\n";
    }
}
