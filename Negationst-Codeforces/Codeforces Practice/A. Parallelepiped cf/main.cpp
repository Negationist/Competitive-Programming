#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,x,y,z;
    cin >> a >> b >> c;
    z = sqrt((a*b)/c);
    x = a/z;
    y = b/z;
    cout << (4*x+4*y+4*z);
    return 0;
}
