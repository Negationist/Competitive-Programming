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
    int x;
    cin >> x;
    int a[32] = {0};
    int b[32] = {0};
    for(int i=0;i<32;i++){
        if(1<<i & x){
            a[i] = 1;
        } else if(i>0){
            if(arr[i-1]==0){
                b[i] = 1;
                b[i-1] = 1;
            }
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
