//solved in 13, overthinking for 10
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
    int n,x;
    cin >> n >> x;
    vi a(n);
    int index;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i]==x){
            index = i;
        }
    }
    int l=0,r=n;
    while(r-l>1){
        int mid = l +(r-l)/2;
        if(a[mid]<=x){
            l = mid;
        } else{
            r = mid;
        }
    }
    if(a[l]==x){
        cout << 0 << "\n";
    } else{
        cout << 1 << "\n";
        cout << index+1 << " " << l+1 << "\n";
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
