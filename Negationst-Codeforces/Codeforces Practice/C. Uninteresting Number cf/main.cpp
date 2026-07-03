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
    int sum = 0;
    int x = 0,y = 0;
    for(int i=0;i<s.size();i++){
        int z = s[i]-'0';
        sum+=z;
        if(z==2) x++;
        else if (z==3) y++;
    }
    int need = (9-(sum%9))%9;
    bool win = 0;
    for(int i=0;i<=min(x,9LL);i++){
        int start = 2*i;
        for(int i=0;i<=min(y,3LL);i++){
            if(start%9==need) win = true;
            start+=6;
        }
    }
    if(win){
        cout << "yes\n";
    } else{
        cout << "no\n";
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
