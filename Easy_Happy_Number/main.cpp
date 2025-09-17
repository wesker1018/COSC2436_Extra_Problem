#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;

        while (n != 1 && !seen.count(n)) {
            seen.insert(n);
            n = getNext(n);
        }
        return n == 1;
    }

private:
    int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int d = n % 10;
            totalSum += d * d;
            n /= 10;
        }
        return totalSum;
    }
};

// Driver code
int main() {
    Solution sol;

    int n1 = 19;
    cout << "Input: " << n1 << " -> " 
         << (sol.isHappy(n1) ? "true" : "false") << endl; // Expected true

    int n2 = 2;
    cout << "Input: " << n2 << " -> " 
         << (sol.isHappy(n2) ? "true" : "false") << endl; // Expected false

    return 0;
}
