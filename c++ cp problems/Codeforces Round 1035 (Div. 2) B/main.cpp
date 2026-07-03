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
using u128 = unsigned __int128;
using i128 = __int128;

const double eps = 1e-9;

void solve(){
    double x1,y1,x2,y2,n;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    vector<double> a(n);
    double sum = 0,mx = -1;
    for(int i=0;i<n;i++){
        cin >> a[i];
        mx = max(mx,a[i]);
        sum+=a[i];
    }
    double dist = sqrtl((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    if(n==1){
        cout << (abs(dist-(double)a[0])<eps?"yes\n":"no\n");
        return;
    }
    if(mx<=(sum-mx)+dist+eps && sum+eps>=dist){
        cout << "yes\n";
    } else{
        cout << "no\n";
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
