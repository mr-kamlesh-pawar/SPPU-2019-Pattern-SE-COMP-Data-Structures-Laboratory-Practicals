#include <iostream>
#include <cstdlib>

#define MAX 10

using namespace std;

class Dictionary {
private:
    struct Node {
        int key;
        int value;
        Node* next;
    };

    Node* table[MAX];

    int hash(int key) {
        return key % MAX;
    }

public:
    Dictionary() {
        for (int i = 0; i < MAX; i++)
            table[i] = NULL;
    }

    void insert(int key, int value) {
        int index = hash(key);
        Node* newNode = new Node;
        newNode->key = key;
        newNode->value = value;
        newNode->next = NULL;

        if (table[index] == NULL) {
            table[index] = newNode;
        } else {
            Node* current = table[index];
            while (current->next != NULL)
                current = current->next;
            current->next = newNode;
        }
    }

    int find(int key) {
        int index = hash(key);
        Node* current = table[index];
        while (current != NULL) {
            if (current->key == key)
                return current->value;
            current = current->next;
        }
        return -1; // Key not found
    }

    void remove(int key) {
        int index = hash(key);
        Node* current = table[index];
        Node* prev = NULL;
        while (current != NULL && current->key != key) {
            prev = current;
            current = current->next;
        }
        if (current == NULL) {
            cout << "Key not found" << endl;
            return;
        }
        if (prev == NULL) {
            table[index] = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
    }

    void display() {
        cout << "Dictionary:" << endl;
        for (int i = 0; i < MAX; i++) {
            Node* current = table[i];
            while (current != NULL) {
                cout << "Key: " << current->key << ", Value: " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    Dictionary dict;

    dict.insert(5, 10);
    dict.insert(15, 20);
    dict.insert(25, 30);
    
    cout << "Value for key 15: " << dict.find(15) << endl;

    dict.remove(15);

    dict.display();

    return 0;
}