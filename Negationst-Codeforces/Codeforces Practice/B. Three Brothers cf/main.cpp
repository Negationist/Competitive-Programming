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
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    int a,b;
    cin >> a >> b;
    s.erase(a);
    s.erase(b);
    cout << *s.begin() << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
