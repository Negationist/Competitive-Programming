#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;

long double distance(pair<ld,ld> a, pair<ld,ld> b){
    ld res = (b.ff-a.ff)*(b.ff-a.ff)+(b.ss-a.ss)*(b.ss-a.ss);
    return res;
}

ld xcept(pair<ld,ld> a, pair<ld,ld> b){
    if(a.ss == b.ss){
        ld mid = (a.ff+b.ff)/2;
        return mid;
    }
    pair<ld,ld>  res;
    res.ff = (a.ff+b.ff)/2;
    res.ss = (a.ss+b.ss)/2;
    ld slope = -(b.ff-a.ff)/(b.ss-a.ss);
    ld c = res.ss-res.ff*slope;
    ld x = -c/slope;
    return x;
}

void solve(){
    int n,l;
    cin >> n >> l;
    vector<pair<ld,ld>> p1(n);
    for(int i=0;i<n;i++){
        ld x,y;
        cin >> x >> y;
        y = abs(y);
        p1[i] = {x,y};
    }
    vector<pair<ld,ld>> p;
    sort(p1.begin(),p1.end());
    p.pb(p1[0]);
    for(int i=1;i<n;i++){
        if(p1[i].ff != p1[i-1].ff){
            p.pb(p1[i]);
        }
    }
    ld ans = -1;
    sort(p.begin(),p.end());
    stack<tuple<ld,ld,int>> stck;
    stck.push({0,l,0});
    for(int i=1;i<p.size();i++){
        bool flag = false;
        while(true && stck.size()){
            int last = get<2>(stck.top());
            ld res = xcept(p[last],p[i]);
            if(res>l){
                flag = true;
                break;
            }
            int left =get<0>(stck.top());
            if(res<=left){
                stck.pop();
            } else{
                break;
            }
        }
        if(flag) continue;
        if(stck.size()==0){
            stck.push({0,l,i});
        } else{
            int last = get<2>(stck.top());
            ld res = xcept(p[last],p[i]);
            ld left =get<0>(stck.top());
            stck.pop();
            stck.push({left,res,last});
            stck.push({res,l,i});
        }
    }
    while(stck.size()){
        ld cur = get<2>(stck.top());
        ld left = get<0>(stck.top());
        ld right = get<1>(stck.top());
        ld ans1 = distance(p[cur],{left,0});
        ld ans2 = distance(p[cur],{right,0});
        ans = max(ans1,ans);
        ans = max(ans2,ans);
        stck.pop();
    }
    cout << fixed << setprecision(15) << sqrtl(ans) << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
