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
    int n,m;
    cin >> n >> m;
    int a[n],b[m];
    int amx = -1,bmx=-1;
    for(int i=0;i<n;i++){
        cin >> a[i];
        amx = max(amx,a[i]);
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
        bmx = max(bmx,b[i]);
    }
    if(amx>bmx){
        cout << "-1\n";
        return;
    }
    int i=0,j=0;
    int ans = 0;
    while(i<n){
        int sum = a[i];
        j=0;
        while(sum+a[i+1]<=b[j+1]){
            sum+=a[i+1];
            i++;
            j++;
            if(j==m-1) break;
        }
        while(sum<=b[j] && j!=m-1){
            j++;
            if(j==m-1) break;
        }
        cout << "j is " << j << "\n";
        ans+=(m-j-1);
        i++;
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
