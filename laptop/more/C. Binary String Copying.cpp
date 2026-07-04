#include <bits/stdc++.h>
#define int long long
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

void solve(){
    int n,m;
    cin >> n >> m;
    string s; cin >> s; //don't count unless you need to 
    vi next1(n), last1(n), next0(n), last0(n);
    int ptr = n;
    for(int i=n-1;i>=0;i--){
        if(s[i] == '1'){
            ptr = i;
        }
        next1[i] = ptr;
    }
    ptr = -1;
    for(int i=0;i<n;i++){
        if(s[i] == '1'){
            ptr = i;
        }
        last1[i] = ptr;
    }
    ptr = n;
    for(int i=n-1;i>=0;i--){
        if(s[i] == '0'){
            ptr = i;
        }
        next0[i] = ptr;
    }
    ptr = -1;
    for(int i=0;i<n;i++){
        if(s[i] == '0'){
            ptr = i;
        }
        last0[i] = ptr;
    }
    bool flag = false;
    set<pii> diffs;
    while(m--){
        int l,r; cin >> l >> r;
        --l; --r;
        if(s[l] == '0' && next1[l] > r){
            flag = true;
            continue;
        }
        if(s[l] == '1' && next0[l] > r){
            flag = true;
            continue;
        }
        l = next1[l];
        r = last0[r];
        //cout << l << " " << r << "!!\n";
        if(l <= r){
            diffs.insert({l,r});
        } else{
            flag = true;
        }
    }
    //cout << flag << "!\n";
    cout << (int)(diffs.size()) + flag << "\n";
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