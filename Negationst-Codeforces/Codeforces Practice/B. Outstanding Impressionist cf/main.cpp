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
    vii a(n);
    vi must(2*n+5,0);
    map<int,int> cnt;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        a[i] = {x,y};
        if(x==y){
            must[x] = 1;
            cnt[x]++;
        }
    }
    vi pref(2*n+5);
    pref[0] = 0;
    for(int i=1;i<2*n+5;i++){
        pref[i] = pref[i-1]+must[i];
    }
    for(int i=0;i<n;i++){
        int x = a[i].ff, y=a[i].ss;
        if(x!=y){
            int res = pref[y]-pref[x-1];
            if(res<y-x+1){
                cout << 1;
            } else{
                cout << 0;
            }
        } else{
            if(cnt[x]==1){
                cout << 1;
            } else{
                cout << 0;
            }
        }
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
