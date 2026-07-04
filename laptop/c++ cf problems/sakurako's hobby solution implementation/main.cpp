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
    int b[n];
    int F[n];
    int used[n] = {0};
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        b[i] = a-1;
    }
    string s;
    cin >> s;
    for(int i=0;i<n;i++){
        if(used[i]==1) continue;
        int sz = 0;
        while(!used[i]){
            sz+=(s[i]=='0');
            used[i] = 1;
            i = b[i];
        }
        while(used[i]!=2){
            used[i] = 2;
            F[i] = sz;
            i = b[i];
        }
    }
    for(int x : F){
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
