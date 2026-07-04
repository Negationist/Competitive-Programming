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
        int n,ans=2;
        cin >> n;
        int max5 = n/5;
        while(max5>=0){
            int copyN = n;
            copyN -=(max5*5);
            copyN%=3;
            ans = min(ans,copyN);
            max5--;
        }
        cout << ans << endl;
    }
    return 0;
}
