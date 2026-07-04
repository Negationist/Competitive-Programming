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
    int a[n],b[n],mad=0;
    set<int> s;
    int sum=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(s.find(a[i]) != s.end()){
           mad = max(mad,a[i]);
        } else{
            s.insert(a[i]);
        }
        b[i] = mad;
        sum+=a[i];
    }
    s.clear();
    int c[n];
    mad = 0;
    for(int i=0;i<n;i++){
        sum+=b[i];
        if(s.find(b[i]) != s.end()){
           mad = max(mad, b[i]);
        } else{
            s.insert(b[i]);
        }
        c[i] = mad;
    }
    for(int i=0;i<n;i++){
        sum+=(c[i]*(n-i));
    }
    cout << sum << "\n";
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
