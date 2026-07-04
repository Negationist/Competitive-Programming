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
    int y,k,n,x;
    cin >> y >> k >> n;
    if(y%k==0){
        x = k;
    } else{
        x = k - y%k;
    }
    if(x+y > n){
        cout << -1;
        return 0;
    }
    while(true){
        if(x+y <= n){
            cout << x << " ";
            x+=k;
        } else{
            break;
        }
    }
    return 0;
}
