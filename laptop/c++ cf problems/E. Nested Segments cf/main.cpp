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
const int mod = 998244353;
const int maxN = (2e5+5)*2;
vi fact(maxN),factInv(maxN);
vi cata(maxN);

int binPowMod(int b, int p, int mod){
    int res = 1;
    b%=mod;
    while(p>0){
        if(p&1){
            res*=b;
            res%=mod;
        }
        p>>=1;
        b = (b*b)%mod;
    }
    return res;
}

int modInv(int x, int mod){
    return binPowMod(x,mod-2,mod);
}

void compute(){
    fact[0] = fact[1] = 1;
    for(int i=2;i<maxN;i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
    factInv[maxN-1] = modInv(fact[maxN-1],mod);
    for(int i=maxN-2;i>=0;i--){
        factInv[i] = (factInv[i+1]*(i+1))%mod;
    }
    cata[0] = cata[1] = 1;
    for(int i=2;i<maxN/2;i++){
        cata[i] = fact[2*i]*factInv[i+1];
        cata[i]%=mod;
        cata[i]*=factInv[i];
        cata[i]%=mod;
    }
}
void solve(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,pii>> events;
    map<pii,int> sze;
    stack<pii> s;
    bool cover = false;
    for(int i=0;i<m;i++){
        int l,r;
        cin >> l >> r;
        if(l==r) continue;
        if(l==1 && r==n){
            cover = true;
        }
        events.pb({l,{l,r}});
        events.pb({r,{l,r}});
        sze[{l,r}] = r-l+1;
    }
    if(!cover){
        events.pb({1,{1,n}});
        events.pb({n,{1,n}});
        sze[{1,n}] = n;
    }
    //cout << "here\n";
    sort(events.begin(),events.end(),
         [&](pair<int,pii> a, pair<int,pii> b){
            bool starta = (a.ff == a.ss.ff);
            bool startb = (b.ff == b.ss.ff);
            if(a.ff != b.ff){ //diff events
                return a.ff<b.ff;
            } else if(starta&&startb){
                return a.ss.ss > b.ss.ss;
            } else{
                return a.ss.ff < b.ss.ff;
            }
         }
         );
    int l = events.size();
    int ans = 1;
    for(int i=0;i<l;i++){
        bool start = (events[i].ff == events[i].ss.ff);
        if(start){
            if(s.size()){
                sze[s.top()]-=(sze[events[i].ss]-1);
            }
            s.push(events[i].ss);
        } else{
            s.pop();
            int res  = cata[sze[events[i].ss]-1];
            ans*=res;
            ans%=mod;
            //cout << "processed " << events[i].ss.ff << " " << events[i].ss.ss << " with size " << sze[events[i].ss] << "\n";
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
    compute();
    while(t--){
        solve();
    }
    return 0;
}
