#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int a=0,b,n,m,e=0; cin >> n >> m;
    while(a*a<=n){
        b = n-a*a;
        if (m==b*b+a){
            e++;
        }
        a++;
    }
    cout << e;
    return 0;
}
