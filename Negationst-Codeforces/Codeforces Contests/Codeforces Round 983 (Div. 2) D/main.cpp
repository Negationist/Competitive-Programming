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
    int n;
    cin >> n;
    vii s(n);
    s[1] = {0,0};
    for(int i=2;i<n;i++){
        s[i] = {0,i-1};
    }
    int z = n-1;
    int minPar = LLONG_MAX;
    while(true){
        if(z==1) break;
        int askable =  s[z].second;
        askable = min(askable,minPar-1);
        if(askable==0){
            s[z]={0,0};
            z--;
            continue;
        }
        int res = ask(z,askable);
        if(!res){
            s[z] = {askable,askable};
            minPar = min(minPar,askable);
        } else{
            int mx = max(askable-1,0LL);
            s[z].second=mx;
        }
        if(s[z].second-s[z].first==0){
            cout << "node " << z << " has parent " << s[z].first << "\n";
            cout.flush();
            z--;
        }
    }
    cout << "! ";
    for(int i=1;i<n;i++){
        cout << s[i].first << " ";
    }
    cout << "\n";
    cout.flush();
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
