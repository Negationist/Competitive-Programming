#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

const int MOD = 1e9+7;

int a[200001] = {0};

long long factorial(int n){
    if (a[n]!=0){
        return a[n];
    } else{
        a[n] = (n*factorial(n-1))%MOD;
        return a[n];
    }
}
long long nCr(int n,int r){
    int a = (factorial(n)/factorial(r)/factorial(n-r));
    return a;
}

int main()
{
    a[0]=1;
    int t;
    cin >> t;
    while(t--){
        long long sum = 0;
        int n,k,a=0,b=0;
        cin >> n >> k;
        FOR(i,n){
            int d;
            cin >> d;
            if (d==1){
                a++;
            } else{
                b++;
            }
        }
        int oneUp = min(k,a);
        int oneLow = (k+1)/2;
        for(int i = oneLow;i<=oneUp;i++){
            long long z = (nCr(a,i)%MOD)*(nCr(b,k-i)%MOD);
            sum+=z;
        }
        cout << sum << endl;
    }
    return 0;
}
