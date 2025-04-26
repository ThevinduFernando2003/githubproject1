#include <iostream>
#include <list>
using namespace std;

class HashTable {
private:
    static const int SIZE = 10; // Size of the hash table
    list<pair<int, int>> table[SIZE];

    int hashfunc(int key) {
        return key % SIZE; // Simple modulus-based hash function
    }

public:
    void insert(int key, int value) {
        int index = hashfunc(key);
        for (auto &pair : table[index]) {
            if (pair.first == key) {
                pair.second = value; // Update existing key
                return;
            }
        }
        table[index].emplace_back(key, value); // Insert new key-value pair
    }

    int lookup(int key) {
        int index = hashfunc(key);
        for (auto &pair : table[index]) {
            if (pair.first == key) {
                return pair.second; // Return the value if key found
            }
        }
        return -1; // Indicate not found
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << "Index " << i << ": ";
            for (auto &pair : table[i]) {
                cout << "(" << pair.first << ", " << pair.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(12, 120);
    
    cout << "Lookup 2: " << ht.lookup(2) << endl;
    cout << "Lookup 12: " << ht.lookup(12) << endl;
    cout << "Lookup 5: " << ht.lookup(5) << endl;
    
    ht.display();
    
    return 0;
}


#include <iostream>
#include <string>
using namespace std;

struct HashTable {
    int MAX_LENGTH = 3;
    string *passwords = new string[MAX_LENGTH];

    void initialize_hashtable() {
        for (int i = 0; i < MAX_LENGTH; i++) {
            passwords[i].clear();
        }
    }

    bool isFull() {
        for (int i = 0; i < MAX_LENGTH; i++) {
            if (passwords[i].empty()) {
                return false;
            }
        }
        return true;
    }

    int hashfunc(string user_name) {
        int sum = 0;
        for (char c : user_name) {
            sum += static_cast<int>(c); // get the ASCII value
        }
        return sum % MAX_LENGTH;
    }

    bool is_slot_empty(int hash) {
        return passwords[hash].empty();
    }

    int insert(string user_name, string user_password) {
        int hash = hashfunc(user_name);
        if (is_slot_empty(hash)) {
            passwords[hash] = user_password;
            return 0; // Success
        }
        return 1; // Slot already occupied
    }

    string hash_lookup(string user_name) {
        int hash = hashfunc(user_name);
        if (!is_slot_empty(hash)) {
            return passwords[hash]; // Return found password
        }
        return ""; // Not found
    }

    int delete_item(string user_name) {
        int hash = hashfunc(user_name);
        if (is_slot_empty(hash)) {
            return 1; // Nothing to delete
        }
        passwords[hash].clear();
        return 0; // Success
    }

    void print_hashtable() {
        for (int i = 0; i < MAX_LENGTH; i++) {
            cout << "[" << i << "] --> " << passwords[i] << "\n";
        }
    }
};

int main() {
    HashTable *hashtbl = new HashTable;
    hashtbl->initialize_hashtable();
    cout << hashtbl->isFull() << "\n";

    int command = 0;
    string user_name;
    string password;
    while (command != -1) {
        cin >> command;
        switch (command) {
        case 1:
            cin >> user_name >> password;
            cout << "Inserting " << user_name << "...\n";
            cout << (hashtbl->insert(user_name, password) ? "Failed" : "Succeeded") << "\n";
            break;
        case 2:
            cin >> user_name;
            cout << "Deleting " << user_name << "...\n";
            cout << (hashtbl->delete_item(user_name) ? "Failed" : "Succeeded") << "\n";
            break;
        case 3:
            cin >> user_name;
            cout << "Looking up " << user_name << "...\n";
            {
                string found_password = hashtbl->hash_lookup(user_name);
                if (found_password.empty()) {
                    cout << "Not found" << "\n";
                } else {
                    cout << "Found: " << found_password << "\n";
                }
            }
            break;
        case 4:
            hashtbl->print_hashtable();
            break;
        case -1:
            break;
        }
    }
    delete hashtbl;
    return 0;
}


#include <iostream>
#include <string>
using namespace std;

struct Node {
    string user_name;
    string password;
    Node *link;
};

struct LinkedList {
    Node *head = NULL;
    int length = 0;

    void insert(string user_name, string password) {
        Node *temp = new Node;
        temp->user_name = user_name;
        temp->password = password;
        temp->link = head;
        head = temp;
        length++;
    }

    string search(string user_name) {
        Node *temp = head;
        while (temp != NULL) {
            if (temp->user_name == user_name) {
                return temp->password;
            }
            temp = temp->link;
        }
        return "";
    }

    void print_list() {
        Node *temp = head;
        cout << "[";
        while (temp != NULL) {
            cout << temp->user_name << " ";
            temp = temp->link;
        }
        cout << "]\n";
    }
};

struct HashTable {
    int MAX_LENGTH = 3;
    LinkedList *passwords = new LinkedList[MAX_LENGTH];

    int hashfunc(string user_name) {
        int sum = 0;
        for (char c : user_name) {
            sum += static_cast<int>(c);
        }
        return sum % MAX_LENGTH;
    }

    int insert(string user_name, string user_password) {
        int hash = hashfunc(user_name);
        passwords[hash].insert(user_name, user_password);
        return 0;
    }

    string hash_lookup(string user_name) {
        int hash = hashfunc(user_name);
        return passwords[hash].search(user_name);
    }

    void print_hashtable() {
        for (int i = 0; i < MAX_LENGTH; i++) {
            cout << "[" << i << "] --> ";
            passwords[i].print_list();
        }
    }
};

int main() {
    HashTable *hashtbl = new HashTable;

    int command = 0;
    string user_name;
    string password;
    while (command != -1) {
        cin >> command;
        switch (command) {
        case 1:
            cin >> user_name >> password;
            cout << "Inserting " << user_name << "...\n";
            cout << (hashtbl->insert(user_name, password) ? "Failed" : "Succeeded") << "\n";
            break;
        case 2:
            cin >> user_name;
            cout << "Looking up " << user_name << "...\n";
            {
                string found_password = hashtbl->hash_lookup(user_name);
                if (found_password.empty()) {
                    cout << "Not found\n";
                } else {
                    cout << "Found: " << found_password << "\n";
                }
            }
            break;
        case 3:
            hashtbl->print_hashtable();
            break;
        case -1:
            break;
        }
    }
    delete hashtbl;
    return 0;
}


int hash_lookup(string user_name) {
    int hash = hashfunc(user_name);
    string found_password = passwords[hash].search(user_name);
    if (!found_password.empty()) {
        cout << "Password: " << found_password << "\n";
        return 0;
    }
    cout << "Not found\n";
    return 1;
}

///////////////////////////////////////////////////////////////

/* An implementation of a LinkedList has been provided to you in the given answer template.

Complete the following functions using the given instructions:

hashfunc: Hash a given username by obtaining the sum of the ASCII values of the characters of the username. 
You may use your function from the previous question.
insert: Hash a given username using hashfunc and insert the password. Return 0 if the insertion was successful and 1 if it failed.
hash_lookup: Hash a given username using hashfunc and find its password. 
Use the search function of the LinkedList struct to print the password. 
Return 0 if the hash exists in the Hashtable or 1 if not.*/

#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string user_name;
    string password;
    Node *link;
};

struct LinkedList
{

