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

void guess(int a){
    cout << "! " << a << "\n";
    cout.flush();
}

void solve(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i+=2){
        if(i==n){
            guess(i);
            return;
        }
        int a = ask(i,i+1);
        int b = ask(i+1,i);
        if(a!=b){
            int next = (i+2)%n;
            if(next==0) next = n;
            int c = ask(i,next);
            int d = ask(next,i);
            if(c!=d){
                guess(i);
                return;
            } else{
                guess(i+1);
                return;
            }
        }
    }
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
