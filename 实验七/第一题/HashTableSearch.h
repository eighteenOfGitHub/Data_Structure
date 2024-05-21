#pragma once

class HashTableSearchBy10000 {//哈希表查找
private:
    static const int TABLE_SIZE = 10000;

    struct HashNode {
        int key;
        int value;
        HashNode* next;

        HashNode(int k, int v) : key(k), value(v), next(nullptr) {}
    };
    HashNode* table[TABLE_SIZE];

public:
    HashTableSearchBy10000() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key, int value) {
        int index = hashFunction(key);
        HashNode* newNode = new HashNode(key, value);

        if (table[index] == nullptr) {
            table[index] = newNode;
        }
        else {
            HashNode* current = table[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    int search(int key) {
        int index = hashFunction(key);

        HashNode* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;  // 未找到目标值
    }
};

class HashTableSearchBy100 {//哈希表查找
private:
    static const int TABLE_SIZE = 100;

    struct HashNode {
        int key;
        int value;
        HashNode* next;

        HashNode(int k, int v) : key(k), value(v), next(nullptr) {}
    };
    HashNode* table[TABLE_SIZE];

public:
    HashTableSearchBy100() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key, int value) {
        int index = hashFunction(key);
        HashNode* newNode = new HashNode(key, value);

        if (table[index] == nullptr) {
            table[index] = newNode;
        }
        else {
            HashNode* current = table[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    int search(int key) {
        int index = hashFunction(key);

        HashNode* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;  // 未找到目标值
    }
}; 