    Node *head = NULL;
    Node *tail = NULL;

    int length = 0;

    void insert(string user_name, string password)
    {
        if (head == NULL)
        {
            Node *temp;
            temp = new Node;
            temp->user_name = user_name;
            temp->password = password;

            temp->link = NULL;
            head = temp;
            length++;
        }
        else
        {
            Node *temp;
            Node *tail;

            temp = new Node;
            temp->user_name = user_name;
            temp->password = password;
            temp->link = NULL;
            tail = head;
            while (true)
            {

                if (tail->link == NULL)
                {
                    break;
                }
                else
                {
                    tail = tail->link;
                }
            }
            tail->link = temp;
            length++;
        }
    }

    void search(string user_name)
    {
        Node *temp = head;
        for (int i = 0; i < length; i++)
        {
            if (temp->user_name == user_name)
            {
                cout << "Password: " << temp->password << "\n";
                break;
            }
            else
            {
                temp = temp->link;
            }
        }
    }

    void print_list()
    {
        if (head == NULL)
        {
            cout << "[]" << endl;
        }
        else
        {
            Node *temp = head;
            cout << "[";
            while (temp != NULL)
            {
                cout << temp->user_name << ", ";
                temp = temp->link;
            }
            cout << "]" << endl;
        }
    }
};

struct HashTable
{
    int MAX_LENGTH = 3;
    int MAX_CHAIN_LENGTH = 2;
    LinkedList *passwords = new LinkedList[MAX_LENGTH];
    bool isFull()
    {
        bool full = true;
        for (int i = 0; i < MAX_LENGTH; i++)
        {
            if (passwords[i].head == NULL)
            {
                full = false;
            }
        }
        return full;
    }
    int hashfunc(string user_name)
    {
        int sum = 0;
        int hash = 0;
        // <--- ADD YOUR CODE HERE --->
        
    }
    bool is_slot_empty(int hash)
    {
        bool empty;
        if (passwords[hash].head == NULL)
        {
            empty = true;
        }
        else
        {
            empty = false;
        }
        return empty;
    }
    int insert(string user_name, string user_password)
    {
        int hash;
        // <--- ADD YOUR CODE HERE --->
        
    }
    void print_hashtable()
    {
        for (int i = 0; i < MAX_LENGTH; i++)
        {
            cout << "[" << i << "]-->";
            passwords[i].print_list();
        }
    }
    int hash_lookup(string user_name)
    {
        int hash;
        bool empty;
        hash = hashfunc(user_name);
        empty = is_slot_empty(hash);
        // <--- ADD YOUR CODE HERE --->
        
    }
};

int main()
{
    HashTable *hashtbl = new HashTable;
    cout << hashtbl->isFull() << "\n";

    int command = 0;
    string user_name;
    string password;
    while (command != -1)
    {
        /* code */
        cin >> command;
        switch (command)
        {
        case 1:
            /* insert the new item*/
            cin >> user_name;
            cin >> password;
            cout << "Inserting " << user_name << "...\n";
            cout << (hashtbl->insert(user_name, password) ? "Failed" : "Succeeded") << "\n";
            break;
        case 2:
            /* hash lookup password*/
            cin >> user_name;
            cout << "Looking up " << user_name << "...\n";
            cout << (hashtbl->hash_lookup(user_name) ? "Not found" : "Found") << "\n";
            break;
        case 3:
            hashtbl->print_hashtable();
            break;
        case -1:
            break;
        }
    }
    return 0;
}


#include <iostream>
#include <string>
using namespace std;

struct Node {
    string user_name;
    string password;
    Node *link;
};

struct LinkedList {
    Node *head = NULL;
    Node *tail = NULL;
    int length = 0;

