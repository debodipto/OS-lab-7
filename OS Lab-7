#include <iostream>
#include <cmath>
#include <limits.h>

using namespace std;

int main() {
    int requests[] = {0, 14, 41, 53, 65, 67, 98, 122, 124, 183, 199};
    int n = sizeof(requests) / sizeof(requests[0]);
    int visited[100] = {0};

    int head = 53;
    int total_seek = 0;

    for (int i = 0; i < n; i++) {
        int min_diff = INT_MAX;
        int index = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int diff = abs(head - requests[j]);
                if (diff < min_diff) {
                    min_diff = diff;
                    index = j;
                }
            }
        }

        visited[index] = 1;
        total_seek += abs(head - requests[index]);
        head = requests[index];
    }

    cout << "Total number of seek operations = " << total_seek << endl;
    return 0;
}
