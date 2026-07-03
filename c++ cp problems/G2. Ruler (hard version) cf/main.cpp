#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int ask(int a, int b){
    cout << "? " << a << " " << b << "\n";
    cout.flush();
    int z;
    cin >> z;
    return z;
}

void solve(){
    int l=2, r=999;
    while(l!=r){
        int i=l+(r-l)/3, j=l+(r-l)*2/3;
        int z = ask(i,j);
        if(z==i*j){
            l = j+1;
        } else if(z==i*(j+1)){
            l = i+1;
            r = j;
        } else{
            r = i;
        }
    }
    cout << "! " << l << "\n";
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
