#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

pair<int,int> mnmx(vector<int> &a){
    pii res = {0,0};
    int n = a.size();
    int sum = 0;
    for(int i=0;i<n;i++){
        if(sum<0){
            sum+=a[i];
        } else{
            sum = a[i];
        }
        res.ff = min(res.ff,sum);
    }
    sum = 0;
    for(int i=0;i<n;i++){
        if(sum>0){
            sum+=a[i];
        } else{
            sum = a[i];
        }
        res.ss = max(res.ss,sum);
    }
    return res;
}

void solve(){
    int n;
    cin >> n;
    vi a(n);
    int index;
    int num = -1;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(abs(a[i])!=1){
            index = i;
            num = a[i];
        }
    }
    set<int> ans;
    if(num!=-1){
        int sum = 0;
        int lo1 = 0,hi1 = 0, lo2 = 0, hi2 = 0;
        for(int i=index-1;i>=0;i--){
            sum+=a[i];
            lo1 = min(sum,lo1);
            hi1 = max(sum,hi1);
        }
        sum = 0;
        for(int i=index+1;i<n;i++){
            sum+=a[i];
            lo2 = min(sum,lo2);
            hi2 = max(sum,hi2);
        }
        int up = hi1+hi2;
        int down = lo1+lo2;
        for(int i=down;i<=up;i++){
            ans.insert(num+i);
        }
        vi x;
        for(int i=0;i<index;i++){
            x.pb(a[i]);
        }
        vi y;
        for(int i=index+1;i<n;i++){
            y.pb(a[i]);
        }
        pii z1 = mnmx(x);
        pii z2 = mnmx(y);
        for(int i=z1.ff;i<=z1.ss;i++){
            ans.insert(i);
        }
        for(int i=z2.ff;i<=z2.ss;i++){
            ans.insert(i);
        }
    } else{
        pii z = mnmx(a);
        for(int i=z.ff;i<=z.ss;i++){
            ans.insert(i);
        }
    }
    cout << ans.size() << "\n";
    for(int x : ans){
        cout << x << " ";
    }
    cout << "\n";
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
