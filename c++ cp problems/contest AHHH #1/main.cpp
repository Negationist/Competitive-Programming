#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

void solve(){
    string x;
    cin >> x;
    /*if (s.size()<3){
        cout << "NO" << endl;
        return;
    }*/
    if (x[0]=='1' && x[1]=='0'){
        x.erase(0,2);
    } else{
        cout << "NO" << endl;
        return;
    }
    for(int i=0;i<x.size();i++){
        if (x[i]!='0'){
            break;
        }
        if(x[i]=='0'){
            cout << "NO" << endl;
            return;
        }
    }
    int n = stoi(x);
    if (n>=2){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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
