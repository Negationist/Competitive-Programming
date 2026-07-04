#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    //palindrome check
    int l=0, r=n-1;
    while(l<r){
        if(s[l]!=s[r]){
            cout << "YES\n1\n";
            cout << s << "\n";
            return;
        }
        l++;
        r--;
    }
    char first = s[0];
    bool good = false;
    for(int i=0;i<n-1;i++){
        if(s[i]!=first) good = true;
        if(s[i]!=first && s[i+1]!=first){
            cout << "YES\n2\n";
            cout << s.substr(0,i+1) << " " << s.substr(i+1,n-i-1) << "\n";
            return;
        }
    }
    if(!good){
        cout << "NO\n";
        return;
    }
    int cnt = 0;
    char next = '-';
    for(int i=0;i<n;i++){
        if(s[i]!=first && next=='-'){
            next = s[i];
            cnt++;
        } else if(s[i]!=first && s[i]!=next){
            cnt++;
        }
        if(cnt==2){
            cout << "YES\n2\n";
            cout << s.substr(0,i+2) << " " << s.substr(i+2, n-i+2);
            return;
        }
    }
    //finish later lol

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
