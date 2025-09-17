#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }

private:
    void backtrack(vector<int>& candidates, int target, int start, 
                   vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (target < 0) return;

        for (int i = start; i < candidates.size(); i++) {
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, current, result); // allow reuse
            current.pop_back();
        }
    }
};

// ---------------- Driver Code ----------------
int main() {
    Solution sol;

    vector<int> candidates1 = {2,3,6,7};
    int target1 = 7;
    auto res1 = sol.combinationSum(candidates1, target1);
    cout << "Example 1: ";
    for (auto &comb : res1) {
        cout << "[";
        for (int x : comb) cout << x << " ";
        cout << "] ";
    }
    cout << endl;

    vector<int> candidates2 = {2,3,5};
    int target2 = 8;
    auto res2 = sol.combinationSum(candidates2, target2);
    cout << "Example 2: ";
    for (auto &comb : res2) {
        cout << "[";
        for (int x : comb) cout << x << " ";
        cout << "] ";
    }
    cout << endl;

    vector<int> candidates3 = {2};
    int target3 = 1;
    auto res3 = sol.combinationSum(candidates3, target3);
    cout << "Example 3: ";
    for (auto &comb : res3) {
        cout << "[";
        for (int x : comb) cout << x << " ";
        cout << "] ";
    }
    cout << endl;

    return 0;
}
