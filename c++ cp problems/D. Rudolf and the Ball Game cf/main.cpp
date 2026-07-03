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
    int n,m,x;
    cin >> n >> m >> x;
    vector<set<int>> s(2);
    int cur = 0;
    s[cur].insert(x%n);
    for(int i=0;i<m;i++){
        int a;
        char b;
        cin >> a >> b;
        for(int num : s[cur]){
           if(b=='0'){
                s[1-cur].insert((num+a+n)%n);
           } else if(b=='1'){
                s[1-cur].insert((num-a+n)%n);
           } else{
                s[1-cur].insert((num+a+n)%n);
                s[1-cur].insert((num-a+n)%n);
           }
        }
        s[cur].clear();
        cur = 1-cur;
    }
    if(s[cur].find(0LL)!=s[cur].end()){
        s[cur].erase(0);
        s[cur].insert(n);
    }
    cout << s[cur].size() << "\n";
    for(int x : s[cur]){
        cout << x << " ";
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
