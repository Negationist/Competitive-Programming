#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

const int maxN = 1e6+20;

int totient[maxN] = {};
int sieve[maxN] = {};
void totientMake(){
    totient[0] = 1;
    for(int i=1;i<maxN;i++){
        totient[i] = i;
    }
    for(int i=2;i<maxN;i++){
        if(totient[i]==i){
            for(int j=i;j<maxN;j+=i){
                totient[j]-=(totient[j]/i);
            }
        }
    }
}

void sieveMake(){
    for(int i=2;i<maxN;i++){
        if(sieve[i]==0){
            for(int j=i;j<maxN;j+=i){
                sieve[j] = i;
            }
        }
    }
}

void solve(){
    int g[maxN] = {};
    g[1] = 0;
    g[2] = 1;
    for(int i=3;i<maxN;i++){
        int res = 0;
        int cur = i;
        vector<int> divisors;
        //pie over divisors for each add d*phi(n/d), too lazy to do now
        g[i] = g[i-1];
    }
    while(true){
        int n;
        cin >> n;
        if(!n) break;

    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    totientMake();
    sieveMake();
    solve();
    return 0;
}
