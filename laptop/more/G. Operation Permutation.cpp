    #include <bits/stdc++.h>
    #define pb push_back
    #define ff first
    #define ss second
    #define pii pair<int,int>
    #define vi vector<int>
    #define vii vector<pair<int,int>>
    #define print(x) cout << (x) << endl
    #define each(a, x) for(auto &&a : x)

    using namespace std;
    using ll = long long;
    using ld = long double;
    using u128 = unsigned __int128;
    using i128 = __int128;

    int MOD = 1e9+7;
    struct mi {
        int v;
        explicit operator int() const { return v; }

        mi() : v(0) {}
        mi(long long _v) : v(int(_v % MOD)) { if (v < 0) v += MOD; }
    };
    mi &operator+=(mi &a, mi b) { if ((a.v += b.v) >= MOD) a.v -= MOD; return a; }
    mi &operator-=(mi &a, mi b) { if ((a.v -= b.v) < 0) a.v += MOD; return a; }
    mi operator+(mi a, mi b) { return a += b; }
    mi operator-(mi a, mi b) { return a -= b; }
    mi operator*(mi a, mi b) { return mi(1LL * a.v * b.v); }
    mi &operator*=(mi &a, mi b) { return a = a * b; }
    mi pow(mi a, long long p) {
        assert(p >= 0);
        mi res = 1;
        while (p) { if (p & 1) res *= a; a *= a; p >>= 1; }
        return res;
    }
    mi inv(mi a) { assert(a.v); return pow(a, MOD - 2); }
    mi operator/(mi a, mi b) { return a * inv(b); }
    mi &operator/=(mi &a, mi b) { return a = a / b; }
    inline bool operator==(mi a, mi b) { return a.v == b.v; }
    inline bool operator!=(mi a, mi b) { return a.v != b.v; }
    inline bool operator<(mi a, mi b)  { return a.v <  b.v; }
    inline bool operator>(mi a, mi b)  { return a.v >  b.v; }
    inline bool operator<=(mi a, mi b) { return a.v <= b.v; }
    inline bool operator>=(mi a, mi b) { return a.v >= b.v; }
    inline mi abs(mi a) { return (a.v < 0 ? mi(-a.v) : a); }
    inline std::ostream& operator<<(std::ostream& os, const mi& x) { return os << x.v; }

    const int mod = 1e9+7, maxN = 3005;

    int fact[maxN];

    void compute(){
        fact[0] = fact[1] = 1;
        for(int i=2;i<maxN;i++){
            fact[i] = (fact[i-1]*i)%mod;
        }
    }

    void solve(){
        int n,x;
        cin >> n >> x;
        mi ans = x;
        mi o = 0;
        vector<mi> ops;
        for(int i=0;i<n;i++){
            string s; cin >> s;
            char op = s[0];
            int num  = stoi(s.substr(1, (int)(s.size())-1));
            if(op == '+'){
                o+=num;
            } else if(op == '-'){
                o-=num;
            } else if(op == '/'){
                mi temp = 1;
                temp/=num;
                ops.pb(temp);
                ans/=num;
            } else{
                ops.pb(num);
                ans*=num;
            }
        }
        n = (int)ops.size();
        vector<mi> dp(n+1,0);
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            vector<mi> ndp(n+1);
            for(int j=0;j<=n;j++){
                ndp[j] = dp[j] + (j>0?dp[j-1]*ops[i-1] : 0);
            }
            dp = move(ndp);
        }
        mi effect = 0;
        for(int i=0;i<=n;i++){
            dp[i]*=(fact[i]);
            dp[i]*=(fact[n-i]);
            effect+=dp[i];
        }
        effect/=fact[n+1];
        ans+=(effect * o);
        cout << ans << "\n";
    }

    signed main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        compute();
        int t;
        cin >> t;
        while(t--){
            solve();
        }
        return 0;
    }