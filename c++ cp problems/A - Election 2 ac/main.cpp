#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int n,t,a;
    cin >> n >> t >> a;
    if (abs(a-t)>(n-t-a)){
        cout << "YES";
    } else{
        cout << "NO";
    }
    return 0;
}
