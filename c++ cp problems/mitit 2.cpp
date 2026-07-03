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
    unordered_multiset<int> nums;
    auto get = [&](int x){
        unordered_multiset<int> res;
        while(x>0){
            res.insert(x%10);
            x/=10;
        }
        return res;
    };
    for(int i=1;i<=9999;i++){
        for(int j=i;j<=9999;j++){
            if(get(i) == get(j)){
                nums.insert(j-i);
            }
        }
    }
    for(int i=0;i<=999;i+=9){
        if(nums.find(i) == nums.end()){
            cout << i << "\n";
        }
    }
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