#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int e[5][5],maxSum=0;
    FOR(i,5){
        FOR(j,5){
            cin >> e[i][j];
        }
    }

    vector<int> p;
    for (int i = 0; i < 5; i++) {
        p.push_back(i);
    }
    do {
        int sum = e[p[0]][p[1]]+e[p[1]][p[0]]+2*e[p[2]][p[3]]+2*e[p[3]][p[2]]+2*e[p[3]][p[4]]+2*e[p[4]][p[3]]+e[p[1]][p[2]]+e[p[2]][p[1]];
        maxSum = max(sum,maxSum);
    } while (next_permutation(p.begin(),p.end()));

    cout << maxSum;

    return 0;
}
