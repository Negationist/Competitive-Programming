#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int xor0(int n){
    if(n%4==0){
        return n;
    } else if(n%4==1){
        return 1;
    } else if(n%4==2){
        return n+1;
    } else{
        return 0;
    }
}

int modrange(int l, int r){
    int x = (l-1>=0?xor0(l-1):0);
    int y = xor0(r);
    int res = x^y;
    return res;
}

void solve(){
    int l,r,i,k;
    cin >> l >> r >> i >> k;
    int res = modrange(l,r);
    int first = l-l%(1LL<<i);
    first+=k;
    if(first<l){
        first+=(1LL<<i);
    }
    int z = 0;
    if(first<=r){
        int num = (first-k)/(1LL<<i);
        int cnt = (r-first)/(1LL<<i);
        z = modrange(num,num+cnt)*(1LL<<i);
        cnt++;
        z+=(cnt%2==1)*k;
    }
    cout << (res^z) << "\n";
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
