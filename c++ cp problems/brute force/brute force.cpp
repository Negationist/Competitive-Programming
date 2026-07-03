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

int get_num(string s){
    int n = (int)(s.size());
    int res = 0;
    for(int l=0;l<n;l++){
        for(int r=l;r<n;r++){
            int sum = 0, fail = 0;
            for(int j=l;j<=r;j++){
                sum+=(s[j]=='('?1:-1);
                if(sum<0){
                    fail = true;
                }
            }
            if(!fail && sum==0){
                ++res;
            }
        }
    }
    return res;
}

void solve(){
    string dict[4] = {"((","()",")(","))"};
    int l = 0, r = 0;
    vector<vector<string>> sequences(50);
    for(int i=0;i<50;i++){
        for(int j=0;j<(1LL<<i);j++){
            string cur;
            for(int k=0;k<i;k++){
                if(j&(1LL<<k)){
                    cur.pb('(');
                } else{
                    cur.pb(')');
                }
            }
            sequences[i].pb(cur);
            if(i==3){
                cout << cur << "!\n";
            }
        }
    }
    while(true){
        for(int r=0;r<=l;r++){
            for(string left : sequences[l]){
                for(string right : sequences[r]){
                    set<int> nums;
                    bool bad = false;
                    for(string mid : sequences[4]){
                        int z = get_num(left+mid+right);
                        if(nums.find(z)!=nums.end()){
                            bad = true;
                            break;
                        }
                        nums.insert(z);
                    }
                    if(bad) continue;
                    cout << "left is " << left << "\n";
                    cout << "right is " << right << "\n";
                    return;
                }
            }
        }
        ++l;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}