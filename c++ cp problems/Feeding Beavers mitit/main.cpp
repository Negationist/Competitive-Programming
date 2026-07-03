#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
using ld = long double;
void solve(){
    int n;
    string s;
    cin >> n >> s;
    int even = 2, odd = 1;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='E') ++cnt;
    }
    if(cnt&1){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int p = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='E'){
            if(p){
                cout << even << " " << even+2 << "\n";
                even+=4;
            } else{
                cout << odd << " " << odd+2 << "\n";
                odd+=4;
            }
            p = !p;
        } else{
            cout << even << " " << odd << "\n";
            even+=2;
            odd+=2;
        }
    }
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
