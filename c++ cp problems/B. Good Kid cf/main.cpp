#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--){
        int a;
        long long product = 1;
        int mn = INT_MAX;
        int index;
        cin >> a;
        int e[a];
        for (int i=0;i<a;i++){
            cin >> e[i];
            if (e[i]<=mn){
                index = i;
            }
            mn = min(mn,e[i]);
        }
        e[index]++;
        for (int i=0;i<a;i++){
            product*=e[i];
        }
        cout << product << endl;
    }
    return 0;
}
