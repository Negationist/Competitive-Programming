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
    int mn = LLONG_MAX;
    int index = -1;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i]<mn){
            mn = a[i];
            index = i;
        } else if(a[i]==mn){
            index = -1;
        }
    }
    for(int i=0;i<n;i++){
        a.pb(a[i%n]);
    }
    vii b(n);
    stack<pii> s;
    for(int i=0;i<2*n;i++){
        while(s.size() && a[i] <= s.top().ff){
            b[s.top().ss].ss = i%n;
            s.pop();
        }
        if(i<n){
            s.push({a[i],i});
        }
    }
    for(int i=2*n-1;i>=0;i--){
        while(s.size() && a[i] <= s.top().ff){
            b[s.top().ss].ff = i%n;
            s.pop();
        }
        if(i>=n){
            s.push({a[i],i%n});
        }
    }
    vi diff(n,0);
    for(int i=0;i<n;i++){
        if(index==i){
            diff[0]+=a[i];
        } else{
            if(b[i].ff>i){
                b[i].ff-=n;
            }
            int x = i-b[i].ff;
            if(b[i].ss<i){
                b[i].ss+=n;
            }
            int y = b[i].ss-i;
            diff[0]+=a[i];
            diff[x]-=a[i];
            diff[y]-=a[i];
            diff[y+x]+=a[i];
        }
    }
    vi pref1(n),pref2(n);
    pref2[0] = pref1[0] = diff[0];
    cout << pref2[0] << "\n";
    for(int i=1;i<n;i++){
        pref1[i] = pref1[i-1]+diff[i];
        pref2[i] = pref2[i-1]+pref1[i];
        cout << pref2[i] << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
