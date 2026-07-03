#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
const int inf = 1LL<<60;

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    auto possible = [&](int z)->bool{
        if (z == n) return true;
        int num = 0;
        for(int i=0;i<n-1;i++){
            while((z+z-num)*(num+1)/2 <= a[i] && num<z) ++num;
            if(i+1-num == n-z){
                return true;
            }
        }
        return false;
    };
    int l = 1, r = n; //how many that bessie takes
    while(l<=r){
        int mid = l+(r-l)/2;
        if(possible(mid)){
            r = mid-1;
        } else{
            l = mid+1;
        }
    }
    cout << min(l*(l+1)/2,a.back()) << "\n";
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
