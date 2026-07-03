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
    int n;
    cin >> n;
    stack<int> s;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        s.push(z%2);
        while(s.size()>=2){
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            if(x==y) continue;
            else{
                s.push(y);
                s.push(x);
                break;
            }
        }
    }
    if(s.size()<2){
        cout << "YES\n";
    } else{
        cout << "NO\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
