
#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void solve(){
    int n,k,d,ans=-1;
    cin >> n >> k >> d;
    int a[n], b[k];
    int num = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i]==i+1) num++;
    }
    for(int i=0;i<k;i++){
        cin >> b[i];
    }
    ans = num+(d-1)/2;
    for(int i=1;i<min(d,(int)1e5);i++){
        for(int j=0;j<b[(i-1)%k];j++){
            if(a[j] == j+1) num--;
            else if(a[j]==j) num++;
            a[j]++;
        }
        int res = num + (d-i-1)/2;
        ans = max(ans, res);
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
