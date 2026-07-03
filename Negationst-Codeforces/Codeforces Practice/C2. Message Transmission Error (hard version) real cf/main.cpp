#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

string check(string s){
    for(int i=1;i<s.size();i++){
        int num = 0;
        while(true){
            if(i+1 > s.size()-i) return string();
            if(s[num]==s[i+num]) num++;
            else break;
            if(i+num == s.size()) return s.substr(i,LLONG_MAX);
            else continue;
        }
    }
    return string();
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string t;
    cin >> t;
    string ans = check(t);
    if(ans.size()){
        cout << "YES\n" << ans;
    } else{
        cout << "NO\n";
    }
    return 0;
}
