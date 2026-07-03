#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int dp[200005] = {0};
int pref[200005] = {0};

void computeDP(){
dp[0] = 0;
for(int i = 1;i<=200000;i++){
        int current = i/3;
        dp[i] = 1 + dp[current];
    }
}
void computepref(){
pref[0] = 0;
for(int i = 1;i<=200000;i++){
        pref[i] = pref[i-1]+dp[i];
    }
}

void solve(){
    int l,r;
    long long ans;
    cin >> l >> r;
    ans = pref[r]-pref[l-1]+dp[l];
    cout << ans << endl;
}

int main()
{
    computeDP();
    computepref();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
