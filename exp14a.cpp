//Program-2: to demonstrate the use of map and iterator in C++
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> mp;

    mp["One"] = 1;
    mp["Two"] = 2;
    mp["Three"] = 3;

    map<string, int>::iterator it = mp.begin();

    while (it != mp.end()) {
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
        it++;
    }
    return 0;
}
