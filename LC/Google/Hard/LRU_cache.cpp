/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache(2);

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

Your LRUCache object will be instantiated and called as such:
LRUCache obj = new LRUCache(capacity);
int param_1 = obj.get(key);
obj.put(key, value);
*/

#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
public:
    int cap;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> used;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        unordered_map<int, pair<int, list<int>::iterator>>::iterator it = cache.find(key);
        if (it != cache.end()) {
            updateList(it);
            return it->second.first;
        }
        return -1;
    }

    void put(int key, int value) {
        unordered_map<int, pair<int, list<int>::iterator>>::iterator it = cache.find(key);
        if (it == cache.end()) {
            if (cache.size() == cap) {
                cache.erase(used.back());
                used.pop_back();
            }

            used.push_front(key);
        }
        else
            updateList(it);
        cache[key] = {value, used.begin()};
    }

    void updateList(unordered_map<int, pair<int, list<int>::iterator>>::iterator it) {
        int key = it->first;
        used.erase(it->second.second);
        used.push_front(key);
        it->second.second = used.begin();
    }

    void print() {
        for (auto it = used.begin(); it != used.end(); it++) {
            auto it2 = cache.find(*it);
            cout << "\n Key: " << it2->first << " Value: " << it2->second.first;
        }
    }
};

int main() {

    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);

    cache.print();

    cout << "\n Cache get 1: " << cache.get(1);       // returns 1

    cache.put(3, 3);                                  // evicts key 2

    cache.print();

    cout << "\n Cache get 2: " << cache.get(2);       // returns -1 (not found)

    cache.put(4, 4);                                  // evicts key 1

    cache.print();

    cout << "\n Cache get 1: " << cache.get(1);       // returns -1 (not found)
    cout << "\n Cache get 3: " << cache.get(3);       // returns 3
    cout << "\n Cache get 4: " << cache.get(4);       // returns 4

    cout << "\n\n";
    return 0;
}
