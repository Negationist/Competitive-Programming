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
const int lo = -1e10;
void solve(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi a(n);
    int first = LLONG_MAX;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(s[i]=='0'){
            first = min(first,i);
            a[i] = lo;
        }
    }
    int sum = 0;
    int mx = 0;
    for(int i=0;i<n;i++){
        if(sum>0){
            sum+=a[i];
        } else{
            sum = a[i];
        }
        mx = max(mx,sum);
    }
    if(mx>k){
        cout << "No\n";
    } else if(mx==k){
        cout << "Yes\n";
        for(int x : a){
            cout << x << " ";
        }
        cout << "\n";
    } else{
        if(first==LLONG_MAX){
            cout << "No\n";
        } else{
            int mx_after = 0, mx_before = 0;
            sum = 0;
            for(int i=first+1;i<n;i++){
                sum+=a[i];
                mx_after = max(mx_after,sum);
            }
            sum = 0;
            for(int i=first-1;i>=0;i--){
                sum+=a[i];
                mx_before = max(mx_before,sum);
            }
            a[first] = k-mx_before-mx_after;
            cout << "Yes\n";
    for(int x : a){
                cout << x << " ";
            }
            cout << "\n";
        }
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
