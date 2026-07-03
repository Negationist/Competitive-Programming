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
    auto b = a;
    sort(b.begin(),b.end());
    int x=0,y=n-1;
    while(a[x]==b[x] && x<n-1){
        x++;
    }
    while(a[y]==b[y] && y>0){
        y--;
    }
    map<int,int> seen;
    if(x>=y){
        cout << 0 << "\n";
        return;
    }
    vii next(n,{-1,n});
    stack<int> s;
    for(int i=0;i<n;i++){
        if(a[i]==b[i]){
            s.push(i);
        } else{
            while(s.size()){
                int cur = s.top();
                s.pop();
                next[cur].ss = i;
            }
            next[i].ss = i;
        }
    }
    while(s.size()) s.pop();
    for(int i=n-1;i>=0;i--){
        if(a[i]==b[i]){
            s.push(i);
        } else{
            while(s.size()){
                int cur = s.top();
                s.pop();
                next[cur].ff = i;
            }
            next[i].ff = i;
        }
    }
    int ans = (n-x)*(n-x);
    ans = min(ans, (y+1)*(y+1));
    int cnt1 = 0;
    int cnt2 = 0;
    int j = 0;
    for(int i=0;i<n-1;i++){
        ++cnt2;
        ++seen[a[i]];
        while(j<n){
            if(seen[b[j]]){
                --seen[b[j]];
                ++j;
                ++cnt1;
            } else break;
        }
        int res = (cnt2*cnt2)+(n-cnt1)*(n-cnt1);
        ans = min(res,ans);
        if(cnt2==cnt1){
            int savings = next[i+1].ss-(i+1);
            res = (cnt2*cnt2)+(n-cnt1-savings)*(n-cnt1-savings);
            ans = min(res,ans);
        }
    }
    j = n-1;
    cnt1 = 0;
    cnt2 = 0;
    map<int,int> seen2;
    for(int i=n-1;i>=1;i--){
        ++cnt2;
        ++seen2[a[i]];
        while(j>=0){
            if(seen2[b[j]]){
                --seen2[b[j]];
                --j;
                ++cnt1;
            } else break;
        }
        int res = (cnt2*cnt2)+(n-cnt1)*(n-cnt1);
        ans = min(res,ans);
        if(cnt2==cnt1){
            int savings = next[i-1].ff-(i-1);
            res = (cnt2*cnt2)+(n-cnt1-savings)*(n-cnt1-savings);
            ans = min(res,ans);
        }
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
