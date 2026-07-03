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
    vi a(n);
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        a[i] = (z<=k?-1:1);
    }
    bool win = false;
    int minl = LLONG_MAX,maxr = LLONG_MIN;
    int cnt = 0;
    bool in = false;
    for(int i=0;i<n;i++){
        cnt+=(a[i]);
        if(!in){
            if(cnt<=0){
                minl = i;
                in = true;
            }
            if(cnt==-1){
                if(i+1<n && a[i+1]==1){
                    ++i;
                    cnt = 0;
                }
            }
        } else{
            if(cnt<=0){
                win = true;
            }
        }
    }
    reverse(a.begin(),a.end());
    cnt = in = 0;
    for(int i=0;i<n;i++){
        cnt+=(a[i]);
        if(!in){
            if(cnt<=0){
                maxr = n-1-i;
                in = true;
            }
            if(cnt==-1){
                if(i+1<n && a[i+1]==1){
                    ++i;
                    cnt = 0;
                }
            }
        } else{
            if(cnt<=0){
                win = true;
            }
        }
    }
    if(win || (minl<maxr)){
        cout << "YES\n";
    } else{
        cout << "NO\n";
    }
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
