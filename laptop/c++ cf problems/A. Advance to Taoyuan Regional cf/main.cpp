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
    string a,b,c;
    a = s.substr(0,4);
    b = s.substr(5,2);
    c = s.substr(8,2);
    tuple<int,int,int> x = {stoi(a),stoi(b),stoi(c)};
    tuple<int,int,int> y = {2023,9,17};
    vector<tuple<int,int,int>> z;
    z.pb(x);
    z.pb(y);
    sort(z.begin(),z.end());
    if(z[0]!=y){
        cout << "GOOD\n";
    } else{
        cout << "TOO LATE\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
