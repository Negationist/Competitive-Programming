#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endl
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;


void solve(){
    int n,k;
    cin >> n >> k;
    set<pii> events;
    vi freq(5*n, 0);
    for(int i=0;i<n;i++){
        int z; cin >> z;
        freq[z]++;
    }
    for(int i=0;i<5*n;i++){
        if(freq[i] != 1){
            events.insert({i, freq[i]-1});
        }
    }
    int ans = 0;
    for(int i=2*n;i>=0;i--){
        if(freq[i] > k){
            int rem = freq[i] - k, place = i;
            events.erase({i, freq[i]-1});
            while(rem){
                pii next = *events.lower_bound({i+1, -1000});
                rem+=next.ss;
                events.erase(next);
                place = next.ff;
            }
            ans = max(ans, place - i);
            events.insert({place, k-1});
        }
    }
    cout << ans << "\n";
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