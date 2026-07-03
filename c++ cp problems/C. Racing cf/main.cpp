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
using ld = long double;
void solve(){
    int n;
    cin >> n;
    vi d(n),l(n),r(n);
    for(int i=0;i<n;i++) cin >> d[i];
    for(int i=0;i<n;i++){
        cin >> l[i] >> r[i];
    }
    set<int> cands;
    int h = 0;
    for(int i=0;i<n;i++){
        if(d[i]==1){
            ++h;
        } else if(d[i]==-1){
            cands.insert(i);
        }
        while(h<l[i] && cands.size()){
            int cur = *cands.rbegin();
            d[cur] = 1;
            cands.erase(cur);
            ++h;
        }
        if(h<l[i]){
            cout << -1 << "\n";
            return;
        }
    }
    for(int i=0;i<n;i++){
        if(d[i]==-1){
            d[i] = 0;
        }
        //cout << d[i] << " ";
    }
    //cout << "!\n";
    vi height(n);
    h = 0;
    for(int i=0;i<n;i++){
        h+=d[i];
        if(h<=r[i]){
            height[i] = h;
        } else{
            cout << -1 << "\n";
            return;
        }
    }
    for(int x : d){
        cout << x << " ";
    }
    cout << "\n";
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
