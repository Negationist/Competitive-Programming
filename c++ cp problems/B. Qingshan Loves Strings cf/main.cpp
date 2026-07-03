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
    int n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    set<int> st;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]){
            st.insert(s[i]);
            if(st.size()>1){
                cout << "No\n";
                return;
            }
        }
    }
    if(st.size()==0){
        cout << "Yes\n";
        return;
    }
    for(int i=0;i<t.size()-1;i++){
        if(t[i]==t[i+1]){
            cout << "No\n";
            return;
        }
    }
    int x = *st.begin();
    if(t[0]==x || t.back()==x){
        cout << "No\n";
    } else{
        cout << "Yes\n";
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
