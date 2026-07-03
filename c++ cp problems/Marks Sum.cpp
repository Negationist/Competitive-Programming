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
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

void solve(){
    int type; cin >> type;
    int t;
    cin >> t;
    while(t--){
        if(type==1){
            string s;
            cin >> s;
            int last = -1, sum = 0, rem = 0, x = 0;
            for(int i=0;i<s.size();i++){
                sum+=(s[i]=='1'?1:2);
                if((sum%2000)<=1){
                    last = i;
                    rem = (sum%2000);
                    x = sum/2000;
                }
            }
            cout << (int)(s.size())-(last+1) << " " << x+1000*rem << "\n";
        } else{
            int info; cin >> info;
            string s;
            cin >> s;
            int sum = (info>=1000?(info-1000)*2000+1:info*2000);
            for(int i=0;i<s.size();i++){
                sum+=(s[i]=='1'?1:2);
            }
            cout << sum << "\n";
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}