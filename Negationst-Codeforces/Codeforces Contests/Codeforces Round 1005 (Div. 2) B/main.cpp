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
void solve(){
    int n;
    cin >> n;
    vi a(n);
    map<int,int> cnt;
    for(int i=0;i<n;i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    vi b(n);
    for(int i=0;i<n;i++){
        if(cnt[a[i]]==1){
            b[i] = 1;
        } else{
            b[i] = 0;
        }
    }
    int ans = 0;
    int sum = 0;
    int l=-1,r=-1;
    for(int i=0;i<n;i++){
        if(b[i]==0){
            if(sum>ans){
                l = i-sum;
                r = i-1;
                ans = sum;
            }
            sum = 0;
        } else{
            ++sum;
        }
    }
    if(sum>ans){
        l = n-sum;
        r = n-1;
        ans = sum;
    }
    if(l==-1){
        cout << "0\n";
    } else{
        cout << l+1 << " " << r+1 << "\n";
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
