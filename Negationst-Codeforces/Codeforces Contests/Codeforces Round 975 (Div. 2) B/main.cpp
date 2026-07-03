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
    int n,q;
    cin >> n >> q;
    map<int,int> m;
    int a[n];
    for(int i=1;i<=n;i++){
        cin >> a[i-1];
        int res=0;
        res+=(i-1)*(n-i+1);
        res+=(n-i);
        m[res]++;
    }
    for(int i=1;i<n;i++){
        int num = a[i]-a[i-1]-1;
        int res = (i)*(n-i);
        m[res]+=num;
    }
    while(q--){
        int q;
        cin >> q;
        cout << m[q] << " ";
    }
    cout << "\n";
}

signed main()
{
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
