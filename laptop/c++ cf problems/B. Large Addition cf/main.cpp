#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    string s;
    cin >> s;
    if(s=="10"){
        cout << "Yes\n";
        return;
    }
    if(s[s.size()-1]=='9') {
        cout << "No\n";
        return;
    }
    for(int i=s.size()-2;i>0;i--){
        int x = s[i]-'0';
        if(x==0){
            cout << "No\n";
            return;
        }
    }
    int x = s[0]-'0';
    if(x!=1){
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
