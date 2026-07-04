#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        bool firstMod = true;
        int n,k;
        long long diff=0;
        cin >> n >> k;
        int arr[n];
        for (int i=0;i<n;i++){
            cin >> arr[i];
        }
        sort(arr,arr+n);
        for(int i=n-1;i>=0;i--){
            if (firstMod){
                diff+=arr[i];
            } else{
                diff-=arr[i];
            }
            firstMod = !firstMod;
        }
        diff-=k;
        long long x = 0;
        if(n%2==0) cout << max(diff,x) << endl;
        else{
            cout << max(diff,(long long)arr[0]) << endl;
        }
    }
    return 0;
}
