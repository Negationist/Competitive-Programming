#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    int num = 0;
    int minCap = 0;
    cin >> t;
    while(t--){
        int a;
        int b;
        cin >> a >> b;
        num-=a;
        num+=b;
        minCap = max(minCap,num);
    }
    cout << minCap;
    return 0;
}
