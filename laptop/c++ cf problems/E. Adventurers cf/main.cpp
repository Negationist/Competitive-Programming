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
    map<int,int> x;
    map<int,int> y;
    vii p(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        x[a]++;
        y[b]++;
        p[i] = {a,b};
    }
    pii ans;
    int sum = 0;
    int bestX;
    int mn = LLONG_MAX;
    for(auto z : x){
        sum+=z.ss;
        if(abs(n-sum)<mn){
            mn = abs(n-sum);
            bestX = z.ff;
        }
    }
    sum = 0;
    int bestY;
    mn = LLONG_MAX;
    for(auto z : y){
        sum+=z.ss;
        if(abs(n-sum)<mn){
            mn = abs(n-sum);
            bestY = z.ff;
        }
    }
    int a=0,b=0,c=0,d=0
    ;
    for(auto z : p){
        int l = z.ff, r=z.ss;
        if(l<=bestX){
            if(r<=bestY){
                a++;
            } else{
                b++;
            }
        } else{
            if(r<=bestY){
                c++;
            } else{
                d++;
            }
        }
    }
    int che = min(a,min(b,min(c,d)));
    cout << che << "\n";
    cout << bestX << " " << bestY << "\n";
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
