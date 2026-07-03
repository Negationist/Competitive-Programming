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

const set<char> digits = {'2', '3', '4', '5', '6', '7', '8', '9'};

void solve(){
    int inc = 1;
    string s; cin >> s;
    int n = sz(s);
    vl len(2*n,0), reps(2*n, 1);
    vector<char> data(2*n, ' ');
    vector<vi> chi(2*n, vi());
    stack<int> pos;
    pos.push(0); //root
    int last = -1;
    for(int i=0;i<n;i++){ //children get ordered automatically
        if(s[i] == '+') continue;
        if(s[i] == '('){
            chi[pos.top()].pb(inc);
            pos.push(inc++);
        } else if(s[i] == ')'){
            last = pos.top();
            pos.pop();
        } else if(digits.find(s[i]) != digits.end()){
            reps[last] = (s[i] - '0');
        } else{
            last = inc;
            chi[pos.top()].pb(inc);
            data[inc++] = s[i];
        }
    }
    auto dfs_len = [&](auto self, int x) ->void {
        if(data[x] == ' '){
            for(int y : chi[x]){
                self(self, y);
                len[x]+=(len[y] * reps[y]);
            }
        } else{
            len[x] = 1;
        }
    };
    dfs_len(dfs_len, 0);
    auto dfs_ans = [&](auto self, int x, ll num) ->void {
        if(data[x] == ' '){
            for(int y : chi[x]){
                if(len[y] * reps[y] < num){
                    num -= (len[y] * reps[y]);
                } else{
                    num%=len[y];
                    if(num == 0){
                        num = len[y];
                    }
                    self(self, y, num);
                    break;
                }
            }
        } else{
            cout << data[x] << "\n";
        }
    };
    int N; cin >> N;
    dfs_ans(dfs_ans, 0, N);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
