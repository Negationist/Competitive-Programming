#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;

int ask(int i, int j){
    cout << "? " << i << " " << j << "\n";
    cout.flush();
    int z;
    cin >> z;
    return z;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<int> out;
        for(int i=1;i<=n;i++){
            out.insert(i);
        }
        int x=-1,y=-1;
        for(int i=1;i<=n;i++){
            int z;
            cin >> z;
            if(z==1){
                x = i;
            } else if(z==n){
                y = i;
            }
            out.erase(z);
        }
        if(out.size()){
            int a = *(out.rbegin());
            int b = a%n+1;
            int z = ask(a,b);
            if(z){
                cout << "! B\n";
            } else{
                cout << "! A\n";
            }
            cout.flush();
        } else{
            int z1 = ask(x,y);
            int z2 = ask(y,x);
            if(z1<n-1){
                cout << "! A\n";
            } else if(z1>n-1){
                cout << "! B\n";
            } else{
                if(z1==z2){
                    cout << "! B\n";
                } else{
                    cout << "! A\n";
                }
            }
        }
        cout.flush();
    }
    return 0;
}
