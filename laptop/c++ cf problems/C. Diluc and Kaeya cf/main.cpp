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
const int maxN = 5e5;
int sieve[maxN] = {};

void compute(){
    sieve[1] = 1;
    for(int i=2;i<maxN;i++) sieve[i] = i;
    for(int i=2;i<maxN;i++){
        if(sieve[i]==i){
            for(int j=i;j<maxN;j+=i){
                sieve[j] = i;
            }
        }
    }
}


void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi pref(n+1);
    pref[0] = 0;
    for(int i=1;i<=n;i++){
        pref[i]=pref[i-1];
        if(s[i-1]=='K'){
            pref[i]++;
        } else pref[i]--;
    }
    map<pii,int> m;
    for(int i=1;i<=n;i++){
        m[{i,i}] = pref[i];
        int mx = 1;
        vector<int> factors;
        int cur = i;
        while(cur!=1){
            factors.pb(sieve[cur]);
            cur/=sieve[cur];
        }
        for(int x : factors){
            int diff = i/x;
            int first = pref[i] - pref[i-diff];
            if(first = m[{i-diff,x}]){
                mx = max(mx,x);
                m[{i,x}] = first;
            } else{
                m[{i,x}] = -1;
            }
        }
        cout << mx << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    compute();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
