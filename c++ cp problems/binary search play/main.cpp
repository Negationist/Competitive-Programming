#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    cout << "How big is the array?" << endl;
    int n; cin >> n;
    cout << "Please enter the elements.\n";
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    cout << "What number are you looking for?\n";
    int num; cin >> num;
    int L = 0, R = n-1;
    while(L<=R){
        cout << "L is "<< L << ". R is " << R << endl;
        int mid = L + (R-L)/2;
        if(a[mid]>=num){
            R = mid -1;
        } else{
            L = mid +1;
        }
    }
    cout << "Element " << a[L] << " found.";
    return 0;
}
