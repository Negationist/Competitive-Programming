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

void solve(){
    char z;
    cin >> z;
    string s;
    cin >> s;
    if(z=='D'){
        char last;
        for(char x : s){
            int z = (int)(x);
            if(z>=49 && z<=57){
                z-='0';
                for(int i=0;i<z;i++){
                    cout << last;
                }
            } else{
                last = x;
            }
        }
    } else{
        string out;
        int cnt = 1;
        for(int i=1;i<s.size();i++){
            if(s[i]!=s[i-1]){
                out.pb(s[i-1]);
                out.pb((char)(cnt+'0'));
                cnt = 1;
            } else{
                ++cnt;
            }
        }
        out.pb(s.back());
        out.pb((char)(cnt+'0'));
        cout << out;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
