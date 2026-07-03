#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
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
    int n,x;
    cin >> n >> x;
    --x;
    string s; cin >> s;
    set<int> left,right;
    for(int i=0;i<x;i++){
        if(s[i]=='#') left.insert(i);
    }
    for(int i=x+1;i<n;i++){
        if(s[i]=='#') right.insert(i);
    }
    int ans = 0;
    while(true){
        if(x==0 || x==n-1){
            ++ans;
            break;
        }
        if(left.find(x-1)!=left.end()){
            right.insert(x+1);
        }
        else if(right.find(x+1)!=right.end()){
            left.insert(x-1);
        } else{
            if(!left.size() && !right.size()){
                ++ans;
                break;
            } else if(left.size() && !right.size()){
                right.insert(x+1);
            } else if(!left.size() && right.size()){
                left.insert(x-1);
            } else{
                int l_wall = *left.rbegin(), r_wall = *right.begin();
                if(l_wall+1<=n-r_wall){
                    left.insert(x-1);
                } else{
                    right.insert(x+1);
                }
            }
        }
        int l_wall = *left.rbegin(), r_wall = *right.begin();
        if(l_wall+1<=n-r_wall){
            x = l_wall;
            left.erase(l_wall);
        } else{
            x = r_wall;
            right.erase(r_wall);
        }
        ++ans;
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