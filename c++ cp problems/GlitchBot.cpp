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
    int x,y;
    cin >> x >> y;
    int n; cin >> n;
    string dict[3] = {"Left", "Forward", "Right"};
    map<string,int> m;
    m["Left"] = 0;
    m["Forward"] = 1;
    m["Right"] = 2;
    auto get_pos = [&](vi &a){
        int px = 0, py = 0;
        int dir = 0;
        for(int i=0;i<n;i++){
            string s = dict[a[i]];
            if(m[s]==1){
                if(dir==0){
                    py++;
                } else if(dir==1){
                    px++;
                } else if(dir==2){
                    py--;
                } else{
                    px--;
                }
            } else{
                dir += (m[s]-1);
                dir = (dir+4)%4;
            }
        }
        return make_pair(px,py);
    };
    vi a(n);
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        a[i] = m[s];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            a[i] = (a[i]+1)%3;
            if(get_pos(a) == make_pair(x,y)){
                cout << i+1 << " " << dict[a[i]] << "\n";
                return;
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}