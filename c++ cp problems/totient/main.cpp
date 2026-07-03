#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

const int maxN = 1e5+5;
int totient[maxN] = {};

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

void solve(){

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
