#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

const int maxN = 1e6+5;

void solve(){
    int n;
    cin >> n;
    vector<int> cnt(maxN,0);
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        cnt[z]++;
    }
    int ans = 1;
    for(int i=maxN;i>=2;i--){
        int num = 0;
        for(int j=i;j<=maxN;j+=i){
            num+=cnt[j];
        }
        if(num>1){
            ans = i;
            break;
        }
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
