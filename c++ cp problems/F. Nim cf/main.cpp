#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
const int inf = 1LL<<60;
const int mod = 998244353;
void solve(){
    int n,q;
    cin >> n >> q;
    vector<vi> pref(51, vi(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=0;j<51;j++){
            pref[j][i] = pref[j][i-1];
        }
        int z;
        cin >> z;
        pref[z][i]++;
    }
    auto get = [&](int a, int b, vi &cnt)->bool{
        bool easy = false;
        cnt.resize(51);
        for(int i=0;i<51;i++){
            int num = pref[i][b]-pref[i][a-1];
            cnt[i] = num;
            if(num>=2){
                easy = true;
            } else if(num==1 && i==0){
                easy = true;
            }
        }
        return easy;
    };
    auto genAns = [&](vi &a)->int{
        int res = 0;
        for(int i=0;i<51;i++){
            int num = (a[i]*(a[i]-1))/2;
            res+=num;
            res%=mod;
        }
        return res;
    };
    auto getdpans = [&](vi &cur)->pii{
        int n = cur.size();
        vii dp(64,{inf,-1});
        dp[cur[0]] = {1,1};
        for(int i=1;i<n;i++){
            auto ndp = dp;
            for(int j=1;j<64;j++){
                if(dp[j].ss == -1) continue;
                int res = j^cur[i];
                if(dp[j].ff+1<ndp[res].ff){
                    ndp[res] = {dp[j].ff+1,dp[j].ss};
                } else if(dp[j].ff+1==ndp[res].ff){
                    ndp[res].ss+=dp[j].ss;
                }
            }
            ndp[cur[i]] = {1,1};
            dp = move(ndp);
        }
        return dp[0];
    };
    while(q--){
        int l,r;
        cin >> l >> r;
        vi cnt;
        bool easy = get(l,r,cnt);
        if(easy){
            int ans;
            if(cnt[0]){
                ans = cnt[0];
            cout << r-l << " ";
            } else{
                ans = genAns(cnt);
                cout << r-l-1 << " ";
            }
            cout << ans%mod << "\n";
        } else{
            vi cur;
            for(int i=0;i<51;i++){
                while(cnt[i]--){
                    cur.pb(i);
                }
            }
            pii ans = getdpans(cur);
            if(ans.ss!=-1){
                cout << r-l+1-ans.ff << " " << ans.ss << "\n";
            } else{
                cout << -1 << "\n";
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
