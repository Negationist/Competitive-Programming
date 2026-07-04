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
        int n;
        cin >> n;
        int x,y;
        cin >> x >> y;
        int put,blend;
        if(n%x==0){
            put = n/x;
        } else{
            put = n/x+1;
        }
        if(n%y==0){
            blend = n/y;
        } else{
            blend = n/y+1;
        }
        cout << max(put, blend) << "\n";
    }
    return 0;
}
