#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int key, value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head; // dummy head (most recent side)
    Node* tail; // dummy tail (least recent side)

    // Helper: add node right after head
    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // Helper: remove node from list
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Helper: move node to front (most recent)
    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }

    // Helper: pop least recently used node (from tail)
    Node* popTail() {
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        Node* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Update existing node
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            // Create new node
            Node* node = new Node(key, value);
            cache[key] = node;
            addNode(node);

            if (cache.size() > capacity) {
                Node* lru = popTail();
                cache.erase(lru->key);
                delete lru;
            }
        }
    }
};

int main() {
    LRUCache lRUCache(2);
    lRUCache.put(1, 1); // cache: {1=1}
    lRUCache.put(2, 2); // cache: {1=1, 2=2}
    cout << lRUCache.get(1) << endl; // return 1
    lRUCache.put(3, 3); // evicts key 2, cache: {1=1, 3=3}
    cout << lRUCache.get(2) << endl; // return -1 (not found)
    lRUCache.put(4, 4); // evicts key 1, cache: {4=4, 3=3}
    cout << lRUCache.get(1) << endl; // return -1
    cout << lRUCache.get(3) << endl; // return 3
    cout << lRUCache.get(4) << endl; // return 4
    return 0;
}
