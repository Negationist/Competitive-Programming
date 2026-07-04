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
    int n,x;
    cin >> n >> x;
    set<int> s;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        while(true){
            if(s.find(a)==s.end()){
                s.insert(a);
                break;
            } else{
                a+=x;
            }
        }
    }
    for(int i=0;i<LLONG_MAX;i++){
        if(s.find(i) ==  s.end()){
            cout << i << endl;
            return;
        }
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
