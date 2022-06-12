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
};

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

void HashTable::insertItem(int key, string value) {
    int hashValue = hashFunction(key); // equal to Index -> Idx
    auto& cell = table[hashValue];
    auto bItr = begin(cell); // std::begin, std::end - some iterator
    bool keyExist = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExist = true;
            bItr->second = value;
            cout << "[WARN] Key " << key << "exists. Value " << value << "replaced." << endl;
            break;
        }
    }
    if (!keyExist) {
        cell.emplace_back(key, value);
    }

    return;
}

void HashTable::removeItem(int key) {
    int hashValue = hashFunction(key); // equal to Index -> Idx
    auto &cell = table[hashValue];
    auto bItr = begin(cell); // std::begin, std::end - some iterator
    bool keyExist = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key)
        {
            keyExist = true;
            bItr = cell.erase(bItr);
            cout << "[INFO] Key " << key << " exists. Pair removed." << endl;
            break;
        }
    }
    if (!keyExist) {
        cout << "[WARN] Key not found. Pair not removed." << endl;
    }

    return;
}

void HashTable::printTable() {
    for (int i{}; i < hashGroups; i++) {
        if (table[i].size() == 0) continue;
        
        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++) {
            // cout << "[INFO] Pair: " << bItr->first << " -> " << bItr->second << endl;
            cout << "[INFO] Pair: " << bItr->first << " -> " << bItr->second << ", hash: " << hashFunction(bItr->first) << endl;
        }
    }

    return;
}

int main() {
    HashTable ht;
    ht.insertItem(100, "Alice_100");
    ht.insertItem(101, "Bob_101");

    ht.insertItem(99, "Bob_99");
    ht.insertItem(98, "Bob_98");
    ht.insertItem(97, "Bob_97");
    ht.insertItem(96, "Bob_96");

    ht.insertItem(300, "Bob_300");
    ht.insertItem(400, "Bob_400");
    ht.insertItem(500, "Bob_500");
    ht.insertItem(600, "Bob_600");
    ht.insertItem(700, "Bob_700");
    
    ht.insertItem(7, "Bob_7");
    ht.insertItem(8, "Bob_8");

    ht.removeItem(700);
    ht.removeItem(700);

    ht.printTable();
    
    if (ht.isEmpty()){
        return 1;
    }
    
    return 0;
}