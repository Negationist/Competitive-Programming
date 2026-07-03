#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
vector<vector<int>> child;
vector<int> val;

bool check(int cur, int goal){
    if(cur==0){
        for(int x : child[0]){
            if(!check(x,goal)){
                return false;
            }
        }
        return true;
    }
    if(child[cur].size()==0){
        if(val[cur] >= goal){
            return true;
        } else{
            return false;
        }
    }
    if(val[cur] >= goal){
        for(int x : child[cur]){
            if(!check(x,goal)){
                return false;
            }
        }
    } else{
        int inc = goal - val[cur];
        if(goal+inc > 1e9){
            return false;
        }
        for(int x : child[cur]){
            if(!check(x,goal+inc)){
                return false;
            }
        }
    }
    return true;
}

void solve(){
    int n;
    cin >> n;
    child.assign(n,vector<int>());
    val.resize(n);
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        val[i] = a;
    }
    for(int i=1;i<n;i++){
        int a;
        cin >> a;
        a--;
        child[a].pb(i);
    }
    int l=0,r=1e9;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(check(0, mid)){
            l = mid+1;
        } else{
            r = mid - 1;
        }
    }
    cout << val[0]+r << "\n";
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
