#include <iostream>
#include <vector>
using namespace std;

class MyHashMap {
private:
    static const int SIZE = 1009; // prime number for fewer collisions
    vector<vector<pair<int,int>>> buckets;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashMap() {
        buckets.resize(SIZE);
    }
    
    void put(int key, int value) {
        int h = hash(key);
        for (auto &p : buckets[h]) {
            if (p.first == key) { // update
                p.second = value;
                return;
            }
        }
        buckets[h].push_back({key, value});
    }
    
    int get(int key) {
        int h = hash(key);
        for (auto &p : buckets[h]) {
            if (p.first == key) return p.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int h = hash(key);
        for (auto it = buckets[h].begin(); it != buckets[h].end(); it++) {
            if (it->first == key) {
                buckets[h].erase(it);
                return;
            }
        }
    }
};

// Driver code
int main() {
    MyHashMap myHashMap;
    myHashMap.put(1, 1); 
    myHashMap.put(2, 2); 
    cout << myHashMap.get(1) << endl; // 1
    cout << myHashMap.get(3) << endl; // -1
    myHashMap.put(2, 1); 
    cout << myHashMap.get(2) << endl; // 1
    myHashMap.remove(2); 
    cout << myHashMap.get(2) << endl; // -1
    return 0;
}
