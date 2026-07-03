#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

void solve(){
    int n;
    cin >> n;
    vi a(n+1),b(n+1,0),pref(n+1,0);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        pref[i] = pref[i-1]+a[i];
    }
    if(pref[n]&1){
        cout << -1 << "\n";
        return;
    }
    int i = 1, j = n;
    while(i<j){
        int x = min(a[i],a[j]);
        b[i]+=x;
        b[j]+=x;
        a[i]-=x;
        a[j]-=x;
        if(!a[i]){
            ++i;
        }
        if(!a[j]){
            --j;
        }
    }
    int y = b[i]+a[i];
    if(i>j){
        cout << 1 << "\n";
        for(int i=1;i<=n;i++){
            cout << b[i] << " ";
        }
        cout << "\n";
    } else{
        int x = pref[i-1], z = pref[n]-pref[i], need = a[i]/2;
        if(x+z<y){
            cout << -1 << "\n";
            return;
        }
        if(x<=z){
           for(int k=1;k<=n;k++){
                if(b[k]<need){
                    a[k]+=b[k];
                    a[i]-=b[k];
                    b[i]+=b[k];
                    need-=b[k];
                    b[k] = 0;
                } else{
                    a[k]+=need;
                    a[i]-=need;
                    b[i]+=need;
                    b[k]-=need;
                    break;
                }
           } 
        } else{
            for(int k=n;k>=1;k--){
                if(b[k]<need){
                    a[k]+=b[k];
                    a[i]-=b[k];
                    b[i]+=b[k];
                    need-=b[k];
                    b[k] = 0;
                } else{
                    a[k]+=need;
                    a[i]-=need;
                    b[i]+=need;
                    b[k]-=need;
                    break;
                }
           }
        }
        cout << 2 << "\n";
        for(int i=1;i<=n;i++){
            cout << b[i] << " ";
        }
        cout << "\n";
        for(int i=1;i<=n;i++){
            cout << a[i] << " ";
        }
        cout << "\n";
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