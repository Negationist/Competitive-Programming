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
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

const int MOD = 828362409;

struct mint {
    ll x;
    mint(ll x=0):x((x%MOD+MOD)%MOD){}
    mint& operator+=(const mint a) {if ((x += a.x) >= MOD) x -= MOD;return *this;}
    mint& operator-=(const mint a) {if ((x += MOD-a.x) >= MOD) x -= MOD;return *this;}
    mint& operator*=(const mint a) {(x *= a.x) %= MOD;return *this;}
    mint operator+(const mint a) const {mint res(*this);return res+=a;}
    mint operator-(const mint a) const {mint res(*this);return res-=a;}
    mint operator*(const mint a) const {mint res(*this);return res*=a;}
    mint pow(ll b) const {
      mint res(1), a(*this);
      while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
      }
      return res;
    }
    mint minv() const {return pow(MOD-2);}
    mint& operator/=(const mint a) {return (*this) *= a.minv();}
    mint operator/(const mint a) const {mint res(*this);return res/=a;}
};

i128 binpow(i128 b, ll p) {
    i128 res = 1;
    while(p){
        if(p&1){
            res*=b;
        }
        p>>=1;
        b*=b;
    }
    return res;
}

const int maxN = 100000;

void solve(){
    //cout << (int)(binpow(629961,4) - binpow(629960,4)) << "!\n";
    int n,k;
    cin >> n >> k;
    if(k == 3){
            ll upTo = min(n, 1'000'000LL); ll cnt = 0;
            for(int i = 1; i <= upTo; i++){
                if(n % i == 0){
                    //a^2 + ab + b^2
                    //(a + i)^2 + a(a + i) + a^2
                    //
                    ll get = n/i;
                    ll low = 1; ll high = 1e9;
                    while(low < high){
                        ll mid = (low + high)/2; 
                        ll val = (mid + i) * (mid + i) + mid*(mid + i) + mid*mid;
                        if(val >= get){
                            high = mid;
                        }
                        else{
                            low = mid + 1;
                        }
                    }
                    ll val = (low + i) * (low + i) + low*(low + i) + low*low;
                    if(val == get) cnt++;
                }
            }
            cout << cnt << "\n";
        }
        else if(k == 4){
            ll upTo = min(n, 32000LL); ll cnt = 0;
            for(int i = 1; i <= upTo; i++){
                if(n % i == 0){
                    //a^3 + ab^2 + a^2b + b^3
                    //(a + i)^2 + a(a + i) + a^2
                    //
                    ll get = n/i;
                    ll low = 1; ll high = 1e6;
                    while(low < high){
                        ll mid = (low + high)/2; 
                        ll val = mid * ((mid + i) * (mid + i) + mid*(mid + i) + mid*mid) + (mid + i)*(mid + i)*(mid + i);
                        if(val >= get){
                            high = mid;
                        }
                        else{
                            low = mid + 1;
                        }
                    }
                    //if(i == 1) cout << low << "\n";
                    ll val = low * ((low + i) * (low + i) + low*(low + i) + low*low) + (low + i)*(low + i)*(low + i);
                    if(val == get) cnt++;
                }
            }
            cout << cnt << "\n";

        } else{
            set<i128> nums;
            for(int i=1;i<=maxN;i++){
                nums.insert(binpow(i,k));
            }
            int ans = 0;
            for(int x : nums){
                if(nums.find(x+n)!=nums.end()){
                    ++ans;
                }
            }
            cout << ans << "\n";
        }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}