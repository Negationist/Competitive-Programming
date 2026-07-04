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
    int n;
    cin >> n;
    map<int,int> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
        int cur = a[i];
        for(int i=1;i<=sqrtl(a[i]);i++){
            while(a%i==0){
                a/=i
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
