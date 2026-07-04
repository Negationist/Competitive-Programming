#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;

const int maxN = 2e5+5;
vi fact(maxN);

void compute(){
    fact[0] = fact[1] = 0;
    for(int i=2;i<maxN;i++){
        fact[i] = fact[i-1]+__builtin_ctz(i);
    }
}


void solve(){
    int n;
    cin >> n;
    vi a(n);
    int ans = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        int res = fact[n-1]-fact[n-1-i]-fact[i];
        if(!res){
            ans^=a[i];
        }
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    compute();
    solve();
    return 0;
}
