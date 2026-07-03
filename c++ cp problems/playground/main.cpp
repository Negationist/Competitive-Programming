#include <iostream>
#include <vector>

using namespace std;

int n;  // This should be initialized with the size of the set
vector<int> subset;  // This will hold the current subset

// Function to process the subset
void processSubset() {
    // For example, print the subset
    cout << "{ ";
    for (int x : subset) {
        cout << x << " ";
    }
    cout << "}" << endl;
}

// Recursive function to generate all subsets
void search(int k) {
    if (k == n) {
        // If we've considered all elements, process the subset
        processSubset();
    } else {
        // Case 1: Don't include k in the subset
        search(k + 1);

        // Case 2: Include k in the subset
        subset.push_back(k);
        search(k + 1);
      subset.pop_back();  // Backtrack
    }
}

int main() {
    n = 3;  // For example, working with a set of size 3

    // Start the search from the first element (index 0)
    search(0);

    return 0;
}
