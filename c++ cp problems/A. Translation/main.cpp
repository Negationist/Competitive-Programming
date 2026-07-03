#include <bits/stdc++.h>

using namespace std;

int main()
{

    string a,b;
    cin >> a >> b;
    if(a.size()!=b.size()){
    cout << "NO";
    return 0;
    }
    for (int i=0; i<a.size(); i++){
        if (a[i]!=b[a.size()-1-i]){
            cout << "NO";
            return 0;
        }
    }
        cout << "YES";
}
