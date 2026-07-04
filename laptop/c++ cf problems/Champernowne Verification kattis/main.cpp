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
    string s;
    cin >> s;
    int cur = 1;
    for(int i=0;i<s.size();i++){
        if(s[i]-'0'==cur){
            cur++;
        } else{
            cout << -1 << "\n";
            return;
        }
    }
    cout << cur-1 << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
