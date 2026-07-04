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
        if(n==2){
            int x,y;
            cin >> x >> y;
            cout << y-x << endl;
            continue;
        }
        int sum = 0;
        for(int i=0;i<n-2;i++){
            int a;
            cin >> a;
            sum+=a;
        }
        int l;
        cin >> l;
        l-=sum;
        int ans;
        cin >> ans;
        ans-=l;
        cout << ans << endl;
    }
    return 0;
}
