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
    vi a(n);
    vi ans(n);
    map<int,set<int>> m;
    for(int i=0;i<n;i++){
        ans[i] = 1;
        cin >> a[i];
        m[a[i]].insert(i);
    }
    int sum = 0;
    for(auto it = m.begin();it!=m.end();it++){
        if(sum==2) break;
        if(it->second.size()>=2){
            sum++;
            ans[*(it->second.begin())] = sum+1;
        }
    }
    if(sum==2){
        for(int x : ans){
            cout << x << " ";
        }
        cout << "\n";
    } else{
        cout << "-1\n";
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
