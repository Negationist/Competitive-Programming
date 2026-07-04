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
    int n,k;
    cin >> n  >> k;
    string s;
    cin >> s;
    int mxL = LLONG_MAX, mxR = -1;
    for(int i=0;i+k<n;i++){
        if(s[i]==s[i+k]){
            mxL = i-k;
            break;
        }
    }
    for(int i=n-1;i-k>=0;i--){
        if(s[i]==s[i-k]){
            mxR = i-k+1;
            break;
        }
    }
    int num = min(mxL, n-1-mxR);
    for(int i=0;i<n;i++){
        if(i>=num){
            cout << -1 << "\n";
            return;
        }
    }
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
