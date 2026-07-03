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
    int n,m,d;
    cin >> n >> m >> d;
    int mn = 1+(n-1)/d;
    vi a;
    a.pb(1);
    int num = 0;
    for(int i=0;i<m;i++){
        int z;
        cin >> z;
        if(i==0){
            num+=(z!=1);
        }
        a.pb(z);
    }
    a.pb(n+1);
    bool done = false;
    for(int i=0;i<a.size()-2;i++){
        int aToc = (a[2] - a[0]-1)/d;
        int aTob = (a[1] - a[0]-1)/d;
        int bToc = (a[2] - a[1]-1)/d;
        if(aToc < aTob+bToc+1 && !done){
            done = true;
            num+=(aToc);
            i++;
        } else{
            num+=(aTob);
            if(i==a.size()-2){
                num+=bToc;
            }
        }
    }
    num+=(m-1);
    cout << "num is " << num-done << "\n";
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
