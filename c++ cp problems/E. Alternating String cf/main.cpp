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
    string s;
    cin >> n >> s;
    if(n%2==0){
        int even[26] = {};
        int odd[26] = {};
        int mx1 =0,mx2=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                even[s[i]-'a']++;
                mx1 = max(mx1, even[s[i]-'a']);
            } else{
                odd[s[i]-'a']++;
                mx2 = max(mx2, odd[s[i]-'a']);
            }
        }
        cout << n-mx1-mx2 << "\n";
    } else{
        //thanks author
        int res = n;
        vector<vector<int>> pref(2, vector<int> (26));
        vector<vector<int>> suff(2, vector<int> (26));
        for(int i=0;i<n;i++){
            suff[i%2][s[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            suff[i%2][s[i]-'a']--;
            int ans = n;
            for(int k=0;k<2;k++){
                int mx=0;
                for(int j=0;j<26;j++){
                    mx = max(mx, pref[k][j] + suff[1-k][j]);
                }
                ans-=mx;
            }
            res = min(res,ans);
            pref[i%2][s[i]-'a']++;
        }
        cout << res << "\n";
    }
}

signed main()
{
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
