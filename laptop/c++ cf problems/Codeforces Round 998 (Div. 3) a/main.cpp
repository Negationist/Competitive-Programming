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
    vi a(4);
    for(int i=0;i<4;i++){
        cin >> a[i];
    }
    int num1 = a[0]+a[1];
    int num2 = a[2]-a[1];
    int num3 = a[3]-a[2];
    //cout << num1 << " " << num2 << " " << num3 << "\n";
    map<int,int> cnt;
    int ans = 0;
    ++cnt[num1];
    ans = max(ans,cnt[num1]);
    ++cnt[num2];
    ans = max(ans,cnt[num2]);
    ++cnt[num3];
    ans = max(ans,cnt[num3]);
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
