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
ld eps = 1e-9;

void solve(){
    int n;
    cin >> n;
    vector<ld> a(n);
    bool flag = false;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(i>0){
            if(a[i]==1 && a[i-1]>1){
                flag = true;
            }
        }
    }
    if(flag){
        cout << -1 << "\n";
        return;
    }
    for(int i=0;i<n;i++){
        a[i] = log(log(a[i]));
    }
    int ans = 0;
    for(int i=1;i<n;i++){
        ld need = a[i-1]-a[i];
        if(need>eps){
            int cnt = 1+(need-eps)/log(2);
            a[i]+=log(2)*cnt;
            ans+=(cnt);
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
