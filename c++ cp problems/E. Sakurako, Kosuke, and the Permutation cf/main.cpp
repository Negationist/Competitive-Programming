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
    vi a(n+1);
    set<int> s;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(i==a[i]) continue;
        if(a[a[i]]==i) continue;
        s.insert(i);
    }
    int cur = *(s.begin());
    s.erase(cur);
    int sum = 1;
    while(s.size()){
        cur = a[cur];
        if(s.find(cur)==s.end()){
            ans+=(sum-1)/2;
            sum=0;
            cur = *(s.begin());
        } else{
            sum++;
            s.erase(cur);
        }
    }
    cout << ans+(sum-1)/2 << "\n";
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
