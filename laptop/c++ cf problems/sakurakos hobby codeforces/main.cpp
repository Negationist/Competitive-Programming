#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

vector<int> a,b,c;

int F(set<int> s, int current){
    if (c[current] != -1){
        return c[current];
    }
    if(s.find(current) != s.end()){
        return 0;
    }
    s.insert(current);
    if(b[current]==0){
       c[current] = F(s,b[current]);
       return 1 + c[current];
    } else{
        c[current] = F(s,b[current]);
        return c[current];
    }
}

void solve(){
    int n;
    cin >> n;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    for(int i=0;i<n;i++){
        c[i] = -1;
    }
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        z--;
        a[i] = z;
    }
    string s;
    cin >> s;
    for(int i=0;i<n;i++){
        b[i] = s[i];
    }
    for(int i=0;i<n;i++){
        set<int> used;
        c[n] = F(used, n);
    }
    for(int x : c){
        cout << x << " ";
    }
    cout << "\n";
}

signed main()
{
    // ios::sync_with_stdio(0);
    //
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
