#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void ask(int a, int b){
    cout << "? " << a << " " << b << "\n";
    cout.flush();
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,ans;
        cin >> n;
        vii edges;
        for(int i=2;i<=n;i++){
            int node = 1;
            while(true){
                ask(i,node);
                cin >> ans;
                if(ans==i){
                    break;
                } else{
                   node = ans;
                }
            }
            edges.pb(make_pair(i,node));
        }
        cout << "! ";
        for(auto it=edges.begin();it!=edges.end();it++){
            cout << it->first << " " << it->second << " ";
        }
        cout << "\n";
        cout.flush();
    }
    return 0;
}
