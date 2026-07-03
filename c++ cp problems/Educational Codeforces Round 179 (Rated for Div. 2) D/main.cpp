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
    int n,m;
    cin >> n >> m;
    vi a(m);
    for(int i=0;i<m;i++) cin >> a[i];
    sort(a.begin(),a.end());
    int l = 0, r = m-1, p = 0;
    for(int i=0;i<n;i++){
        if(p==2){
            ++l;
            --r;
            p = 0;
        }
        if(p==0){
            cout << a[l] << " " << a[r] << " ";
            cout << a[l] << " " << a[r] << " ";
            cout << a[l] << " " << a[r] << "\n";
        } else{
            swap(l,r);
            cout << a[l] << " " << a[r] << " ";
            cout << a[l] << " " << a[r] << " ";
            cout << a[l] << " " << a[r] << "\n";
            swap(l,r);
        }
        ++p;
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
