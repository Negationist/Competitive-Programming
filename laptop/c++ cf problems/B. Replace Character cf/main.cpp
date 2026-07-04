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
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char,int> m;
    char high;
    int most = -1;
    for(int i=0;i<n;i++){
        m[s[i]]++;
        if(m[s[i]]>most){
            most = m[s[i]];
            high = s[i];
        }
    }
    if(m.size()==1){
        cout << s << "\n";
    } else{
        int mn = LLONG_MAX;
        char low;
        for(auto x : m){
            if(x.ss<mn && x.ff!=high){
                mn = x.ss;
                low = x.ff;
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]==low){
                s[i] = high;
                break;
            }
        }
        cout << s << "\n";
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
