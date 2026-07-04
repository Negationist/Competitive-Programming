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
    int n;
    cin >> n;
    vector<string> set(n);
    for(int i=0;i<n;i++){
        cin >> set[i];
    }
    auto dq = [&](auto self, vector<string> s){
        int z = s.size();
        if(z==1)  return s[0];
        vector<string> gotten;
        for(int i=0;i<z;i++){
            for(int j=0;j<z;j++){
                if(i!=j){
                    int l = min((int)s[i].size(),(int)s[j].size());
                    for(int k=0;k<l;k++){
                        vector<string> n_s;
                        string pref_i = s[i].substr(0,s[i].size()-k-1), suff_i = s[i].substr(s[i].size()-k-1,k+1);
                        string pref_j = s[j].substr(0,k+1), suff_j = s[j].substr(k+1,s[j].size()-k-1);
                        if(suff_i==pref_j){
                            n_s.pb(s[i]+suff_j);
                            for(int r=0;r<z;r++){
                                if(r!=i && r!=j){
                                    n_s.pb(s[r]);
                                }
                             }
                            gotten.pb(self(self,n_s));
                        }
                    }
                }
            }
        }
        string res = "idubaspdfonfdoanfdasdnnfsdfnpoasidnfsapifnsapdounspuadsfbppadfbudubafds0un";
        for(string x : gotten){
            if((int)x.size()<(int)res.size()){
                res = x;
            } else if((int)x.size()==(int)res.size()){
                if(x<res){
                    res = x;
                }
            }
        }
        return res;
    };
    string add = dq(dq,set);
    if(add=="idubaspdfonfdoanfdasdnnfsdfnpoasidnfsapifnsapdounspuadsfbppadfbudubafds0un"){
        cout << -1 << "\n";
    } else{
        cout << add << "\n";
    }
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    solve();
    return 0;
}