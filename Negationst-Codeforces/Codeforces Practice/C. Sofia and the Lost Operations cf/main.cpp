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
    int a[n],b[n];
    map<int,int> m1;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    set<int> needed;
    for(int i=0;i<n;i++){
        cin >> b[i];
        needed.insert(b[i]);
        if(a[i] != b[i]) m1[b[i]]++;
    }
    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        int z;
        cin >> z;
        m1[z]--;
        if(i==m-1){
            if(needed.find(z)==needed.end()){
                cout << "NO\n";
                return;
            }
        }
    }
    for(auto it = m1.begin(); it!=m1.end();it++){
        if(it->second > 0){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
