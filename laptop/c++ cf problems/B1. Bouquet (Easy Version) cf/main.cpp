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
    int n,m,ans=0;
    cin >> n >> m;
    unordered_map<int,int> m1;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        m1[a]++;
    }
    for(auto it = m1.begin();it!=m1.end();it++){
        int total = 0;
        int current = it->first;
        int money = m;
        int num1 = min(it->second,money/current);
        for(int i=1;i<=num1;i++){
            total=(i * current);
            int moneyCurrent = money - (i*current);
            if(m1.find(current+1) != m1.end()){
                int num2 = min(m1[current+1], moneyCurrent/(current+1));
                total+=(num2 * (current+1));
                ans = max(ans,total);
            } else{
                ans = max(ans,total);
            }
        }
    }
    cout << ans << endl;
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
