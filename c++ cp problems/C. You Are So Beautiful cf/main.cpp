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
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int num[n+1];
    num[n] = 0;
    set<int> s;
    for(int i=n-1;i>=0;i--){
        if(s.find(a[i])==s.end()){
            num[i] = num[i+1]+1;
            s.insert(a[i]);
        } else{
            num[i] = num[i+1];
        }
    }
    s.clear();
    int ans = 0;
    for(int i=0;i<n;i++){
        if(s.find(a[i])==s.end()){
            ans+=num[i];
            s.insert(a[i]);
        }
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
