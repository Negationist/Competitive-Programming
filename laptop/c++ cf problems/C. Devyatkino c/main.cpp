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
    int n;
    cin >> n;
    int ans = 7;
    for(int i=0;i<=6;i++){
        int temp = n-i;
        bool flag = false;
        while(temp>0){
            int cur = temp%10;
            if(cur<=7 && i+cur>=7){
                ans = i;
                flag = true;
            }
            temp/=10;
        }
        if(flag){
            break;
        }
    }
    int inc = 0;
    while(n%10 != 7){
        n+=9;
        ++inc;
    }
    cout << min(ans,inc) << "\n";
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
