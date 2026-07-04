#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

void solve(){
    int n,k;
    cin >> n >> k;
    multiset<int> s;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        s.insert(z);
    }
    int ans = 0;
    while(s.size()>2){
        int lo = *s.begin();
        s.erase(s.find(lo));
        int temp = *s.begin();
        if(lo+temp>=k){
            s.insert(lo);
            break;
        } else{
            auto it = s.lower_bound(k-lo);
            it--;
            s.erase(it);
            int hi = *s.rbegin();
            s.erase(s.find(hi));
            ++ans;
        }
    }
    while(s.size()){
        ++ans;
        int lo = *s.begin();
        s.erase(s.find(lo));
        if(s.size() && lo<k){
            int x = *s.rbegin();
            s.erase(s.find(x));
        }
    }
    cout << ans-1 << "\n";
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
