#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Contact {
    int id;
    string name;
    string phone;
    string email;
    string address;
};

class PhonebookManager {
private:
    const string filename = "phonebook.txt";
    
    int getNextId() {
        vector<Contact> contacts = getAllContacts();
        if (contacts.empty()) return 1;
        return contacts.back().id + 1;
    }
    
public:
    // Add a new contact
    bool addContact(const Contact& contact) {
        ofstream file(filename, ios::app);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return false;
        }
        
        Contact newContact = contact;
        newContact.id = getNextId();
        
        file << newContact.id << "|" 
             << newContact.name << "|" 
             << newContact.phone << "|" 
             << newContact.email << "|" 
             << newContact.address << endl;
        
        file.close();
        cout << "Contact added successfully! ID: " << newContact.id << endl;
        return true;
    }
    
    // Get all contacts
    vector<Contact> getAllContacts() {
        vector<Contact> contacts;
        ifstream file(filename);
        
        if (!file.is_open()) {
            return contacts;
        }
        
        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;
            
            Contact c;
            stringstream ss(line);
            string token;
            
            getline(ss, token, '|');
            c.id = stoi(token);
            getline(ss, c.name, '|');
            getline(ss, c.phone, '|');
            getline(ss, c.email, '|');
            getline(ss, c.address, '|');
            
            contacts.push_back(c);
        }
        
        file.close();
        return contacts;
    }
    
    // Search contacts by name
    vector<Contact> searchByName(const string& name) {
        vector<Contact> results;
        vector<Contact> all = getAllContacts();
        
        string lowerName = name;
        transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
        
        for (const auto& contact : all) {
            string lowerContactName = contact.name;
            transform(lowerContactName.begin(), lowerContactName.end(), 
                     lowerContactName.begin(), ::tolower);
            
            if (lowerContactName.find(lowerName) != string::npos) {
                results.push_back(contact);
            }
        }
        
        return results;
    }
    
    // Update contact
    bool updateContact(int id, const Contact& updatedContact) {
        vector<Contact> contacts = getAllContacts();
        bool found = false;
        
        for (auto& contact : contacts) {
            if (contact.id == id) {
                contact.name = updatedContact.name;
                contact.phone = updatedContact.phone;
                contact.email = updatedContact.email;
                contact.address = updatedContact.address;
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << "Contact not found!" << endl;
            return false;
        }
        
        // Rewrite file
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return false;
        }
        
        for (const auto& contact : contacts) {
            file << contact.id << "|" 
                 << contact.name << "|" 
                 << contact.phone << "|" 
                 << contact.email << "|" 
                 << contact.address << endl;
        }
        
        file.close();
        cout << "Contact updated successfully!" << endl;
        return true;
    }
    
    // Delete contact
    bool deleteContact(int id) {
        vector<Contact> contacts = getAllContacts();
        auto it = remove_if(contacts.begin(), contacts.end(),
                           [id](const Contact& c) { return c.id == id; });
        
        if (it == contacts.end()) {
            cout << "Contact not found!" << endl;
            return false;
        }
        
        contacts.erase(it, contacts.end());
        
        // Rewrite file
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return false;
        }
        
        for (const auto& contact : contacts) {
            file << contact.id << "|" 
                 << contact.name << "|" 
                 << contact.phone << "|" 
                 << contact.email << "|" 
                 << contact.address << endl;
        }
        
        file.close();
        cout << "Contact deleted successfully!" << endl;
        return true;
    }
    
    // Display all contacts
    void displayAllContacts() {
        vector<Contact> contacts = getAllContacts();
        
        if (contacts.empty()) {
            cout << "No contacts found!" << endl;
            return;
        }
        
        cout << "\n===== PHONEBOOK =====\n" << endl;
        for (const auto& contact : contacts) {
            cout << "ID: " << contact.id << endl;
            cout << "Name: " << contact.name << endl;
            cout << "Phone: " << contact.phone << endl;
            cout << "Email: " << contact.email << endl;
            cout << "Address: " << contact.address << endl;
            cout << "--------------------" << endl;
        }
    }
};

int main() {
    PhonebookManager phonebook;
    int choice;
    
    while (true) {
        cout << "\n===== PHONEBOOK MANAGEMENT SYSTEM =====" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. View All Contacts" << endl;
        cout << "3. Search Contact" << endl;
        cout << "4. Update Contact" << endl;
        cout << "5. Delete Contact" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1: {
                Contact contact;
                cout << "Enter Name: ";
                getline(cin, contact.name);
                cout << "Enter Phone: ";
                getline(cin, contact.phone);
                cout << "Enter Email: ";
                getline(cin, contact.email);
                cout << "Enter Address: ";
                getline(cin, contact.address);
                phonebook.addContact(contact);
                break;
            }
            case 2:
                phonebook.displayAllContacts();
                break;
            case 3: {
                string name;
                cout << "Enter name to search: ";
                getline(cin, name);
                vector<Contact> results = phonebook.searchByName(name);
                if (results.empty()) {
                    cout << "No contacts found!" << endl;
                } else {
                    cout << "\n===== SEARCH RESULTS =====\n" << endl;
                    for (const auto& contact : results) {
                        cout << "ID: " << contact.id << endl;
                        cout << "Name: " << contact.name << endl;
                        cout << "Phone: " << contact.phone << endl;
                        cout << "Email: " << contact.email << endl;
                        cout << "Address: " << contact.address << endl;
                        cout << "--------------------" << endl;
                    }
                }
                break;
            }
            case 4: {
                int id;
                Contact contact;
                cout << "Enter Contact ID to update: ";
                cin >> id;
                cin.ignore();
                cout << "Enter New Name: ";
                getline(cin, contact.name);
                cout << "Enter New Phone: ";
                getline(cin, contact.phone);
                cout << "Enter New Email: ";
                getline(cin, contact.email);
                cout << "Enter New Address: ";
                getline(cin, contact.address);
                phonebook.updateContact(id, contact);
                break;
            }
            case 5: {
                int id;
                cout << "Enter Contact ID to delete: ";
                cin >> id;
                phonebook.deleteContact(id);
                break;
            }
            case 6:
                cout << "Thank you for using Phonebook Management System!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    
    return 0;
}