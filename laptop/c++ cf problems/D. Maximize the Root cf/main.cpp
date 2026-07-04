#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

vector<int> val;
vector<vector<int>> kids;

bool check(int cur, int goal){
    if(goal>1e9) return false;
    if(kids[cur].size()==0){
        if(val[cur]>=goal){
            return true;
        } else{
            return false;
        }
    }
    if(val[cur] >= goal){
        for(int x : kids[cur]){
            if(!check(x,goal)){
                return false;
            }
        }
    } else{
        for(int x : kids[cur]){
            if(!check(x, goal+(goal-val[cur]))){
                return false;
            }
        }
    }
    return true;
}

void solve(){
    int n;
    cin >> n;
    val.clear();
    kids.clear();
    val.resize(n);
    kids.resize(n);
    int mx=0, mn = LLONG_MAX;
    for(int i=0;i<n;i++){
        cin >> val[i];
        mx = max(mx,val[i]);
        mn = min(mn,val[i]);
    }
    for(int i=1;i<n;i++){
        int a;
        cin >> a;
        a--;
        kids[a].pb(i);
    }
    int l=0,r=mx+mn;
    while(l<=r){
        int mid = l + (r-l)/2;
        for(int x : kids[0]){
            if(!check(x,mid)){
                r = mid - 1;
                continue;
            } else{
                l = mid + 1;
            }
        }
    }
    cout << val[0]+r << endl;
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
