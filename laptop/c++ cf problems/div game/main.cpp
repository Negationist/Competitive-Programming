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
    int ans = 0;
    map<int,int> cnt;
    for(int i=2;i<=sqrtl(n);i++){
        while(n%i==0){
            n/=i;
            cnt[i]++;
        }
    }
    if(n>1) cnt[n]++;
    for(auto x : cnt){
        int num = x.ss;
        int inc = 1;
        while(num>=inc){
            ans++;
            num-=inc;
            inc++;
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
