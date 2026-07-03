#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    for(int i=2;i<=1000;i++){ // O(n)
        bool isprime = true;
        int num = i;
        for(int j=2;j<=sqrt(num);j++){ //O(nsqrt(n))
            if (num%j==0){
                isprime = false;
                break;
            }
        }
        if(isprime){
            cout << i << endl;
        }
    }
    return 0;
}
