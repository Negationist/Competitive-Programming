#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
//sexy implementation, thanks

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> val (3, vector<int>(n+1,0));
    vector<vector<int>> pref (3, vector<int>(n+1,0));
    for(int i=0;i<3;i++){
        for(int j=1;j<n+1;j++){
            cin >> val[i][j];
            pref[i][j] = pref[i][j-1]+val[i][j];
        }
    }
    int goal = (pref[0][n]+2)/3;
    vi perm = {0,1,2};
    for(int i=0;i<6;i++){
        int cur = 0;
        while(pref[perm[0]][cur]<goal) cur++;
        for(int j=cur+1;j<n;j++){
            if(pref[perm[1]][j]-pref[perm[1]][cur] >= goal && pref[perm[2]][n]-pref[perm[2]][j]>=goal){
                vii ans(3);
                ans[perm[0]] = {1, cur};
                ans[perm[1]] = {cur+1, j};
                ans[perm[2]] = {j+1, n};
                for(auto x : ans){
                    cout << x.first << " " << x.second << " ";
                }
                cout << "\n";
                return;
            }
        }
        next_permutation(perm.begin(),perm.end());
    }
    cout << "-1\n";
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
