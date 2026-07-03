#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void update(int k, int x, vector<int> &tree){
    while(k<=tree.size()-1){
        tree[k]+=x;
        k+=(k&-k);
    }
}
int sum(int l, int r, vi &tree){
    int suml = 0,sumr = 0;
    l--;
    while(l>0){
        suml+=tree[l];
        l-=(l&-l);
    }
    while(r>0){
        sumr+=tree[r];
        r-=(r&-r);
    }
    return sumr-suml;
}

void solve(){
    int n;
    cin >> n;
    vi tree(n+1,0);
    for(int i=1;i<=n;i++){
        int z;
        cin >> z;
        update(i,z,tree);
    }
    cout << "please update me\n";
    int c,d;
    cin >> c >> d;
    update(c, d, tree);
    cout << "sum?\n";
    cin >> c >> d;
    cout << sum(c,d,tree);
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
