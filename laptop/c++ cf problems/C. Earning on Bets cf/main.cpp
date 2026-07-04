#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int GCD(int x,int y){
    if(y%x==0) return x;
    return GCD(y%x,x);
}

int LCM(int x,int y){
    return x*y/GCD(x,y);
}

void solve(){
    int n,lcm,sum=0;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(i==0)lcm = a[i];
        else{
            lcm = LCM(lcm,a[i]);
        }
    }
    for(int i=0;i<n;i++){
        int current = lcm/a[i];
        sum+=current;
    }
    if (sum >= lcm){
        cout << -1 << endl;
    } else{
        int diff = lcm-sum;
        int factor = (n/diff)+1;
        for(int i=0;i<n;i++){
            int z = (lcm/a[i])*factor;
            z++;
            cout << z << " ";
        }
        cout << "\n";
    }
}

signed main()
{
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
