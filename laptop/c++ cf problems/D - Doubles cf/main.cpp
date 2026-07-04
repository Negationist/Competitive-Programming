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
    cout << fixed << setprecision(16);
    int n;
    cin >> n;
    map<int,ld> mxchance;
    ld ans = 0;
    auto get = [&](map<int,ld> &l, map<int,ld> &r){
        ld res = 0;
        for(auto x : l){
            //cout << x.ss << "  " << r[x.ff] << "!\n";
            ld temp = x.ss*r[x.ff];
            //cout << temp << "!\n";
            res+=temp;
        }
        return res;
    };
    vector<map<int,ld>> a(n);
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        map<int,int> cnt;
        for(int j=0;j<z;j++){
            int x;
            cin >> x;
            ++cnt[x];
        }
        for(auto x : cnt){
            ld chance = (ld)x.ss/z;
            a[i][x.ff] = chance;
        }
        for(int j=i-1;j>=0;j--){
            ld res = get(a[i],a[j]);
            ans = max(ans,res);
        }
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
