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
    int n,a,b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int x = 0, y = 0;
    set<pii> z;
    bool win = false;
    for(int i=0;i<n;i++){
        if(s[i]=='N'){
            y++;
        }
        if(s[i]=='S'){
            y--;
        }
        if(s[i]=='E'){
            x++;
        }
        if(s[i]=='W'){
            x--;
        }
        z.insert({x,y});
        if(x==a && b==y){
            win = true;
        }
    }
    int q = 100;
    while(q--){
        a-=x;
        b-=y;
        if(z.find({a,b})!=z.end()){
            win = true;
        }
    }
    if(win){
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
