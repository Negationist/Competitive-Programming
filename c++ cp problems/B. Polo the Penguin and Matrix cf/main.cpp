#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int n,m,d;
    cin >> n >> m >> d;
    long long sum = 0;
    int Cmod;
    if (n==1&&m==1){
        cout << 0;
        return 0;
    }
    vector<int> arr2;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            int a;
            cin >> a;
            if (i==0&&j==0){
                arr[i][j]=a;
                arr2.push_back(a);
                Cmod = a%d;
                continue;
            }
            if (a%d!=Cmod){
                cout << -1;
                return 0;
            } else{
                arr[i][j]=a;
                arr2.push_back(a);
            }
        }
    }
    sort(arr2.begin(),arr2.end());
    int median = arr2[(n*m)/2];
    for(int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            int z = abs(arr[i][j]-median)/d;
            sum+=z;
        }
    }
    cout << sum;

    return 0;
}
