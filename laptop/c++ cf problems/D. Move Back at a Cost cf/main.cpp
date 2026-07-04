#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    if(n==1){
        cout << a[0] << "\n";
        return;
    }
    vi suff(n);
    suff[n-1] = a[n-1];
    for(int i=n-2;i>=0;i--){
        suff[i] = min(a[i],suff[i+1]);
    }
    vi ans;
    vi rest;
    int next = suff[0];
    int mn = LLONG_MAX;
    for(int i=0;i<n;i++){
        if(a[i]==next && next<=mn){
            ans.pb(a[i]);
            if(i==n-1) break;
            next = suff[i+1];
        } else{
            rest.pb(a[i]+1);
            mn = min(mn,a[i]+1);
        }
    }
    sort(rest.begin(),rest.end());
    for(int x : ans){
        cout << x << " ";
    }
    for(int x : rest){
        cout << x << " ";
    }
    cout << "\n";
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
