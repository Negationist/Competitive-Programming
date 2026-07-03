#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,q; long long V = 0; long long P = 0;
    int pos;
    cin >> n;
    int e[n];
    unordered_map<int,int> map;

    for (int i=0;i<n;i++){
        cin >> e[i];
        map[e[i]] = i;
    }
    cin >> q;
    while (q--){
        int a;
        cin >> a;
        auto it = map.find(a);
        V+=(it->second)+1;
        P+=(n-1-(it->second)+1);
        }
    cout << V << " " << P;
    return 0;
}

