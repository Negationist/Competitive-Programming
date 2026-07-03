#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve(){
    int n;
    cin >> n;
    vi a(n);
    int z;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(!i) z = a[i];
        else z = gcd(z,a[i]);
    }
    for(int i=0;i<n;i++){
        a[i]/=z;
    }
    sort(a.begin(),a.end());
    vi b(n);
    b[0] = a[0];
    a[0]=0;
    int cur = b[0];
    for(int i=1;i<n;i++){
        if(cur==1){
            for(int j=i;j<n;j++){
                b[i] = 1;
            }
            break;
        }
        int mn = LLONG_MAX;
        int index;
        for(int j=0;j<n;j++){
            if(a[j]==0) continue;
            int res = gcd(cur, a[j]);
            if(res<mn){
                mn = res;
                index = j;
            }
        }
        cur = gcd(cur,a[index]);
        b[i] = a[index];
        a[index] = 0;
    }
    int sum = b[0];
    cur = b[0];
    for(int i=1;i<n;i++){
        cur = gcd(cur,b[i]);
        sum+=cur;
    }
    cout << sum*z << "\n";
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
