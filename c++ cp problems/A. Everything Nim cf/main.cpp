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
    set<int> s;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        s.insert(a);
    }
    if(*s.begin()!=1){
        cout << "Alice\n";
    } else if(s.size()==2){
        cout << "Bob\n";
    } else{
        int last = -1;
        int inc = 0;
        for(int x : s){
            if(last!=-1 && x-last>1){
                if(inc%2==1){
                    cout << "Bob\n";
                } else{
                    cout << "Alice\n";
                }
                return;
            }
            last = x;
            inc++;
        }
        if(s.size()%2==0){
            cout << "Bob\n";
        } else{
            cout << "Alice\n";
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
