#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

int A;
int B = 1e9+7;

using namespace std;

void computehash(string &s, vi &h){
    int n = s.size();
    h[0] = s[0];
    for(int i=1;i<n;i++){
        h[i] = (h[i-1]*A + s[i])%B;
   }
}

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    vi h(n);
    computehash(s, h);
    vi pow(n);
    pow[0] = 1;
    for(int i=1;i<n;i++){
        pow[i] = (pow[i-1]*A)%B;
    }
    int res1 = (h[5]-((h[2]*pow[5-2])%B)+B)%B;
    int res2 = h[2];
    cout << res1 << "\n" << res2 << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(1,B-1);
    A = dist(rng);
    solve();
    return 0;
}
