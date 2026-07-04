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


const int inf = 10000000;

void solve(){
    auto truncate = [&](string x)->string {
        int y = x.size();
        return x.substr(1, y-2);
    };
    auto min_ops = [&] (int l, int r, int will_left, int will_right, int right_up, int left_up)->int {
        int ops = 0;
        if(right_up && r==9 && !will_right) return inf;
        else if(right_up){
            ++r;
            if(r==10){
                r = 0;
                will_right = 0;
            }
        }
        if(left_up && l==9 && !will_left) return inf;
        else if(left_up){
            ++l;
            if(l==10){
                l = 0;
                will_left = 0;
            }
        }
        if(will_left){
            bool flag = false;
            while(!flag){
                ++ops;
                l = (l+1)%10;
                if(l == 0){
                    flag = true;
                }
            }
        }
        if(will_right){
            bool flag = false;
            while(!flag){
                ++ops;
                r= (r+1)%10;
                if(r == 0){
                    flag = true;
                }
            }
        }
        ops+=(max(l,r) -  min(l,r));
        return ops;
    };
    int dp[100][2]; //for two digit numbers
    for(int i=0;i<=99;i++){
        dp[i][0] = dp[i][1] = inf;
        for(int j=0;j<20;j++){
            for(int k=0;k<20;k++){
                int add = 10*j  + k;
                int res = i + add;
                if(res < 100){
                    if(res/10 == res%10){
                        dp[i][0] = min(dp[i][0], j+k);
                    }
                } else if(res < 200){
                    res-=100;
                    if(res/10 == res%10){
                        dp[i][1] = min(dp[i][1], j+k);
                    }
                }
            }
        }
    }
   auto get = [&](auto self, string x, int carry_in) -> array<int, 2> {
        array<int,2> res;
        int L = (int)(x[0] - '0'), R = (int)(x.back() - '0');
        if((int)x.size()==1){
            if(stoi(x) == 9 && carry_in){
                res[0] = inf;
                res[1] = 0;
            } else{
                res[0] = 0;
                res[1] = 10 - (stoi(x) + carry_in);
            }
        } else if((int)x.size()==2){
            if(stoi(x) == 99){
                if(carry_in){
                    res[0] = inf;
                    res[1] = 0;
                } else{
                    res[0] = 0;
                    res[1] = 1;
                }
            } else{
                res[0] = dp[stoi(x) + carry_in][0];
                res[1] = dp[stoi(x) + carry_in][1];
            }
        } else{
            auto [middle_in_null, middle_in_out] = self(self, truncate(x), 1);
            auto [middle_null_null, middle_null_out] = self(self, truncate(x), 0);
            res[0] = min({
                middle_in_null + min_ops(L, R, 0, 1, carry_in, 0),
                middle_in_out + min_ops(L, R, 0, 1, carry_in, 1),
                middle_null_null + min_ops(L, R, 0, 0, carry_in, 0),
                middle_null_out + min_ops(L, R, 0, 0, carry_in, 1),
            });
            res[1] = min({
                middle_in_null + min_ops(L, R, 1, 1, carry_in, 0),
                middle_in_out + min_ops(L, R, 1, 1, carry_in, 1),
                middle_null_null + min_ops(L, R, 1, 0, carry_in, 0),
                middle_null_out + min_ops(L, R, 1, 0, carry_in, 1),
            });
        }
        return res;
   };
   string s; cin >> s;
   array<int,2> ans1 = get(get, s, 0);
   cout << min(ans1[0], ans1[1]) << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}