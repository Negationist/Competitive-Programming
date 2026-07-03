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
    int n,k;
    cin >> n >> k;
    vi a(n),b(n);
    auto make = [&](int l, int r, int tag)->void{
        for(int i=l;i<=r;i++){
            b[i] = tag;
        }
        int _cur = 0;
        int num = (l+r+2)/2;
        int _inc = 1;
        while(l<=r){
            if(!_cur){
                a[l] = num;
                l++;
                num+=_inc;
            } else{
                a[r] = num;
                r--;
                num-=_inc;
            }
            _inc++;
            _cur = 1-_cur;
        }
    };
    int index = 0;
    int inc = 0;
    while(index<n){
        make(index,min(index+k-1,n-1),++inc);
        index+=k;
    }
    for(int x : a){
        cout << x << " ";
    }
    cout << "\n";
    cout << inc << "\n";
    for(int x : b){
        cout << x << " ";
    }
    cout << "\n";
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
