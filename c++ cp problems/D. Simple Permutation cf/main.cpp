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
void solve(){
    int n;
    cin >> n;
    if(n<6){
        for(int i=1;i<=n;i++){
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    int prime = n/3-1;
    while(true){
        bool flag = true;
        for(int i=2;i<=sqrtl(prime);i++){
            if(prime%i==0){
                flag = false;
                break;
            }
        }
        if(flag){
            break;
        }
        ++prime;
    }
    int l = prime, r = prime+1;
    int cur = 1;
    while(l>=1 || r<=n){
        if(l<=0){
            cout << r << " ";
            ++r;
        } else if(r>n){
            cout << l << " ";
            --l;
        } else{
            if(cur){
                cout << l << " ";
                --l;
            } else{
                cout << r << " ";
                ++r;
            }
        }
        cur = 1-cur;
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
