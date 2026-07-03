#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int n,k,least,sum=0,j=1;
    cin >> n >> k;
    int arr[n];
    for(int i=0;i<k;i++){
        int a;
        cin >> a;
        arr[i]=a;
        sum+=a;
    }
    least = sum;
    for(int i=0;i<n-k;i++){
        int a;
        cin >> a;
        sum+=a;
        arr[i+k] = a;
        sum-=arr[i];
        if(sum < least){
            least = sum;
            j = i+2;
        }
    }
    cout << j;
    return 0;
}
