#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
int h, w;

int get2(int i, int j, vector<vi>&a, int goal, int cnt){
    if(a[i][j]==goal){
        return cnt;
    }
    if(cnt>h*w){
        return LLONG_MAX;
    }
    pii next = {-1,-1};
    int best = LLONG_MAX;
    if(i>1){
        if(abs(a[i-1][j]-goal)<best){
            best = abs(a[i-1][j]-goal);
            next = {i-1,j};
        }
    }
    if(i<h){
        if(abs(a[i+1][j]-goal)<best){
            best = abs(a[i+1][j]-goal);
            next = {i+1,j};
        }
        if(abs(a[i+1][j]-goal)==best){
            if(abs(a[i+1][j]-a[i][j]) < abs(a[i][j]-a[next.ff][next.ss])){
                next = {i+1,j};
            }
        }
    }
    if(j>1){
        if(abs(a[i][j-1]-goal)<best){
            best = abs(a[i][j-1]-goal);
            next = {i,j-1};
        }
        if(abs(a[i][j-1]-goal)==best){
            if(abs(a[i][j-1]-a[i][j]) < abs(a[i][j]-a[next.ff][next.ss])){
                next = {i,j-1};
            }
        }
    }
    if(j<w){
        if(abs(a[i][j+1]-goal)<best){
            best = abs(a[i][j+1]-goal);
            next = {i,j+1};
        }
        if(abs(a[i][j+1]-goal)==best){
            if(abs(a[i][j+1]-a[i][j]) < abs(a[i][j+1]-a[next.ff][next.ss])){
                next = {i,j+1};
            }
        }
    }
    return get2(next.ff,next.ss,a, goal, cnt+1);
}

int get(vector<vi>&a, int x, int y){
    int ans = -1;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            int res = get2(x,y,a,a[i][j],0);
            ans = max(ans,res);
        }
    }
    return ans;
}

void solve(){
    cin >> h >> w;
    vector<vi> a(h+1,vector<int> (w+1));
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> a[i][j];
        }
    }
    pii ans = {-1,LLONG_MAX};
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            int res = get(a,i,j);
            if(res<ans.ss){
                ans = {a[i][j],res};
            }
        }
    }
    if(ans.ss==LLONG_MAX){
        cout << "impossible\n";
        return;
    }
    cout << ans.ff << " " << ans.ss << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
