#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

const int maxN = 1e6+5;
int sieve[maxN] = {};

void compute(){
    for(int i=2;i<maxN;i++) sieve[i] = i;
    for(int i=2;i<maxN;i++){
        if(sieve[i]==i){
            for(int j=i;j<maxN;j+=i){
                sieve[j] = i;
            }
        }
    }
}


void solve(){
    int n;
    cin >> n;
    int ans = 1;
    unordered_map<int,int> cnt;
    unordered_map<int,int> numbers;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        numbers[z]++;
    }
    for(auto x : numbers){
        vector<int> factors;
        int z = x.ff;
        while(z>1){
            factors.pb(sieve[z]);
            z/=sieve[z];
        }
        int num = factors.size();
        int mx = 1LL<<num;
        unordered_set<int> s;
        for(int i=1;i<mx;i++){
            int res = 1;
            for(int j=0;j<num;j++){
                if(i & 1LL<<j){
                    res*=factors[j];
                }
            }
            if(s.find(res)!=s.end()) continue;
            s.insert(res);
            cnt[res]+=x.ss;
            if(cnt[res] > 1) ans = max(ans, res);
        }
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    compute();
    solve();
    return 0;
}
