//Program-3: to demonstrate the use of list container in C++
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> g1 = {1, 2, 5, 8};

    for (auto i : g1) {
        cout << i << " ";
    }

    return 0;
}
