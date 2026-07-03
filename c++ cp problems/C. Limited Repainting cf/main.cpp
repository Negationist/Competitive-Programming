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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    auto check = [&](int x){
        int num = 0;
        bool open = false;
        for(int i=0;i<n;i++){
            if(a[i]<=x) continue;
            if(s[i]=='R'){
                if(open==true){
                    open = false;
                }
            } else if(s[i]=='B'){
                if(open==false){
                    ++num;
                    open = true;
                }
            }
        }
        return (num<=k);
    };
    int lo = 0, hi = 1e9;
    while(lo<=hi){
        //cout << "here\n";
        int mid = lo+(hi-lo)/2;
        if(check(mid)){
            hi = mid-1;
        } else{
            lo = mid+1;
        }
    }
    cout << lo << "\n";
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
