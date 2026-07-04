#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int ans = 0;
        string s;
        cin >> s;
        bool endgame = false;
        for(int i=0;i<s.size();i++){
            if(!endgame && s[i]=='0' && s[i+1]=='1'){
                endgame = true;
                continue;
            }
            if(s[i]=='1' && s[i+1]=='0'){
                ans++;
            }
            if(s[i]=='0' &&s[i+1]=='1'){
                ans++;
            }
        }
        cout << ans+1 << endl;
    }
    return 0;
}
