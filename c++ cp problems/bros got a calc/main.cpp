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
    while(true){
        double ans = 0;
        for(int i=0;i<7;i++){
            double x;
            cin >> x;
            ans+=x;
        }
        cout << ans/7 << "\n";
    }
    return 0;
}
