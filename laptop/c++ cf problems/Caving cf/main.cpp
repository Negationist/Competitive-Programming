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
    vii a;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            int sum = 0;
            for(int j=i+1;j<s.size();j++){
                if(s[j]=='('){
                   sum++;
                } else if(s[j]==')' && sum==0){
                    a.pb({i,j});
                } else if(s[j]==')'){
                    sum--;
                }
            }
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
