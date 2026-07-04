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
    int n,k;
    cin >> n >> k;
    k--;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int i1 = -1;
    for(int i=0;i<n;i++){
        if(a[i]>a[k]){
            i1 = i;
            break;
        }
    }
    if(i1 == -1){
        cout << n-1 << endl;
    } else if(k<i1){
        cout << i1-1 << endl;
    } else{
        int ans1 = i1-1;
        if(ans1<0) ans1 = 0;
        int ans2 = abs(i1-k);
        if(i1 == 0){
            ans2--;
        }
        cout << max(ans1,ans2) << endl;
    }
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
