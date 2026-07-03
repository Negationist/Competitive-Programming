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
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    set<int> s1,s2;
    for(int i=1;i<=n;i++){
        s1.insert(i);
        s2.insert(i);
    }
    int ans = 0;
    int l=0, r = n-1;
    while(true){
        int con = 0;
        int inc = 0;
        while(l<n){
            auto it = s1.upper_bound(a[l]);
            if(it!=s1.begin()){
                it--;
                s1.erase(*it);
                con-=l;
                ++l;
                ++inc;
                break;
            } else{
                ++l;
            }
        }
        while(r>=0){
            auto it = s2.upper_bound(a[r]);
            if(it!=s2.begin()){
                it--;
                s2.erase(*it);
                con+=r;
                ++inc;
                --r;
                break;
            } else{
                --r;
            }
        }
        if(inc<2 || con<=0){
            break;
        } else{
            ans+=con;
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
