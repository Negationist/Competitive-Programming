#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

const int s = 1e5+1;

int memo[s] = {};

int totient(int n){
    int res = n;
    int og = n;
    if(memo[n]!=0) return memo[n];
    set<int> factors;
    for(int i=2;i<=sqrtl(n);i++){
        while(n%i==0){
            factors.insert(i);
            n/=i;
        }
    }
    if(n>1){
        factors.insert(n);
    }
    for(int x : factors){
        res*=(x-1);
        res/=x;
    }
    memo[og] = res;
    return res;
}


void solve(){
    int n,ans=0;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    map<int,int> m;
    for(int i=0;i<n;i++){
        for(int j=1;j<=sqrtl(a[i]);j++){
            if(a[i]%j==0){
                ans+=(m[j]*(n-i-1)*totient(j));
                m[j]++;
                if(j==sqrtl(a[i])) break;
                ans+=(m[a[i]/j])*(n-i-1)*totient(a[i]/j);
                m[a[i]/j]++;
            }
        }
    }
    cout << ans <<"\n";
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
