#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    double m;
    int l=0;
    int kid=1;
    cin >> n >> m;
    vector<int> e(n);
    for (int i=0;i<n;i++){
        cin >> e[i];
    }
    for (int i=0;i<n;i++){
        if(ceil(e[i]/m)>=l){
            l = ceil(e[i]/m);
            kid = i+1;
        }
    }

    cout << kid;
    return 0;
}
