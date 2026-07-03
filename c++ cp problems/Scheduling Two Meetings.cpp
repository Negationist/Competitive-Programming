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
 
const pii null = {-1,-1};

void solve(){
    int n,m;
    cin >> n >> m;
    int maxN = 1LL<<m;
    vii dp(maxN, null);
    vi nums;
    for(int i=1;i<=n;i++){
        string s; cin >> s;
        ll num = 0, b = 1, cnt = 0;
        while(s.size()){
            if(s.back() == 'Y'){
                num+=b;
                cnt++;
            }
            b<<=1;
            s.pop_back();
        }
        //cout << num << "!!\n";
        dp[num] = max(dp[num],{cnt, -i});
        nums.pb(cnt);
    }
    for(int i=maxN-1;i>=0;i--){
        for(int j=0;j<m;j++){
            if(!((1LL<<j) & i)){
                dp[i] = max(dp[i], dp[i + (1LL << j)]);
            }
        }  
    }
    pii ans;
    int mx = -1;
    bool flag = false;
    for(int i=0;i<maxN-1;i++){
        ll comp = (maxN-1) ^ (i);
        if(dp[i] != null && dp[comp]!=null){
            flag = true;
            int tot = dp[i].ff + dp[comp].ff;
            pii test = {min(-dp[i].ss, -dp[comp].ss), max(-dp[i].ss, -dp[comp].ss)};
            if(tot > mx){
                mx = tot;
                ans = test;
            } else if(tot == mx && test < ans){
                ans = test;
            }
        }
    }
    if(dp[maxN-1] != null){
        int idx = -dp[maxN-1].ss, idx2, best = -1;
        for(int i=0;i<n;i++){
            if(i+1 != idx){
                if(nums[i] > best){
                    idx2 = i;
                    best = nums[i];
                }
            }
        }
        idx2++;
        if(idx > idx2){
            swap(idx, idx2);
        }
        cout << idx << " " << idx2 << "\n";
        return;
    }
    if(flag){
        cout << ans.ff << " " << ans.ss << "\n";
    } else{
        cout << "No\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}