#include <bits/stdc++.h>
#define int long long
#define ld long double
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
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int ans = n*(n+1)/2;
    for(int i=1;i<=10;i++){
        stack<int> q;
        map<int,int> m;
        //cout << i << "!\n";
        int sum = 0;
        q.push(0);
        for(int j=0;j<n;j++){
            if(a[j]<=i){
                ++sum;
            } else{
                --sum;
            }
            if(a[j]==i){

                while(q.size()){
                    ++m[q.top()];
                    q.pop();
                }
            }
            q.push(sum);
            ans-=m[sum];
            //cout << "-" << m[sum] << "\n";
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
