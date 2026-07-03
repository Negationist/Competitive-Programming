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
    string s;
    cin >> n >> s;
    string all[3] = {"pie","map","mapie"};
    int ans = 0;
    for(int i=0;i<n-2;i++){
        if(s.substr(i,3)==all[0]){
            ans++;
        }
    }
    for(int i=0;i<n-2;i++){
        if(s.substr(i,3)==all[1]){
            ans++;
        }
    }
    for(int i=0;i<n-4;i++){
        if(s.substr(i,5)==all[2]){
            ans--;
        }
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
