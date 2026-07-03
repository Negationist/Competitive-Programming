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
    int n,d,k;
    cin >> n >> d >> k;
    int o[n] = {}, c[n] = {};
    for(int i=0;i<k;i++){
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        o[l]++;
        c[r]++;
    }
    for(int i=1;i<n;i++){
        o[i]+=o[i-1];
        c[i]+=c[i-1];
    }
    int mn = LLONG_MAX,mx=-1,bro=0,mom=0;
    for(int i=d-1;i<n;i++){
        int sum;
        if(i-d<0) sum = o[i];
        else sum = o[i] - c[i-d];
        if(sum>mx){
            bro = i-d+1;
            mx = sum;
        }
        if(sum<mn){
            mom = i-d+1;
            mn = sum;
        }
    }
    cout << bro+1 << " " << mom+1 << "\n";
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
