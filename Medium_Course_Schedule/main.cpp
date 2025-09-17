#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph
        for (auto &pre : prerequisites) {
            int course = pre[0], prereq = pre[1];
            graph[prereq].push_back(course);
            indegree[course]++;
        }

        // Initialize queue with courses having indegree = 0
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int finished = 0;
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            finished++;

            for (int next : graph[curr]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        return finished == numCourses;
    }
};

// Driver code
int main() {
    Solution sol;

    int numCourses1 = 2;
    vector<vector<int>> prereq1 = {{1,0}};
    cout << "Example 1: " << (sol.canFinish(numCourses1, prereq1) ? "true" : "false") << endl; // true

    int numCourses2 = 2;
    vector<vector<int>> prereq2 = {{1,0},{0,1}};
    cout << "Example 2: " << (sol.canFinish(numCourses2, prereq2) ? "true" : "false") << endl; // false

    return 0;
}
