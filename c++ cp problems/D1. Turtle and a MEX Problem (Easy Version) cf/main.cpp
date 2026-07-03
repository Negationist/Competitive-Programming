//saving for later lol
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
    int n,m,ans=0;
    cin >> n >> m;
    int mx = 0;
    for(int i=0;i<n;i++){
        int l;
        cin >> l;
        set<int> s;
        for(int j=0;j<l;j++){
            int a;
            cin >> a;
            s.insert(a);
        }
        int cur = 0;
        for(int j=0;j<l+4;j++){
            if(s.find(j) == s.end() ){
                if(cur>0){
                    mx = max(mx,j);
                    break;
                } else{
                    cur++;
                }
            }
        }
    }
    if(mx >= m){
        ans = (m+1)*mx;
    } else{
       ans = (mx*mx) + (mx+m)*(m-mx+1)/2;
    }
    cout << ans << "\n";
}

signed main()
{
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
