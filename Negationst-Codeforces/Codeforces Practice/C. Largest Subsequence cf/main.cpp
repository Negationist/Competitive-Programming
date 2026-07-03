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
    string s;
    cin >> s;
    vector<char> a;
    vi pos;
    char mx[n];
    mx[n-1] = s[n-1];
    for(int i=n-2;i>=0;i--){
        mx[i] = max(mx[i+1], s[i]);
    }
    int overcount = 0;
    for(int i=0;i<n;i++){
        if(mx[i]==s[i]){
            a.pb(s[i]);
            pos.pb(i);
        }
        if(a.size()<2) continue;
        if(s[i]==*a.begin()) overcount++;
    }
    for(int i=0;i<a.size();i++){
        s[pos[i]] = a[a.size()-1-i];
    }
    for(int i=1;i<n;i++){
        if(s[i] < s[i-1]){
            cout << -1 << endl;
            return;
        }
    }
    cout << a.size()-1-overcount << endl;
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
