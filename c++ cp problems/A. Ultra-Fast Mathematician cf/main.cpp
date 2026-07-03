#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a,b;
    cin >> a >> b;
    string c(a.size(),'0');
    for (int i=0; i<a.size(); i++){
        int e = a[i]-'0';
        int f = b[i]-'0';
        e ^= f;
        c[i] = e+'0';
    }

    cout << c;
    return 0;
}
