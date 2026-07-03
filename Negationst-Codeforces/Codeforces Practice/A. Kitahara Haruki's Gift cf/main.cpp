#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a=0, b=0;
    while(n--){
        int x;
        cin >> x;
        if(x==100){
            a++;
        } else{
            b++;
        }
    }

    if((a%2==0 && a!=0) || (a==0 && b%2==0)){
        cout << "YES";
    } else{
        cout << "NO";
    }

    return 0;
}
