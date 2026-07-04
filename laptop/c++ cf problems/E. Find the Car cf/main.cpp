#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void solve(){
    int n,k,q;
    cin >> n >> k >> q;
    int a[k+1],b[k+1];
    a[0] = b[0] = 0;
    for(int i=1;i<k+1;i++){
        cin >> a[i];
    }
    for(int i=1;i<k+1;i++){
        cin >> b[i];
    }
    int qrs[q];
    set<int> s;
    map<int,int> m;
    for(int i=0;i<q;i++){
        cin >> qrs[i];
        s.insert(qrs[i]);
    }
    int index = 0;
    for(int x : s){
        if(a[index]==x){
            m[x] = b[index];
            continue;
        }
        while(a[index]<x){
            index++;
            if(a[index]==x){
                m[x] = b[index];
                continue;
            }
        }
        int ans = (b[index]-b[index-1])*(x-a[index-1]);
        ans/=(a[index]-a[index-1]);
        ans+=(b[index-1]);
        m[x] = ans;
    }
    for(int i=0;i<q;i++){
        cout << m[qrs[i]] << " ";
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
