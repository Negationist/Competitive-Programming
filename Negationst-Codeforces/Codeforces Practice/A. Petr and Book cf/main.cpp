#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, day;
    cin >> n;
    vector<int> e(7);
    for (int i=0;i<7;i++){
        cin >> e[i];
    }
    for (int i = 0; n>0; i++){
        n=n-e[i%7];
        day = (i%7)+1;
    }
    cout << day;
    return 0;
}
