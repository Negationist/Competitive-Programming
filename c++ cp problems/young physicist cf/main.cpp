#include <iostream>

using namespace std;

int main()
{
    int q;
    cin >> q;
    int a=0, b = 0,c = 0;
    while(q--){
        int d, e, f;
        cin >> d >> e >> f;
        a+=d;
        b+=e;
        c+=f;
    }
    if (a==0 && b==0 && c==0){
        cout << "YES";
    } else{
    cout << "NO";
    }
    return 0;
}
