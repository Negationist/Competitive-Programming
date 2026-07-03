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
    int index = -1;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(i && index==-1 && a[i]!=1){
            index = i;
        }
    }
    int next = 1;
    int ans;
    if(n==k){
        bool fail = false;
        for(int i=1;i<n;i+=2){
            if(a[i]==next && !fail){
                ++next;
            } else{
               fail = true;
            }
        }
        cout << next << "\n";
    } else{
        if(index!=-1 && n-index-1>=k-2){ //can we make the split at the first non 1
            ans = 1;
        } else{ //there must be at least 3 ones then
            ans = 2;
        }
        cout << ans << "\n";
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
