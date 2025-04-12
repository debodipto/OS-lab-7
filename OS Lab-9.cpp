#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int main() {
    int requests[] = {0, 14, 41, 53, 65, 67, 98, 122, 124, 183, 199};
    int n = sizeof(requests) / sizeof(requests[0]);
    int head = 53;
    int total_seek = 0;
    int disk_size = 200;

    sort(requests, requests + n);
    int index;
    for (int i = 0; i < n; i++) {
        if (requests[i] >= head) {
            index = i;
            break;
        } }
    cout << "Seek Sequence: ";

    for (int i = index; i < n; i++) {
        cout << requests[i] << " ";
        total_seek += abs(head - requests[i]);
        head = requests[i];
    }

    if (head != disk_size - 1) {
        total_seek += abs(head - (disk_size - 1));
        head = disk_size - 1;
    }

    total_seek += head;
    head = 0;
    for (int i = 0; i < index; i++) {
        cout << requests[i] << " ";
        total_seek += abs(head - requests[i]);
        head = requests[i];
    }
    cout << "\nTotal number of seek operations = " << total_seek << endl;
    return 0;
}
