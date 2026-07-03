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
using ld = long double;

int z;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1;i<=29;i++){
            cout << "add -" << (1<<i) << "\n";
            cout.flush();
            cin >> z;
        }
        cout << "mul " << n << "\n";
        cout.flush();
        cin >> z;
        cout << "!\n";
        cout.flush();
        cin >> z;
        if(z==-1){
            break;
        }
    }
    return 0;
}
