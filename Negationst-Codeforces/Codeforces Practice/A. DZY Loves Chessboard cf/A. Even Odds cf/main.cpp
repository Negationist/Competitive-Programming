#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    long long n,k,index;
    cin >> n >> k;
    if (k<n/2+1){
        cout << 1+2*(k-1);
    } else{
        cout << 2+2*(k-round((double)n/2)-1);
    }
    return 0;
}
