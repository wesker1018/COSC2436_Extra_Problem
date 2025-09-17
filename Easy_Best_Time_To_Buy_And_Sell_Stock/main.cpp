#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;  // track the lowest price so far
        int maxProfit = 0;       // track the maximum profit so far

        for (int price : prices) {
            minPrice = min(minPrice, price);                 // update minimum price
            maxProfit = max(maxProfit, price - minPrice);    // check profit if selling today
        }
        return maxProfit;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> prices1 = {7,1,5,3,6,4};
    cout << "Max Profit (Example 1): " << sol.maxProfit(prices1) << endl;

    // Example 2
    vector<int> prices2 = {7,6,4,3,1};
    cout << "Max Profit (Example 2): " << sol.maxProfit(prices2) << endl;

    return 0;
}
