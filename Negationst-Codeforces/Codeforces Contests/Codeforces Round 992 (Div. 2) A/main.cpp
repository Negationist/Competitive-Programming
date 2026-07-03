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
    int n,k;
    cin >> n >> k;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        bool good = true;
        for(int j=0;j<n;j++){
            if(i==j) continue;
            else{
                if(abs(a[i]-a[j])%k==0){
                    good = false;
                }
            }
        }
        if(good){
            cout << "yes\n" << i+1 << "\n";
            return;
        }
    }
    cout << "no\n";
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
