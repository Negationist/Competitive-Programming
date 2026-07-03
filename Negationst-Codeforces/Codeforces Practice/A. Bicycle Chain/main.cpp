#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    double a[n];
    double currentRatio;
    double ratioMax=0;
    int num = 0;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    int m;
    cin >> m;
    double b[m];
    for (int i=0; i<m; i++){
        cin >> b[i];
    }
    for (int c=m-1;c>=0; c--){ // O(nm)
        for (int d=n-1; d>=0; d--){
            currentRatio = b[c]/a[d];
            double rounded = round(currentRatio);
            if(rounded==currentRatio){
               if(currentRatio>ratioMax){
                    ratioMax = currentRatio;
                    num = 1;
               }
               else if (currentRatio==ratioMax){
                num++;
               }
            }
        }
    }
    cout << num << endl;
    return 0;
}
