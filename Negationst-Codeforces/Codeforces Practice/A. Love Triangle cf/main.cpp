#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        arr[i] = a-1;
    }
    for(int i=0;i<n;i++){
        int first = arr[i];
        int second = arr[first];
        if (arr[second]==i){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
