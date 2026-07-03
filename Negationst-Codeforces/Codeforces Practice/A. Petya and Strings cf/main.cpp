#include <bits/stdc++.h>

using namespace std;

#define FOR(n,i) for(int i=0;i<n;i++)

int main()
{
    string a,b;
    int aSum = 0;
    int bSum = 0;
    cin >> a >> b;
    FOR(a.size(),i){
        int c = tolower(a[i]);
        int d = tolower(b[i]);
        if (c>d){
            cout << 1;
            return 0;
        } else if(c<d){
            cout << -1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}
