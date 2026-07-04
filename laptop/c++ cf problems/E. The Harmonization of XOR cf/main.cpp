#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;

void solve(){
    int n,k,x;
    cin >> n >> k >> x;
    vector<vi> ans;
    vi xtra;
    int base = 0;
    for(int i=1;i<=n;i++){
        base^=i;
        if(i==x) continue;
        int j = i^x;
        if(i<j && j<=n){
            vi temp = {i,j};
            ans.pb(temp);
        } else if(j>n){
            xtra.pb(i);
        }
    }
    if(ans.size()+(x<=n)<k){
        cout << "NO\n";
        return;
    } else if(k%2==0 && base!=0){
        cout << "NO\n";
        return;
    } else if(k%2==1 && base!=x){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int inc = 0;
    if(x<=n && k>1){
        cout << 1 << " " << x << "\n";
        ++inc;
    } else if(x<=n){
        xtra.pb(x);
    }
    for(int i=0;i<ans.size();i++){
        if(inc<k-1){
            cout << 2 << " " << ans[i][0] << " " << ans[i][1] << "\n";
        } else{
            xtra.pb(ans[i][0]);
            xtra.pb(ans[i][1]);
        }
        ++inc;
    }
    cout << xtra.size() << " ";
    for(int x : xtra){
        cout << x << " ";
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
