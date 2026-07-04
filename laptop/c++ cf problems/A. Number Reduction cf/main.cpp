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
    vi pow(19);
    pow[0] = 1;
    for(int i=1;i<19;i++){
        pow[i] = pow[i-1]*10;
    }
    int n;
    cin >> n;
    int x,y,z,m;
    int ans = 1;
    map<int,bool> seen;
    seen[1] = true;
    x=1;
    for(int i=0;i<=59;i++){
        if(i){
            x*=2;
        }
        y=1;
        z=1;
        m=1;
        for(int j=0;j<=37;j++){
            if(j){
                y*=3;
            }
            z=1;
            m=1;
            for(int k=0;k<=25;k++){
                if(k){
                    z*=5;
                }
                m=1;
                for(int l=0;l<=21;l++){
                    if(l){
                        m*=7;
                    }
                    //cout << x << " " << y << " " << z << " " << m << "\n";
                    bool good = true;
                    int res = x;
                    int mx1 = n/y;
                    if(res<=mx1){
                        res*=y;
                    } else{
                        good = false;
                    }
                    int mx2 = n/z;
                    if(res<=mx2){
                        res*=z;
                    } else{
                        good = false;
                    }
                    int mx3 = n/m;
                    if(res<=mx3){
                        res*=m;
                    } else{
                        good = false;
                    }
                    int inc = 0;
                    if(res==1 || !good) continue;
                    while(res/pow[inc]>0){
                        int z = (res/pow[inc])%10;
                        if(z>1 && res%z==0){
                            seen[res]|=seen[res/z];
                        }
                        ++inc;
                    }
                    ans+=seen[res];
                }
            }
        }
    }
    cout << ans << "\n";
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    solve();
    return 0;
}
