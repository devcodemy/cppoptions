#include <iostream>
#include <list>
#include <cstring>
using namespace std;

// Hashtable to implement 905, Jimmy

class HashTable {
    private:
        static const int hashGroups = 10;
        list<pair<int, string>> table[hashGroups]; // List 1, Index 0; List 2, Index 1, ...
    
    public:
        bool isEmpty() const ;
        int hashFunction(int key);
        void insertItem(int key, string value);
        void removeItem(int key);
        string searchTable(int key);
        void printTable();
}

bool HashTable::isEmpty() const {
    int sum{};
    for (int i{}; i < hashGroups; i++) {
        sum += table[i].size();
    }
    if (!sum) {
        return true;
    }
    return false;
}

int HashTable::hashFunction(int key) {
    return key % hashGroups; // Key: 905, in return, this function will spit out 5.
}
