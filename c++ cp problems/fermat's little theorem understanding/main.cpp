#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int MOD = 1e9+7;

long long C(int n, int r){
if(r>n-r) r = n-r;
if (r==0||r==n) return 1;
return (C(n-1,r-1)%MOD+C(n-1,r)%MOD)%MOD;
}


int main()
{
    cout << C(50,9);
    return 0;
}
