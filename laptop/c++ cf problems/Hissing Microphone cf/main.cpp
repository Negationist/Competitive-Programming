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
    int n=s.size();
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1] && s[i]=='s'){
            cout << "hiss";
            return;
        }
    }
    cout << "no hiss";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
