#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int q;
    cin >> q;
    int sum = 0;
    int ways=0;
    for (int i =0; i<q; i++){
        int a;
        cin >> a;
        sum +=a;
    }
    for (int i=sum+1; i<=sum+5; i++){
        if (i%(q+1) != 1){
            ways++;
        }
    }  cout << ways;
    return 0;
}
