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
    string s;
    cin >> s;
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=(s[i]=='.' ? 1 : 0);
        if(i<2) continue;
        if(s[i]=='.' && s[i-1]=='.' && s[i-2]=='.'){
            cout << 2 << "\n";
            return;
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
