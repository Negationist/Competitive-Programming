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
    map<int,int> m;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        m[z]++;
    }
    int cnt = n-2;
    for(int i=1;i<=sqrtl(cnt);i++){
        if(cnt%i!=0) continue;
        if(i*i==cnt){
            if(m[i]>=2){
                cout << i << " " << i << "\n";
                return;
            }
        } else{
            if(m[i]!=0 && m[cnt/i]!=0){
                cout << i << " " << cnt/i << "\n";
                return;
            }
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
