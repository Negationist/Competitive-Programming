#include <bits/stdc++.h>

using namespace std;

int main()
{
    string e;
    cin >> e;
    for (int i=1; i<e.size(); i++){
        if (e[i-2]=='1' && e[i-1]=='4' && e[i]=='4'){
            e[i-2]='z';
            e[i-1]='z';
            e[i]='z';
            }
    }
    for (int i=0; i<e.size(); i++){
        if (e[i-1]=='1' && e[i]=='4'){
            e[i-1]='z';
            e[i]='z';
        }
    }
    for (int i=0; i<e.size(); i++){
        if (e[i]=='1'){
            e[i] = 'z';
        }
    }
    for (int i=0; i<e.size(); i++){
        if (e[i]!='z'){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}
