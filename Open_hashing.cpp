#include <iostream>
#include <list>
#include <vector>
#include <string>

class HashTable {
private:
    static const int TABLE_SIZE = 10; // Size of the hash table

    // Define a structure to hold key-value pairs
    struct KeyValuePair {
        std::string key;
        std::string value;
    };

    // Define a vector of linked lists to represent the hash table
    std::vector<std::list<KeyValuePair>> table;

    // Hash function to map a string key to an index in the table
    int hash(const std::string& key) {
        int hashValue = 0;
        for (char ch : key) {
            hashValue += ch;
        }
        return hashValue % TABLE_SIZE;
    }

public:
    HashTable() {
        // Initialize the table with empty lists
        table.resize(TABLE_SIZE);
    }

    // Insert a key-value pair into the hash table
    void insert(const std::string& key, const std::string& value) {
        int index = hash(key);

        // Search for the key in the linked list at the calculated index
        for (auto& kv : table[index]) {
            if (kv.key == key) {
                // Key already exists, update the value
                kv.value = value;
                return;
            }
        }

        // Key doesn't exist, insert a new key-value pair
        KeyValuePair kvp;
        kvp.key = key;
        kvp.value = value;
        table[index].push_back(kvp);
    }

    // Search for a value using a key
    std::string search(const std::string& key) {
        int index = hash(key);

        // Search for the key in the linked list at the calculated index
        for (const auto& kv : table[index]) {
            if (kv.key == key) {
                return kv.value; // Key found, return the associated value
            }
        }

        return "Key not found"; // Key not found in the hash table
    }
};

int main() {
    HashTable hashTable;

    // Insert some key-value pairs
    hashTable.insert("apple", "red");
    hashTable.insert("banana", "yellow");
    hashTable.insert("grape", "purple");

    // Search for values using keys
    std::cout << "Color of apple: " << hashTable.search("apple") << std::endl;
    std::cout << "Color of banana: " << hashTable.search("banana") << std::endl;
    std::cout << "Color of grape: " << hashTable.search("grape") << std::endl;
    std::cout << "Color of orange: " << hashTable.search("orange") << std::endl;

    return 0;
}
