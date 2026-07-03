#include <iostream>
#include <vector>

using namespace std;

int main()
{
vector<char> kids;
bool swapped = false;
int n,t;
cin >> n >> t;
int skipme;
while (n--){
    char entry;
    cin >> entry;
    kids.push_back(entry);
}
while (t--){
for (int i = 0; i<kids.size(); i++){
    if (kids[i] == 'B' && kids[i+1] == 'G'){
        swap(kids[i], kids[i + 1]);
        i++;
    }
}
}
    for (auto item : kids){
        cout << item;
    }
    return 0;
}
