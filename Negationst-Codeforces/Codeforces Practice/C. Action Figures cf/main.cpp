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
    int ans = 0, cnt=0;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='1' && cnt<i){
            cnt++;
            continue;
        }
        cnt--;
        cnt = max(cnt,0LL);
        ans+=(i+1);
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
