#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; int z=0; int f=0;
    cin >> n;
    while (n--){
        int a;
        cin >> a;
        if (a==0){
            z++;
        } else{
            f++;
        }
    }
    if (z==0){
        cout << "-1";
        return 0;
    }
    f = f-f%9;
    if (f==0){
        cout << "0";
        return 0;
    }

    for (int i = 0; i<f; i++){
        cout << "5";
    }
    for (int i = 0; i<z; i++){
        cout << "0";
    }
    return 0;
}
