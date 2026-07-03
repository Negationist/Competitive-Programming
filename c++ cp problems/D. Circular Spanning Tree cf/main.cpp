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
    int cnt = 0;
    int mark;
    for(int i=0;i<n;i++){
       if(s[i]=='1'){
            cnt++;
       }
       if(s[(i-1+n)%n]=='1'){
            mark = i;
       }
    }
    if(cnt%2==1 || n-cnt>n-1){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vii edges;
    int cur = mark;
    bool in = false;
    for(int i=1;i<n;i++){
        int temp = (mark+i)%n;
        if(s[temp]=='1'){
            if(in){
                edges.pb({cur,temp});
                cur =  mark;
                in = false;
            } else{
                edges.pb({mark,temp});
            }
        } else{
            edges.pb({cur,temp});
            cur = temp;
            in = true;
        }
    }
    for(auto x : edges){
        cout << x.ff+1 << " " << x.ss+1 << "\n";
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
