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
    vii mn(n);
    vii mx(n);
    stack<int> s1;
    stack<int> s2;
    for(int i=0;i<n;i++){
        mn[i] = {0,n-1};
        mx[i] = {0,n-1};
    }
    for(int i=n-1;i>=0;i--){
        while(s1.size() && a[s1.top()]>=a[i]){
            mn[s1.top()].ff = i+1;
            s1.pop();
        }
        s1.push(i);
        while(s2.size() && a[s2.top()]<=a[i]){
            mx[s2.top()].ff = i+1;
            s2.pop();
        }
        s2.push(i);
    }
    while(s1.size()) s1.pop();
    while(s2.size()) s2.pop();
    for(int i=0;i<n;i++){
        while(s1.size() && a[s1.top()]>a[i]){
            mn[s1.top()].ss = i-1;
            s1.pop();
        }
        s1.push(i);
        while(s2.size() && a[s2.top()]<a[i]){
            mx[s2.top()].ss = i-1;
            s2.pop();
        }
        s2.push(i);
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        int num1 = (i-mx[i].ff+1)*(mx[i].ss-i+1);
        int num2 = (i-mn[i].ff+1)*(mn[i].ss-i+1);
        ans+=(num1-num2)*a[i];
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
