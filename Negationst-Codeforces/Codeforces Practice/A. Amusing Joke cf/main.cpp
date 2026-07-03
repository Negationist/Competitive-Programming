#include <bits/stdc++.h>

using namespace std;

void solve(){
    string a,b,c;
    cin >> a >> b >> c;
    if(c.size() != a.size()+b.size()){
        cout << "NO";
        return;
    }
    for (int i = 0;i<a.size();i++){
        auto pos = c.find(a[i]);
        if(pos == string::npos){
            cout << "NO";
            return;
        }
        else{
            c[pos] = '0';
        }
    }
    for (int i = 0;i<b.size();i++){
        auto pos = c.find(b[i]);
        if(pos == string::npos){
            cout << "NO";
            return;
        }
        else{
            c[pos] = '0';
        }
    }
    cout << "YES";
}

int main()
{
    solve();
    return 0;
}
