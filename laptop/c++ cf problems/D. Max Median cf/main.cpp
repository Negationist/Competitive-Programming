#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;

void solve(){
    int n,k;
    cin >> n >> k;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int l = 1, r=n;
    auto check = [&](vi &a, int cur)->bool{
        bool good = false;
        vi b(n);
        for(int i=0;i<n;i++){
            if(a[i]>=cur){
                b[i] = 1;
            } else{
                b[i] = -1;
            }
        }
        vi pref(n),mn(n);
        pref[0] = mn[0] = b[0];
        int sum = b[0];
        for(int i=1;i<n;i++){
            sum+=b[i];
            pref[i] = sum;
            mn[i] = min(sum, mn[i-1]);
        }
        for(int i=k-1;i<n;i++){
            int lo = (i==k-1?0:mn[i-k]);
            lo = min(lo,0LL);
            int diff = pref[i]-lo;
            if(diff>0){
                good = true;
            }
        }
        return good;
    };
    while(l<=r){
        int mid = l+(r-l)/2;
        if(check(a,mid)){
            l = mid+1;
        } else{
            r = mid-1;
        }
    }
    cout << r << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
