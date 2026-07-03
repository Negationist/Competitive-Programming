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
    map<int,int>m;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        m[a]++;
    }
    if(m.size()<3){
        if(m.size()==1){
            cout << "Yes\n";
            return;
        }
        auto it = m.begin();
        int x = it->second;
        it++;
        int y = it->second;
        if(abs(x-y)<2){
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
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