    void insert(string user_name, string password) {
        Node *temp = new Node;
        temp->user_name = user_name;
        temp->password = password;
        temp->link = NULL;

        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->link = temp;
            tail = temp;
        }
        length++;
    }

    string search(string user_name) {
        Node *temp = head;
        while (temp != NULL) {
            if (temp->user_name == user_name) {
                return temp->password;
            }
            temp = temp->link;
        }
        return ""; // Return empty string if not found
    }

    void print_list() {
        if (head == NULL) {
            cout << "[]" << endl;
        } else {
            Node *temp = head;
            cout << "[";
            while (temp != NULL) {
                cout << temp->user_name << ", ";
                temp = temp->link;
            }
            cout << "]" << endl;
        }
    }
};

struct HashTable {
    int MAX_LENGTH = 3;
    LinkedList *passwords = new LinkedList[MAX_LENGTH];

    bool isFull() {
        for (int i = 0; i < MAX_LENGTH; i++) {
            if (passwords[i].head == NULL) {
                return false;
            }
        }
        return true;
    }

    int hashfunc(string user_name) {
        int sum = 0;
        for (char c : user_name) {
            sum += static_cast<int>(c);
        }
        return sum % MAX_LENGTH;
    }

    bool is_slot_empty(int hash) {
        return passwords[hash].head == NULL;
    }

    int insert(string user_name, string user_password) {
        int hash = hashfunc(user_name);
        passwords[hash].insert(user_name, user_password);
        return 0; // Always successful
    }

    int hash_lookup(string user_name) {
        int hash = hashfunc(user_name);
        string password = passwords[hash].search(user_name);
        
        if (!password.empty()) {
            cout << "Password: " << password << "\n";
            return 0;
        }
        cout << "Not found\n";
        return 1;
    }

    void print_hashtable() {
        for (int i = 0; i < MAX_LENGTH; i++) {
            cout << "[" << i << "]-->";
            passwords[i].print_list();
        }
    }
};

int main() {
    HashTable *hashtbl = new HashTable;
    cout << hashtbl->isFull() << "\n";

    int command = 0;
    string user_name;
    string password;
    while (command != -1) {
        cin >> command;
        switch (command) {
        case 1:
            cin >> user_name >> password;
            cout << "Inserting " << user_name << "...\n";
            cout << (hashtbl->insert(user_name, password) ? "Failed" : "Succeeded") << "\n";
            break;
        case 2:
            cin >> user_name;
            cout << "Looking up " << user_name << "...\n";
            cout << (hashtbl->hash_lookup(user_name) ? "Not found" : "Found") << "\n";
            break;
        case 3:
            hashtbl->print_hashtable();
            break;
        case -1:
            break;
        }
    }

    delete hashtbl;
    return 0;
}
