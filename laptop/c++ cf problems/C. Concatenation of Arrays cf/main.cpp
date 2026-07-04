#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<pair<pii,bool>>z(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        if(a<=b){
            z[i] = {{a,b},true};
        } else{
            z[i] = {{b,a},false};
        }
    }
    sort(z.begin(),z.end(),[](pair<pii,bool>&a, pair<pii,bool>&b){
        if(a.first.first != b.first.first){
            return a.first.first < b.first.first;
        }
        if(a.first.second != b.first.second){
            return a.first.second < b.first.second;
        }
        return a.second<b.second;
    });
    for(auto x : z){
        if(x.second){
            cout << x.first.first << " " << x.first.second << " ";
        } else{
            cout << x.first.second << " " << x.first.first << " ";
        }
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
