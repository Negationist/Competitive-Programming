#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void op(int i, vector<vi> &diff, int k, int n, vector<vi> &ans){
    if(i==n-1){
        ans[0][0]+=k;
        ans[0].back()-=k;
        diff[0][0]+=k;
        diff[1].back()-=k;
        return;
    }
    if(i%2==0){
        int index = ((i+1)/2+1);
        if(index<ans[0].size()){
            ans[0][index]+=k;
        }
        ans[1][0]+=k;
        if(index-1<ans[1].size()){
            ans[1][index-1]-=k;
        }
        diff[0][index-1]-=k;
        diff[0][index]+=k;
    } else{
        int index = i/2+1;
        if(index<ans[1].size()){
            ans[1][index]+=k;
        }
        ans[0][0]+=k;
        ans[0][index]-=k;
        diff[1][index-1]-=k;
        diff[1][index]+=k;
    }
}

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    if(n==1){
        cout << a[0] << "\n";
        return;
    }
    vector<vi> ans(2);
    ans[0].resize(n/2+1);
    ans[1].resize(n/2);
    vector<vi> diff(2);
    int delta=0;
    for(int i=0;i<n;i++){
        int res = a[i]-a[(i-1+n)%n];
        diff[i%2].pb(res);
        delta+=res*(i%2==0?1:-1);
    }
    op(n-1,diff,-1*delta/2,n,ans);
    for(int i=0;i<diff[0].size()-1;i++){
        op(2*i, diff, diff[0][i],n,ans);
    }
    for(int i=0;i<diff[1].size()-1;i++){
        op(2*i+1, diff, diff[1][i],n,ans);
    }
    vi rAns(n);
    int sum = 0;
    int mn = LLONG_MAX;
    for(int i=0;i<ans[0].size();i++){
        sum+=ans[0][i];
        rAns[2*i] = sum;
        mn = min(mn,sum);
    }
    sum=0;
    for(int i=0;i<ans[1].size();i++){
        sum+=ans[1][i];
        rAns[2*i+1] = sum;
        mn = min(mn,sum);
    }
    for(int i=0;i<n;i++){
        rAns[i]-=mn;
    }
    for(int x : rAns){
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
