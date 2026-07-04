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
    n*=2;
    string s;
    cin >> s;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            ++cnt;
        }
    }
    if(cnt%2==1){
        cout << -1 << "\n";
        return;
    }
    char last = '0';
    vi ops;
    for(int i=0;i+1<n;i+=2){
        if(s[i]==s[i+1]){
            continue;
        }
        if(last=='0'){
            if(s[i]=='1'){
                ops.pb(i);
            } else{
                ops.pb(i+1);
            }
            last = '1';
        } else{
            if(s[i]=='0'){
                ops.pb(i);
            } else{
                ops.pb(i+1);
            }
            last = '0';
        }
    }
    cout << ops.size() << " ";
    for(int x : ops){
        cout << x+1 << " ";
    }
    cout << "\n";
    for(int i=0;i+1<n;i+=2){
        cout << i+1 << " \n"[i+1==n-1];
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
