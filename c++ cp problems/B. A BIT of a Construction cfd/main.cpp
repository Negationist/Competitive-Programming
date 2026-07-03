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
        int n,k;
        cin >> n >> k;
        if(n==1){
            cout << k << "\n";
            continue;
        }
        int msb = 0;
        for(int i=0;i<31;i++){
            if(1<<i & k){
                msb = i;
            }
        }
        cout << (1<<msb)-1 << " " << k - (1<<msb)+1 << " ";
        n-=2;
        while(n--){
            cout << 0 << " ";
        }
        cout << "\n";
    }
    return 0;
}
