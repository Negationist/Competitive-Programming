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
    int n,k,p;
    cin >> n >> k >> p;
    vector<vi> dp(k+1,vi(2));
    vector<vi> pref(k+1,vi(2));
    pref[0][0] = 0;
    pref[0][1] = 0;
    vector<vi> symdp(k+1,vi(2));
    vector<vi> sympref(k+1,vi(2));
    int cnt0;
    int symcnt0;
    for(int i=0;i<n;i++){
        vector<vi> npref(k+1,vi(2));
        npref[0][0] = 0;
        npref[0][1] = 0;
        vector<vi> nsympref(k+1,vi(2));
        nsympref[0][0] = 0;
        nsympref[0][1] = 0;
        vector<vi> ndp(k+1,vi(2));
        vector<vi> nsymdp(k+1,vi(2));
        int ncnt0 = 0;
        int nsymcnt0 = 0;
        for(int j=0;j<=k;j++){
            //cout << i << " " << j << "!\n";
            if(!i){
                ndp[j][0] = 1;
                nsymdp[j][0] = 0;
                if(j){
                    ndp[j][1] = 0;
                    nsymdp[j][1] = 0;
                } else{
                    ++ncnt0;
                }
            } else if(!j){
                int res = (pref[k][1]+cnt0)%p;
                ncnt0+=res;
                ncnt0%=p;
                int symres = (sympref[k][1]+symcnt0)%p;
                nsymcnt0+=symres;
                nsymcnt0%=p;
            } else{
                ndp[j][0] = pref[j-1][1]+dp[j][0]+cnt0;
                ndp[j][0]%=p;
                ndp[j][1] = dp[j][0];
                ndp[j][1]%=p;
                nsymdp[j][0] = sympref[j-1][1]+symdp[j][0]+symcnt0;
                nsymdp[j][0]%=p;
                nsymdp[j][1] = symdp[j][0];
                nsymdp[j][1]%=p;
            }
            if(i==n-1 && k){
                ndp[k][0] = 0;
                nsymdp[k][0] = 0;
            }
            if(j){
                npref[j][0] = npref[j-1][0]+ndp[j][0];
                npref[j][0]%=p;
                npref[j][1] = npref[j-1][1]+ndp[j][1];
                npref[j][1]%=p;
                nsympref[j][0] = nsympref[j-1][0]+symdp[j][0];
                nsympref[j][0]%=p;
                nsympref[j][1] = nsympref[j-1][1]+nsymdp[j][1];
                nsympref[j][1]%=p;
                //cout << "dp " << i+1 << " " << j << " " << 0 << " is " << ndp[j][0] << "\n";
                //cout << "dp " << i+1 << " " << j << " " << 1 << " is " << ndp[j][1] << "\n";
                cout << "symdp " << i+1 << " " << j << " " << 0 << " is " << nsymdp[j][0] << "\n";
                cout << "symdp " << i+1 << " " << j << " " << 1 << " is " << nsymdp[j][1] << "\n";
            }
            //cout << "cnt0 for " << i+1 << " is " << ncnt0 << "\n";
            cout << "symcnt0 for " << i+1 << " is " << nsymcnt0 << "\n";
        }
        dp = move(ndp);
        symdp = move(nsymdp);
        pref = move(npref);
        sympref = move(nsympref);
        cnt0 = move(ncnt0);
        symcnt0 = move(nsymcnt0);
    }
    int res = (pref[k][0]+pref[k][1]+cnt0);//+(sympref[k][0]+sympref[k][1]+symcnt0);
    cout << res%p << "\n";
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
