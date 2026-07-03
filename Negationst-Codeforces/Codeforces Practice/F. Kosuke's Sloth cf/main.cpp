#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
const int MOD = 1e9+7;
vector<int> memo;
int Fibonacci(int x,int k){
    if(memo[x]!=0) return memo[x];
    memo[x] = (Fibonacci(x-1,k)+Fibonacci(x-2,k))%k;
    return memo[x];
}

void solve(){
    int n,k;
    cin >> n >> k;
    n%=MOD;
    if(k==1){
        cout << (n*k)%MOD << "\n";
        return;
    }
    memo.assign(2*k+100, 0);
    memo[1] = memo[2] = 1;
    int index=3;
    while(Fibonacci(index,k)!=0){
        index++;
    }
    cout << (index*n)%MOD << "\n";
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
