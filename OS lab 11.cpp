#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;
class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {}

    int lru_page_replacement(vector<int>& pages) {
        int page_faults = 0;
        for (int page : pages) {
            if (memory.find(page) == memory.end()) {
                page_faults++;
                if (memory.size() == capacity) {
                    int lru_page = order.back();
                    order.pop_back();
                    memory.erase(lru_page);
                }} else {
                order.remove(page);
            }
            order.push_front(page);
            memory[page] = true;
            cout << "Page: " << page << " -> Memory: ";
            for (int p : order) {
                cout << p << " ";
            }
            cout << endl;
        }
        cout << "\nTotal Page Faults: " << page_faults << endl;
        return page_faults;}
private:
    int capacity;
    list<int> order;
    unordered_map<int, bool> memory;
};
int main() {
    vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4};
    int capacity = 3;
    LRUCache lru(capacity);
    lru.lru_page_replacement(pages);
    return 0;
}
