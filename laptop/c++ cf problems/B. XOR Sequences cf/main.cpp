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
        int x,y;
        cin >> x >> y;
        int res = x ^ y;
        for(int i=0;i<31;i++){
            if (1<<i & res){
                cout << (1<<i) << endl;
                break;
            }
        }
    }
    return 0;
}
