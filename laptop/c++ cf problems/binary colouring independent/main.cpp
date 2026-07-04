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
    int cnt = 0;
    vi nums;
    for(int i=0;i<32;i++){
        cnt++;
        int current = n & 3;
        if(current == 3){
            nums.pb(-1);
            n+=2;
        } else{
            nums.pb(n&1);
        }
        n >>= 1;
    if(n==0) break;
    }
    cout << cnt << "\n";
    for(int x : nums){
        cout << x << " ";
    }
    cout << "\n";
}

signed main()
{
    //ios::sync_with_stdio(0);
    // cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
