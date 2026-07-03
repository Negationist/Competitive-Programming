#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
using ld = long double;
void solve(){
    int n;
    cin >> n;
    vi a(n),d(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        --a[i];
    }
    int num = 0;
    for(int i=0;i<n;i++){
        cin >> d[i];
        --d[i];
        if(a[d[i]]==-1){
            cout << num << " ";
        } else{
            int cur = d[i];
            while(a[cur]!=-1){
                //cout << "at " << cur << " going to " << a[cur] << "\n";
                ++num;
                int next = a[cur];
                a[cur] = -1;
                cur = next;
            }
            cout << num << " ";
        }
    }
    cout << "\n";
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
