#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;

void solve(){
    int k;
    cin >> k;
    priority_queue<int> q;
    vector<int> cnt(30,0;)
    for(int i=0;i<k;i++){
        int z;
        cin >> z;
        q.push(z);
        for(int j=0;j<z-1;j++){
            int a;
            cin >> a;
        }
    }
    vector<int> cnt(30,0);
    while(q.top()!=0){
        int z = q.top();
        q.pop();
        int msb = 31-__builtin_clz(z);
        cnt[msb]++;
        q.push(z-(1LL<<msb));
    }
    int ans = 0;
    for(int i=29;i>=0;i--){
        if(cnt[i]){
            if(i!=0)cnt[i-1]+=(2*(cnt[i]-1));
            ans+=(1LL<<i);
        }
    }
    cout << ans << "\n";
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
