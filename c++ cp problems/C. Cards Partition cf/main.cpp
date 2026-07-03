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
        int n,k,ans=1;
        cin >> n >> k;
        int mx = 0;
        int Osum = 0;
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            mx = max(mx,a);
            Osum+=a;
        }
        for(int i=1;i<=n;i++){
            int copyK = k;
            int sum = Osum;
            int add = (i - sum%i)%i;
            if(add<=copyK){
                sum+=add;
                copyK-=add;
            }
            int factor = copyK/i;
            sum+=(factor*i);
            if(i <= sum/mx && sum%i==0){
                ans = max(ans,i);
            }
        }
        cout <<  ans << "\n";
    }
    return 0;
}
