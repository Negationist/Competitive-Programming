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
    string x,y;
    cin >> x >> y;
    int pos = 0;
    for(int i=0;i<x.size();i++){
        if(x[pos]<y[pos]){
            for(int j=pos+1;j<x.size();j++){
                if(x[j]<y[j]){
                    swap(x[j],y[j]);
                }
            }
            cout << x << "\n" << y << "\n";
            return;
        } else if(y[pos]<x[pos]){
            for(int j=pos+1;j<x.size();j++){
                if(x[j]>y[j]){
                    swap(x[j],y[j]);
                }
            }
            cout << x << "\n" << y << "\n";
            return;
        }
        pos++;
    }
    cout << x << "\n" << y << "\n";
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
