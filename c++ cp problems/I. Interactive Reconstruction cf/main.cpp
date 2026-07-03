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

const int maxB = 14;

void solve(){
    int n;
    cin >> n;
    int ans[maxB+1][n];
    for(int i=0;i<=maxB;i++){
        cout << "QUERY ";
        for(int j=0;j<n;j++){
            cout << (j&(1<<i)?1:0);
        }
        cout << endl;
        for(int j=0;j<n;j++){
            cin >> ans[i][j];
        }
    }
    int val[n];
    cout << "QUERY ";
    for(int j=0;j<n;j++){
        cout << 1;
    }
    cout << endl;
    set<int> leaves;
    for(int j=0;j<n;j++){
        cin >> val[j];
        if(val[j]==1){
            leaves.insert(j);
        }
    }
    cout << "ANSWER\n";
    int inc = 0;
    while(leaves.size() && ++inc<n){
        int x = *leaves.begin();
        leaves.erase(x);
        int p = 0;
        for(int i=0;i<=maxB;i++){
            if(ans[i][x]){
                p+=(1<<i);
            }
        }
        cout << x+1 << " " << p+1 << endl;
        for(int i=0;i<=maxB;i++){
            if(x&(1<<i)){
                ans[i][p]-=1;
            }
        }
        if(--val[p]==1){
            leaves.insert(p);
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
