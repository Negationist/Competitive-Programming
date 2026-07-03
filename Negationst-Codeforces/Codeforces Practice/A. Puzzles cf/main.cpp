#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,best=1000;
    cin >> n >> m;
    vector<int> p(m);
    for (int i=0;i<m;i++){ // O(n)
        cin >> p[i];
    }
    sort(p.begin(), p.end()); // O(nlogn)
    if (m==n){
        best = p.back()-p.front();
        cout << best;
        return 0;
    }
    for (int i=0; i<m-n+1;i++){
        int diff = p[i+n-1]-p[i];
        best = min(best,diff);
    }
    cout << best;

    return 0;
}
