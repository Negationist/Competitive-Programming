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
    string s,r;
    cin >> n >> s >> r;
    int num1 = 0;
    int num2 = 0; //number of extra 1s
    for(int i=0;i<n;i++){
        num1+=(s[i]=='1'?1:-1);
    }
    for(int i=0;i<n-2;i++){
        num2+=(r[i]=='0'?1:-1);
    }
    if(num2-num1==0){
        cout << "YES\n";
    } else{
        cout << "NO\n";
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
