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
    string s;
    cin >> s;
    bool is = false;
    for(int i=0;i<2*n-1;i++){
        if(s[i]=='W'){
            is = true;
        }
    }
    cout << is << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
