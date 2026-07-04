#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

int A;
int B = ((1LL<<61) - 1);

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
    for(int l=n-1;l>1;l--){
        int a = l-1;
        int b = n-l;
        if(a<b) break;
        cout << "\n";
        int hash1 = h[a];
        int hash2 = (h[n-1] - h[b-1]*pow[n-b])%B;
        if(hash1 ==  hash2){
            cout << "YES\n";
            cout << s.substr(1,l);
            return;
        }
    }
    cout << "NO\n";
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
