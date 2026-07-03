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
    int n,k,ans=0;
    cin >> n >> k;
    if(k==1){
        cout << n << endl;
        return;
    }
    while(n>0){
        if(n>=k){
            int take = k;
            while(true){
                if(take*k<=n){
                    take*=k;
                } else{
                    break;
                }
            }
            n-=take;
            ans++;
        }
        else{
            ans+=(n%k);
            break;
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
