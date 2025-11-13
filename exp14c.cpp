//Program-4: to demonstrate the use of range-based for loop in C++

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers = {1, 100, 10, 70, 100};

    cout << "Numbers are:";
    for (auto num : numbers) {
        cout << " " << num;
    }

    return 0;
}
