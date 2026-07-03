#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    double n,k,index;
    cin >> n >> k;
    if (k<n/2+1){
        double out = 1+2*(k-1);
        cout << (long long)out;
    } else{
        double out = 2+2*(k-round(n/2)-1);
        cout << (long long)out;
    }
    return 0;
}
