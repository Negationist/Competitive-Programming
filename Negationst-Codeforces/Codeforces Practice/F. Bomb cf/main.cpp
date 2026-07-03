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
    int tot, sum;
    int n,k;
    cin >> n >> k;
    vi a(n),b(n);
    vi c(n);
    auto check = [&](int x){
        tot = 0;
        sum = 0;
        for(int i=0;i<n;i++){
            c[i] = a[i];
            int cur = ((a[i]-x)+b[i]-1)/b[i];
            if(cur<=0) continue;
            tot+=cur;
            sum+=((a[i]+a[i]-(b[i]*(cur-1)))*cur)/2;
            c[i] = a[i]-b[i]*cur;
        }
    };
    int mx =  -1;
    for(int i=0;i<n;i++) {cin>> a[i]; mx = max(mx,a[i]);}
    for(int i=0;i<n;i++) cin>> b[i];
    int l = 0, r=mx;
    while(l<=r){
        int mid = l+(r-l)/2;
        check(mid);
        if(tot<=k){
            r = mid-1;
        } else{
            l = mid+1;
        }
    }
    check(l);
    int ans = sum;
    k-=tot;
    priority_queue<pii> q;
    for(int i=0;i<n;i++){
        q.push({c[i],b[i]});
    }
    while(k && q.top().ff>0){
        int z = q.top().first;
        int y = q.top().ss;
        ans+=z;
        k--;
        q.pop();
        q.push({z-y,y});
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
