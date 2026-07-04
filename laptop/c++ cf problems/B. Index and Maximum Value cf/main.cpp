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
        int n,m;
        cin >> n >> m;
        int mx = 0;
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            mx = max(mx,a);
        }
        for(int i=0;i<m;i++){
            char sign;
            int l,r;
            cin >> sign >> l >> r;
            if(sign == '-'){
                if(mx >= l && mx <= r){
                    mx--;
                }
            }
            else{
                if(mx >= l && mx <= r){
                    mx++;
                }
            }
            cout << mx << " ";
        }
         cout << "\n";
    }
    return 0;
}
