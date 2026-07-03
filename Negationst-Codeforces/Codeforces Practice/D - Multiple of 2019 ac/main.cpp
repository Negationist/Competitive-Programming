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
    int base = 1;
    vi a(2019,0);
    a[0] = 1;
    int sum = 0;
    int ans = 0;
    for(int i=n-1;i>=0;i--){
        if(i!=n-1){
            base = (base*10)%2019;
        }
        int res = (base*(int)(s[i]-'0'))%2019;
        sum = (sum+res)%2019;
        ans+=a[sum];
        a[sum]++;
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
