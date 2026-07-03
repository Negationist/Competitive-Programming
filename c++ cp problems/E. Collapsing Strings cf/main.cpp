#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
void solve(){
    int n;
    cin >> n;
    vector<string> a(n);
    int tot = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        int z = a[i].size();
        tot+=z;
    }
    auto b = a;
    for(int i=0;i<n;i++){
        reverse(b[i].begin(),b[i].end());
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    auto iscommon = [&](string &x, string &y)->bool{
        if(y.size()<x.size()){
            return false;
        } else{
            for(int i=0;i<x.size();i++){
                if(x[i]!=y[i]){
                    return false;
                }
            }
            return true;
        }
    };
    vector<vi> loss(n);
    int p=0,q=0;
    for(int i=0;i<n;i++){
        string temp;
        int l = 0;
        if(i){
            int sze = min(a[i].size(),a[i-1].size());
            for(int j=0;j<sze;j++){
                if(a[i][l]==a[i-1][l]){
                    loss[i].pb(loss[i-1][l]);
                    temp.pb(a[i][l]);
                    ++l;
                } else break;
            }
        }
        for(int j=l;j<a[i].size();j++){
            temp.pb(a[i][j]);
            while(p<n-1){
                if(temp<b[p]) break;
                if(iscommon(temp,b[p])) break;
                ++p;
            }
            while(q<n-1){
                if(iscommon(temp,b[q+1])){
                    ++q;
                } else if(temp<b[q+1]){
                    break;
                }
            }
            cout << "range for " << temp << " is " << p << " to " << q << "\n";
            int gross = 0;
            if(iscommon(temp,b[p]) && iscommon(temp,b[q])){
                gross = q-p+1;
                cout << "taken!\n";
            }
            loss[i].pb(gross);
            //cout << "done\n";
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int x : loss[i]){
            ans+=x;
        }
    }
    cout << 2*(n*tot-ans) << "\n";
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    solve();
    return 0;
}
