#include <bits/stdc++.h>
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << "\n"
#define each(a, x) for(auto &&a : x)
using namespace std;
using ll = long long;

template <typename T, typename F>
struct SparseTable {
    int n;
    vector<vector<T>> st;
    vector<int> log;
    F merge;
    T identity;
    SparseTable(F merge_op, T id, const vector<T>& a) : merge(merge_op), identity(id) {
         n = a.size();
         log.resize(n+1);
         for (int i = 2; i <= n; i++) {
             log[i] = log[i/2] + 1;
         }
         int K = (n ? log[n] : 0) + 1;
         st.assign(n, vector<T>(K, identity));
         for (int i = 0; i < n; i++) {
              st[i][0] = a[i];
         }
         for (int j = 1; j < K; j++) {
             for (int i = 0; i + (1 << j) <= n; i++) {
                 st[i][j] = merge(st[i][j-1], st[i + (1 << (j-1))][j-1]);
             }
         }
    }
    T query(int L, int R) {
         if (L > R) return identity;
         int j = log[R - L + 1];
         return merge(st[L][j], st[R - (1 << j) + 1][j]);
    }
};

void solve(){
    int n;
    cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    auto op = [&](int x, int y){
        return __gcd(x,y);
    };
    SparseTable<int, decltype(op)> table1(op, 0, a);
    SparseTable<int, decltype(op)> table2(op, 0, b);

    vi prefA(n), prefB(n), sufA(n), sufB(n);
    prefA[0] = a[0]; prefB[0] = b[0];
    for (int i = 1; i < n; i++){
        prefA[i] = __gcd(prefA[i-1], a[i]);
        prefB[i] = __gcd(prefB[i-1], b[i]);
    }
    sufA[n-1] = a[n-1]; sufB[n-1] = b[n-1];
    for (int i = n-2; i >= 0; i--){
        sufA[i] = __gcd(sufA[i+1], a[i]);
        sufB[i] = __gcd(sufB[i+1], b[i]);
    }

    vector<int> poi;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++){
        int temp1 = __gcd(x, a[i]);
        int temp2 = __gcd(y, b[i]);
        bool flag = false;
        if (temp1 != x) {
            poi.pb(i);
            flag = true;
        }
        if (!flag && temp2 != y) {
            poi.pb(i);
        }
        x = temp1;
        y = temp2;
    }
    auto get1 = [&](int index){
        vi res;
        res.pb(index);
        int mn = table1.query(0, index);
        int cur = a[index];
        int pos = index;
        while (cur != mn){
            int lo = 0, hi = pos;
            while (lo <= hi){
                int mid = lo + (hi - lo) / 2;
                int temp = table1.query(mid, index);
                if (temp < cur){
                    lo = mid + 1;
                } else{
                    hi = mid - 1;
                }
            }
            res.pb(hi);
            cur = table1.query(hi, index);
        }
        reverse(res.begin(), res.end());
        return res;
    };
    auto get2 = [&](int index){
        vi res;
        res.pb(index);
        int mn = table2.query(0, index);
        int cur = b[index];
        int pos = index;
        while (cur != mn){
            int lo = 0, hi = pos;
            while (lo <= hi){
                int mid = lo + (hi - lo) / 2;
                int temp = table2.query(mid, index);
                if (temp < cur){
                    lo = mid + 1;
                } else{
                    hi = mid - 1;
                }
            }
            res.pb(hi);
            cur = table2.query(hi, index);
        }
        reverse(res.begin(), res.end());
        return res;
    };
    vii dp(n);
    for (int i = 0; i < n; i++){
        int a_gcd = (i < n-1 ? sufA[i+1] : 0);
        int b_gcd = (i < n-1 ? sufB[i+1] : 0);
        vi temp1 = get1(i);
        vi temp2 = get2(i);
        vi cand;
        for (int x : temp1) cand.pb(x);
        for (int x : temp2) cand.pb(x);
        int pos = upper_bound(poi.begin(), poi.end(), i) - poi.begin();
        for (int j = 0; j < pos; j++){
            cand.pb(poi[j]);
        }
        sort(cand.begin(), cand.end());
        cand.erase(unique(cand.begin(), cand.end()), cand.end());
        vi last;
        last.pb(-1);
        for (int x : cand) last.pb(x);
        auto calc = [&](int x) {
            int leftA = (x ? prefA[x-1] : 0);
            int leftB = (x ? prefB[x-1] : 0);
            int mid1 = table2.query(x, i);
            int mid2 = table1.query(x, i);
            int res1 = __gcd(leftA, mid1);
            res1 = __gcd(res1, a_gcd);
            int res2 = __gcd(leftB, mid2);
            res2 = __gcd(res2, b_gcd);
            return res1 + res2;
        };
        int z = last.size();
        int mx = -1, cnt = 0;
        for (int j = z - 1; j >= 1; j--){
            int num = last[j] - last[j-1];
            int curVal = calc(last[j]);
            if (curVal > mx){
                mx = curVal;
                cnt = num;
            } else if (curVal == mx){
                cnt += num;
            }
        }
        dp[i] = {mx, cnt};
    }
    int mx = -1;
    ll cnt = 0;
    for (int i = 0; i < n; i++){
        if (dp[i].ff > mx){
            mx = dp[i].ff;
            cnt = dp[i].ss;
        } else if (dp[i].ff == mx){
            cnt += dp[i].ss;
        }
    }
    cout << mx << " " << cnt << "\n";
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
