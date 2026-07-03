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
    int ans = 0;
    int cur = 0;
    int num = 0;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        if(z==1){
            cur++;
            num++;
            ans = max(ans,cur);
        } else{
            if(num==0){
                cur = 0;
                continue;
            }
            if(num%2==0){
                cur = 2+(num-2)/2;
            } else{
                cur = 1+(num-1)/2;
            }
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
