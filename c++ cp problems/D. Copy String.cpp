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
    int n,k;
    cin >> n >> k;
    string s,t; cin >> s >> t;
    int i = n-1, j = i;
    int ans = 0;
    while(j>=0){
        while(i>=0 && (s[i]!=t[j] || i>j)){
            --i;
        }
        if(i<0){
            cout << -1 << "\n";
            return;
        } else{
            //cout << j << " with " << i << "\n";
            ans = max(ans, j-i); 
            --j;
        }
    }
    if(ans > k){
        cout << -1 << "\n";
        return;
    } else{
        cout << ans << "\n";
        while(s != t){
            i = n-1, j = i;
            string temp = s;
            while(j>=0){
                while(i>=0 && (s[i]!=t[j] || i>j)){
                    --i;
                }
                if(j-i){
                    temp[i+1] = s[i];
                }
                --j;
            }
            s = temp;
            cout << s << "\n";
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