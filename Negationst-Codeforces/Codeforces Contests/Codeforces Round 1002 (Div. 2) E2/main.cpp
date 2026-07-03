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
    set<int> s1,s2;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        s1.insert(z);
    }
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        s2.insert(z);
    }
    int x = min(s1.size(),s2.size());
    int y = max(s1.size(),s2.size());
    if(x>=2){
        cout << "YES\n";
    } else{
        if(y>=3){
            cout << "YES\n";
        } else{
            cout << "NO\n";
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
