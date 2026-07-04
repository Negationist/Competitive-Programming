#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int GCD(int x, int y){
    if(y%x == 0){
        return x;
    }
    return GCD(y%x,x);
}

void solve(){
    bool good = true;
    int n,index;
    cin >> n;
    int a[n],b[n-1];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n-1;i++){
        b[i] = GCD(a[i],a[i+1]);
        if(i==0) continue;
        if(b[i]<b[i-1]){
            good = false;
            index = i;
            break;
        }
    }
    if(good){
        cout << "YES\n";
    } else{
        vector<int> x,y,z;
        for(int i=0;i<n;i++){
            if(i != index-1){
                x.pb(a[i]);
            }
            if(i != index){
                y.pb(a[i]);
            }
            if(i != index+1){
                z.pb(a[i]);
            }
        }
        int e[3][n-2];
        bool e0 = true, e1 = true, e2 = true;
        for(int i=0;i<n-2;i++){
            e[0][i] = GCD(x[i],x[i+1]);
            if(e[0][i]<e[0][i-1] && i>0) e0 = false;
            e[1][i] = GCD(y[i],y[i+1]);
            if(e[1][i]<e[1][i-1] && i>0) e1 = false;
            e[2][i] = GCD(z[i],z[i+1]);
            if(e[2][i]<e[2][i-1] && i>0) e2 = false;
        }
        if(e0 || e1 || e2){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
}

signed main()
{
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
