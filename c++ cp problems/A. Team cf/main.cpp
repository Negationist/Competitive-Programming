#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)


using namespace std;

int main()
{
    int t,total=0;
    cin >> t;
    FOR(i,t){
        int a, sum=0;
        FOR(i,3){cin >> a; sum+=a;}
        if (sum>1){
            total++;
        }
    }
    cout << total;
    return 0;
}
