#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string t1 = "00";
    int t1G = 0;
    string t2 = "00";
    int t2G = 0;
    bool t1assigned = false;
    bool t2assigned = false;
    while(n--){
        string a;
        cin >> a;
        if (a==t1){
            t1G++;
        }
        if (a==t2){
            t2G++;
        }
        if (a!=t1 && a!=t2 && !t1assigned){
            t1G++;
            t1 = a;
            t1assigned = true;
        }
        if (a!=t1 && a!=t2 && t1assigned &!t2assigned){
            t2G++;
            t2 = a;
            t2assigned = true;
        }
    }
    if (t1G>t2G){
            cout << t1;
        } else {
            cout << t2;
        }
    return 0;
}
