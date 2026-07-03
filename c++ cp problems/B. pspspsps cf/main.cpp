#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void solve(){
    int n;
    cin >> n;
    bool P = false;
    bool lose = false;
    string s;
    cin >> s;
    bool soff = false;
    bool poff = false;
    for(int i=0;i<n;i++){
        if(s[i]=='s'){
            if(i && i<n-1){
                soff = true;
            }
            if(P){
                lose = true;
            }
        } else if(s[i]=='p'){
            P = true;
            if(i && i<n-1){
                poff = true;
            }
        }
    }
    if(lose || (poff && soff)){
        cout << "NO\n";
    } else{
        cout << "YES\n";
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
