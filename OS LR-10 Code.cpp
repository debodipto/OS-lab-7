#include <iostream>
#include <vector>
#include <algorithm>

int fifo_page_replacement(const std::vector<int>& pages, int capacity) {
    std::vector<int> memory;
    int page_faults = 0;
    int index = 0;

    for (int page : pages) {
        if (std::find(memory.begin(), memory.end(), page) == memory.end()) {
            if (memory.size() < capacity) {
                memory.push_back(page);
            } else {
                memory[index] = page;
                index = (index + 1) % capacity;
            }
            page_faults += 1;
        }
        std::cout << "Page: " << page << " -> Memory: ";
        for (int mem_page : memory) {
            std::cout << mem_page << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\nTotal Page Faults: " << page_faults << std::endl;
    return page_faults;
}

int main() {
    std::vector<int> pages = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int capacity = 3;
    fifo_page_replacement(pages, capacity);
    return 0;
}
