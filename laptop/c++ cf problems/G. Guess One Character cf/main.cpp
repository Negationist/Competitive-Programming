#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int ask(string s){
    cout << "1 " << s << "\n";
    cout.flush();
    int z;
    cin >> z;
    return z;
}

void guess(char x, int i){
    cout << "0 " << i << " " << x << "\n";
    cout.flush();
}

void solve(){
    int n;
    cin >> n;
    int x = ask("0");
    int y = ask("01");
    int z = ask("00");
    if(x==y){
        guess('1',n);
    } else{
        int diff = x-y;
        if(z==diff){
            guess('1',n);
        } else{
            guess('0',n);
        }
    }
    int bruh;
    cin >> bruh;
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
