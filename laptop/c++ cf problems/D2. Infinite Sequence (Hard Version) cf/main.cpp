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
using u128 = unsigned __int128;
using i128 = __int128;
void solve(){
    int n,l,r;
    cin >> n >> l >> r;
    vi a(n+1),pref(n+1);
    a[0] = pref[0] = 0;
    for(int i=1;i<=n;i++){
         cin >> a[i];
         pref[i] = pref[i-1]^a[i];
    }
    if(n%2!=1){
        ++n;
        a.pb(pref[n/2]);
        pref.pb(pref.back()^a.back());
    }
    auto sum = [&](int x){
        int res = 0;
        //reduction is odd and >n, form is xz or xz1
        for(int i=1;i<=63;i++){
            for(int j=0;j<=1;j++){
                if(!(i&1)) continue;
                int mult = 1LL<<i;
                int lo = n+2, hi = (1e18+5)/mult; //number that we reduce to
                if(hi<lo || lo*mult+j>x) continue; //break?
                while(lo<=hi){ //find the highest working number
                    int mid = lo+(hi-lo)/2;
                    int val = mid*mult+j;
                    if(val<=x){
                        lo = mid+1;
                    } else{
                        hi = mid-1;
                    }
                }
                int num = 0;
                if(hi&1){
                    num++;
                    hi--;
                }
                num+=((hi-n-1)/2);
                res+=(num*pref[n]);
                //cout << num << "\n";
            }
        }
        //cout << res << "\n";
        for(int i=1;i<=n;i++){
            //case 1, only leading zeros
            if(i*2>n){
                i128 temp = i;
                int inc = 0;
                int odd = 0, even = 0;
                while(temp*2<=x){
                    temp*=2;
                    ++inc;
                    if(inc&1) ++odd;
                    else ++even;
                }
                int res1 = odd*pref[i];
                int res2 = even*(pref[n]^pref[i]);
                res+=res1;
                res+=res2;
            }
            if(i*2>n){
                i128 temp = i*2; //do NOT consider x1, its weird
                int inc = 0;
                int odd = 0, even = 0;
                while(temp*2+1<=x){
                    temp*=2;
                    ++inc;
                    if(inc&1) ++even;
                    else ++odd;
                }
                int res1 = odd*pref[i];
                int res2 = even*(pref[n]^pref[i]);
                res+=res1;
                res+=res2;
            }
            if(i*2+1>n && i*2+1<=x){ //x1 case
                res+=pref[i];
            }
        }
        return res;
    };
    int ans = sum(r)-sum(l-1);
    while(l<=n && l<=r){
        ans+=a[l];
        ++l;
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
