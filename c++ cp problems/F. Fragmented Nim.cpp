#include <bits/stdc++.h>
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
    vi a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(all(a));
    reverse(all(a));
    while(a[sz(a)-1] == 1 && a[sz(a)-2] == 1 && sz(a)>=2){
        a.pop_back();
        a.pop_back();
    }
    string ans;
    if(sz(a)==0){
        ans = "Bob";
    } else if(a.back() == 1 && sz(a)==1){
        ans = "Alice";
    } else if(a.back() == 1 && sz(a)>1){
        ans = "Bob";
    } else{
        ans = "Alice";
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