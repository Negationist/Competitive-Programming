#include <bits/stdc++.h>

using namespace std;

int main()
{
    int orgN,m;
    int posMax=0;
    int maxx = 0;
    int minn = 0;
    int pos1 = 0;
    int pos2 = 0;
    cin >> orgN >> m;
    int n=orgN;
    int e[m];
    bool traversed = false;
    for (int i=0;i<m; i++){
        cin >> e[i];
    }
    sort(e, e+m);
    int eR[m];
    for (int i=0;i<m;i++){
        eR[i] = e[i];
    }
        priority_queue<int> maxHeap(eR, eR+m);
         for (int i = 0; i < n; ++i) {
        int largest = maxHeap.top();
        maxx+=largest;
        maxHeap.pop();
        maxHeap.push(largest - 1);
        }
    n=orgN;
    while(n--){
        if (e[pos2]==0){
            pos2+=1;
        }
        minn+=e[pos2];
        e[pos2]--;
    }
    cout << maxx << " " << minn;
    return 0;
}
