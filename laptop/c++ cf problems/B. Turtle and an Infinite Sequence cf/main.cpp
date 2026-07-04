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
        int m;
        cin >> n >> m;
        int a[31] = {0};
        int b[31];
        for(int i=0;i<31;i++){
            if((1<<i) & n){
                a[i] = 1;
            }
        }
        for(int i=0;i<31;i++){
            if (a[i]==1){
                b[i]=0;
            } else{
                int num = n%(1 << i);

                if(n < (int)(1<<i)){
                    b[i] = (int)(1<<i) - num;
                }
                 else {
                    b[i] = min((int)(1 << i) - num,num+1);
                 }
            }
        }
        int ans = 0;
        for(int i=0;i<31;i++){
            if(b[i]<=m){
                ans+=(1 << i);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
