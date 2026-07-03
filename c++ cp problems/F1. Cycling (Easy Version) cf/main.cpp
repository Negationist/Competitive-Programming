#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
using ld = long double;
void solve(){
    int n;
    cin >> n;
    vi a(n);
    int mn = LLONG_MAX;
    for(int i=0;i<n;i++){
        cin >> a[i];
        mn = min(mn,a[i]);
    }
    int pos = -1;
    for(int i=0;i<n;i++){
        if(a[i]==mn){
            pos = max(pos,i);
        }
    }
    auto _do = [&](){
        int res = a[n-1];
        auto b = a;
        for(int i=n-2;i>=0;i--){
            if(b[i]>b[i+1]){
                swap(b[i],b[i+1]);
                res+=1;
            }
            res+=b[i];
        }
        return res;
    };
    int ans1 = _do();
    swap(a[pos],a[n-1]);
    int ans2 = _do()+n-1-pos;
    cout << min(ans1,ans2) << "\n";
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
