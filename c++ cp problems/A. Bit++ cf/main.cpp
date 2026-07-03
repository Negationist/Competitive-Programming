#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int t,x=0;
    cin >> t;
    for (int i=0;i<t;i++){
        string a;
        cin >> a;
        for (int i=0;i<3;i++){
            if (a[i]=='+'){
                x++;
                break;
            } else if(a[i]=='-'){
                x--;
                break;
            }
        }
    }
    cout << x;
    return 0;
}
