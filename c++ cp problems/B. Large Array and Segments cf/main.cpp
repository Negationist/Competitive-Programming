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
    int n,k,x;
    cin >> n >> k >> x;
    vi a(n);
    int sum = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    int pool = sum*k-x;
    if(pool<0){
        cout << 0 << "\n";
        return;
    }
    int num = (pool/sum)*n;
    //cout << num << "\n";
    pool%=sum;
    //cout << pool << "\n";
    for(int i=0;i<n;i++){
        pool-=a[i];
        if(pool>=0){
            ++num;
        }
    }
    cout << num+1 << "\n";
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
