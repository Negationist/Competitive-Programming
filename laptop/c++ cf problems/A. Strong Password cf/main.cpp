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
    int index = s.size();
    char ins = 'a' + (s[s.size()-1]-'a'+1)%26;
    for(int i=1;i<s.size();i++){
        if(s[i] == s[i-1]){
            index = i;
            ins = 'a' + (s[i]-'a'+1)%26;
            break;
        }
    }
    for(int i=0;i<index;i++){
        cout << s[i];
    }
    cout << ins;
    for(int i=index; i<s.size();i++){
        cout << s[i];
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
