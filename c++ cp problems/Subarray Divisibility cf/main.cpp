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
    vector<int> cnt(n,0);
    cnt[0] = 1;
    int sum = 0;
    int ans = 0;
    int addend = (1LL<<30)*n;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        sum = (sum+z+addend)%n;
        ans+=cnt[sum];
        cnt[sum]++;
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
