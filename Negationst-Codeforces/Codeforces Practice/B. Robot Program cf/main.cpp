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
    int n,x,k;
    cin >> n >> x >> k;
    string s;
    cin >> s;
    int inc = 0;
    int _x = x;
    for(int i=0;i<n;i++){
        inc++;
        if(s[i]=='L'){
            x--;
        } else{
            x++;
        }
        if(!x) break;
    }
    if(x!=0){
        cout << "0\n";
    } else{
        k-=inc;
        int ans = 1;
        if(k<0){
            cout << "0\n";
            return;
        }
        x = _x;
        inc = 0;
        int pos = 0;
        for(int i=0;i<n;i++){
            inc++;
            if(s[i]=='L'){
                pos--;
            } else{
                pos++;
            }
            if(!pos){
                break;
            }
        }
        if(!pos){
            ans+=(k/inc);
        }
        cout << ans << "\n";
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
