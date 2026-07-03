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
    int n,ans=1;
    cin >> n;
    set<int> s;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        s.insert(a);
    }
    int a[s.size()];
    copy(s.begin(),s.end(),a);
    int l=0,r=0;
    while(true){
        if(a[r]-a[l]<n){
            ans = max(ans, r-l+1);
            r++;
            if(r>=s.size()) break;
        } else{
            l++;
        }
    }
    cout << ans << "\n";
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
