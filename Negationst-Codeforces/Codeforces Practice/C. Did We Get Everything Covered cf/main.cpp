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
    int n,k,m;
    string s;
    cin >> n >> k >> m >> s;
    string out;
    int cnt[k] = {};
    int total = 0;
    for(int i=0;i<m;i++){
        bool good = true;
        if(s[i] < 'a'+k){
            cnt[s[i]-'a']++;
        }
        for(int j=0;j<k;j++){
            if(cnt[j]<1){
                good = false;
                break;
            }
        }
        if(!good) continue;
        out.pb(s[i]);
        for(int j=0;j<k;j++){
            cnt[j] = 0;
        }
        total++;
    }
    if(total>=n){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
    cout << out;
    for(int i=0;i<k;i++){
        if(cnt[i]==0){
            for(int j=0;j<n-out.size();j++){
                cout << (char)('a'+i);
            }
            cout << "\n";
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
