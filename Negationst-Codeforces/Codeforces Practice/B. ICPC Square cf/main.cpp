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
int sieve[maxN] = {};

void compute(){
    for(int i=2;i<maxN;i++) sieve[i] = i;
    for(int i=2;i<maxN;i++){
        if(sieve[i]==i){
            for(int j=i;j<maxN;j+=i){
                sieve[j] = i;
            }
        }
    }
}

void solve(){
    int n,d,s;
    cin >> n >> d >> s;
    int ans = s;
    for(int i=2;i<=1e6;i++){
        if(sieve[i]!=i) continue;
        int cur = s*i;
        if(s*i>n) continue;
        int l = 1, r=(n/cur);
        while(l<=r){
            int mid = l+(r-l)/2;
            int last = mid*cur;
            int jump = last*(i-1)/i;
            if(jump<=d){
                ans = max(ans,last);
                l = mid+1;
            } else{
                r = mid-1;
            }
        }
    }
    //no intermediate jumps
    int res = min(n/s,d/s+1);
    ans = max(ans,res*s);
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    compute();
    solve();
    return 0;
}
