#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

class DSU{
public:
    vector<int> parent,cnt;
    DSU(int n){
        cnt.assign(n,1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int pfind(int x){
        while(i!=parent[i]){
            parent[i] = pfind(parent[i]);
        }
        return parent[i];
    }
    void unite(int a, int b){
        int rootA = pfind(a);
        int rootB = pfind(B);
        if(rootA = rootB) return;
        if(cnt[rootA]<=cnt[rootB]){
            parent
        }
    }
};

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
