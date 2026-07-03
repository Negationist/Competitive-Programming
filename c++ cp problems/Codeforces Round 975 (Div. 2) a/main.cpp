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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int mx=0;
        vector<int> index;
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            if(a > mx){
                index.clear();
                index.pb(i);
                mx = a;
            }
            else if(a==mx){
                index.pb(i);
            }
        }
        int ans = n/2;
        for(int x : index){
            if(x%2==0 && n%2==1){
                ans++;
                break;
            }
        }
        cout << ans+mx << "\n";
    }
    return 0;
}
