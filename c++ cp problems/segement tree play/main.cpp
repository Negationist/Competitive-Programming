#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void update(int k, int x, vector<int> &tree, int n){
    k+=n;
    tree[k]=x;
    while(k>1){
        k/=2;
        tree[k] = min(tree[2*k],tree[2*k+1]);
    }
}

int mn(int l, int r, vector<int> &tree, int n){
    l--;
    r--;
    l+=n;
    r+=n;
    int mn = LLONG_MAX;
    while(l<=r){
        if(l%2==1) mn = min(tree[l++],mn);
        if(r%2==0) mn = min(tree[r--],mn);
        l/=2;
        r/=2;
    }
    return mn;
}

void solve(){
    int n;
    cin >> n;
    vi tree(2*n);
    for(int i=n;i<2*n;i++){
        cin >> tree[i];
    }
    for(int i=n-1;i>0;i--){
        tree[i] = min(tree[2*i],tree[2*i+1]);
    }
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
