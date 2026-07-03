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
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    bool win = true;
    for(int i=0;i<n;i++){
        int d1 = i, d2 = n-1-i;
        if(d1*2>=a[i] || d2*2>=a[i]){
            win = false;
        }
    }
    cout << (win?"YES":"NO") << "\n";
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
