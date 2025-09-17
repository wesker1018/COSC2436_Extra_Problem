#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class UnionFind {
private:
    vector<int> parent;

public:
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX != rootY) {
            parent[rootY] = rootX;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        UnionFind uf(n);
        unordered_map<string, int> emailToIndex;

        // Step 1: Union accounts with common emails
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (emailToIndex.count(email)) {
                    uf.unite(i, emailToIndex[email]);
                } else {
                    emailToIndex[email] = i;
                }
            }
        }

        // Step 2: Group emails by root parent
        unordered_map<int, vector<string>> groups;
        for (auto &p : emailToIndex) {
            string email = p.first;
            int idx = uf.find(p.second);
            groups[idx].push_back(email);
        }

        // Step 3: Build result
        vector<vector<string>> result;
        for (auto &g : groups) {
            vector<string> emails = g.second;
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), accounts[g.first][0]); // add name
            result.push_back(emails);
        }
        return result;
    }
};

// ---------------- Driver Code ----------------
int main() {
    Solution sol;

    vector<vector<string>> accounts1 = {
        {"John","johnsmith@mail.com","john_newyork@mail.com"},
        {"John","johnsmith@mail.com","john00@mail.com"},
        {"Mary","mary@mail.com"},
        {"John","johnnybravo@mail.com"}
    };

    auto res1 = sol.accountsMerge(accounts1);
    cout << "Example 1 Output:\n";
    for (auto &acc : res1) {
        cout << "[";
        for (auto &s : acc) cout << s << " ";
        cout << "]\n";
    }

    vector<vector<string>> accounts2 = {
        {"Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"},
        {"Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"},
        {"Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"},
        {"Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"},
        {"Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"}
    };

    auto res2 = sol.accountsMerge(accounts2);
    cout << "Example 2 Output:\n";
    for (auto &acc : res2) {
        cout << "[";
        for (auto &s : acc) cout << s << " ";
        cout << "]\n";
    }

    return 0;
}
