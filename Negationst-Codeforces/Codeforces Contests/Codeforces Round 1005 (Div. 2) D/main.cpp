#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
const int maxN = 2e5+5;
int a[maxN];
void solve(){
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int bit[n+1];
    int lastbit[30];
    for(int i=0;i<=n;i++){
        bit[i] = 31-__builtin_clz(a[i]);
        lastbit[bit[i]] = max(lastbit[bit[i]],i);
    }
    int suff[n+2];
    suff[n+1] = 0;
    suff[n] = a[n];
    for(int i=n-1;i>=0;i--){
        suff[i] = suff[i+1]^a[i];
    }
    int last[n+1];
    stack<int> s;
    for(int i=n;i>=0;i--){
        while(s.size()){
            if(bit[s.top()]<=bit[i]){
                last[s.top()] = i;
                s.pop();
            } else{
                break;
            }
        }
        s.push(i);
    }
    auto MSB = [&](int x){
        return 31-__builtin_clz(x);
    };
    while(q--){
        int x;
        cin >> x;
        int msb = MSB(x);
        int pos = -1;
        for(int i=msb;i<30;i++){
            pos = max(pos,lastbit[i]);
        }
        while(true){
            int y = x^suff[pos+1];
            if(bit[pos]>MSB(y)){
                break;
            } else{
                pos
            }
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
    a[0] = (1LL<<30)-1;
    while(t--){
        solve();
    }
    return 0;
}
