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
    vi a(n);
    bool win = false;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(i>0){
            if(a[i]<=a[i-1]){
                if(a[i]*2>a[i-1]){
                    win = true;
                }
            } else{
                if(a[i-1]*2>a[i]){
                    win = true;
                }
            }
        }
    }
    if(win){
        cout << "yes\n";
    } else{
        cout << "no\n";
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
