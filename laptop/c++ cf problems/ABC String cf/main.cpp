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
    string s;
    cin >> s;
    int n = s.size();
    vi pref(3,0);
    int ans = 1;
    for(int i=0;i<n;i++){
        int cur = s[i]-'A
        ';
        pref[cur]++;
        int x  = abs(pref[0]-pref[1]);
        int y  = abs(pref[1]-pref[2]);
        int z  = abs(pref[2]-pref[0]);
        ans = max(ans,x);
        ans = max(ans,y);
        ans = max(ans,z);
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
