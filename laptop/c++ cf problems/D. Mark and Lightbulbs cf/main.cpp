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

void solve(){
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    vii segs1;
    vii segs2;
    int cnt1 = 1, cnt2 = 1;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            cnt1++;
        } else{
            segs1.pb({i-cnt1,i-1});
            cnt1 = 1;
        }
        if(b[i]==b[i-1]){
            cnt2++;
        } else{
            segs2.pb({i-cnt2,i-1});
            cnt2 = 1;
        }
    }
    segs1.pb({n-cnt1,n-1});
    segs2.pb({n-cnt2,n-1});
    bool win = (segs1.size()==segs2.size() && a[0]==b[0]);
    /*for(auto x : segs1){
        cout << x.ff << " " << x.ss << "\n";
    }*/
    if(!win){
        cout << -1 << "\n";
        return;
    }
    int z = segs1.size();
    int cost = 0;
    for(int i=0;i<z;i++){
        if(a[segs1[i].ff]!='1') continue; //only work with one type for programming reasons
        int l = max(segs1[i].ff,segs2[i].ff);
        int r = min(segs1[i].ss,segs2[i].ss);
        if(l<=r){
            int temp1 = segs1[i].ss-segs1[i].ff+1 - (r-l+1);
            int temp2 = segs2[i].ss-segs2[i].ff+1 - (r-l+1);
            cost+=(temp1+temp2);
        } else if(segs1[i].ss < segs2[i].ff){ //to the left
            int far = segs1[i].ss;
            int goal = segs2[i].ff;
            int num = goal-far;
            cost+=(num*2);
            int num1 = segs1[i].ss-segs1[i].ff+1;
            int num2 = segs2[i].ss-segs2[i].ff+1;
            cost+=(num1+num2-2);
        } else{
            int far = segs2[i].ss;
            int goal = segs1[i].ff;
            int num = goal-far;
            cost+=(num*2);
            int num1 = segs1[i].ss-segs1[i].ff+1;
            int num2 = segs2[i].ss-segs2[i].ff+1;
            cost+=(num1+num2-2);
        }
    }
    cout << cost << "\n";
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
