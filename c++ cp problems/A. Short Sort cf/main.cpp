#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--){
        string i;
        cin >> i;
        if (i[0]=='a'||i[1]=='b'||i[2]=='c'){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
