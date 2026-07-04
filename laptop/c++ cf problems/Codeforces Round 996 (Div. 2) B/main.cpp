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
    int n;
    cin >> n;
    vi a(n),b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    int index = -1;
    int mn = LLONG_MAX;
    for(int i=0;i<n;i++){
        if(a[i]>=b[i]){
            mn = min(mn,a[i]-b[i]);
        } else{
            if(index==-1){
                index = i;
            } else{
                cout << "NO\n";
                return;
            }
        }
    }
    if(index==-1 || b[index]-a[index]<=mn){
        cout << "YES\n";
    } else{
        cout << "NO\n";
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
