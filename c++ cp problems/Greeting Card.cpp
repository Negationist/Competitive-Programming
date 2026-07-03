#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
#define vll vector<pair<long long,long long>>
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

void solve(){
    int n;
    cin >> n;
    vector<pii> refs;
    for(int i=0;i<=2018;i++){
        int temp = 2018*2018 - i*i;
        if((int)sqrtl(temp) * (int)sqrtl(temp) == temp){
            refs.pb({i,(int)sqrt(temp)});
        }
    }
    set<pii> points;
    ll ans = 0;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        for(auto [a,b] : refs){
            set<pii> look;
            look.insert(make_pair(x-a, y-b));
            look.insert(make_pair(x-a, y+b));
            look.insert(make_pair(x+a, y-b));
            look.insert(make_pair(x+a, y+b));
            for(auto x : look){
                ans += (points.find(x) != points.end());
            }
        }
        points.insert(make_pair(x,y));
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