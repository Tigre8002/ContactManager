#include <iostream>
#include <fstream>

using namespace std;

struct Contact {
    string name;
    string prefix;
    string number;
};

class ContactManager
{
public:
    void addContact(const Contact& contact)
    {
        ofstream outFile("contacts.txt", ios::app);
        if (outFile.is_open()) {
            outFile << contact.name << " " << contact.prefix << " " << contact.number << endl;
            outFile.close();
        } else {
            cout << "Unable to open file for writing" << endl;
        }
    };

    void getContacts()
    {
        ifstream inFile("contacts.txt");

        if (inFile.is_open()) {
            while (getline(inFile, contacts)) {
                cout << contacts << endl;
            }
            inFile.close();
        } else {
            cout << "Unable to open file" << endl;
        }
    };

    void removeContact(const string& name) {
        ifstream inFile("contacts.txt");
        ofstream tempFile("temp.txt");
        string line;
        bool found = false;

        if (inFile.is_open() && tempFile.is_open()) {
            while (getline(inFile, line)) {
                if (line.find(name) == string::npos) {
                    tempFile << line << endl;
                } else {
                    found = true;
                }
            }
            inFile.close();
            tempFile.close();
            remove("contacts.txt");
            rename("temp.txt", "contacts.txt");

            if (found) {
                cout << "Contact deleted successfully." << endl;
            } else {
                cout << "Contact not found." << endl;
            }
        }
    }
private:
    string contacts;
};

int main()
{
    ContactManager contactManager;

    while (true)
    {
        cout << "\n \n" << "\t 1.Add Contact" << endl;
        cout << "\t 2.Remove Contact" << endl;
        cout << "\t 3.See Contacts" << endl;
        cout << "\n \t 4.Exit" << endl;

        int choice;
        cin >> choice;

        Contact contact;

        string name;

        switch(choice)
        {
            case 1:
                cout << "Contact Name: " << endl;
                cin >> contact.name;
                cout << "Prefix: " << endl;
                cin >> contact.prefix;
                cout << "Number:" << endl;
                cin >> contact.number;

                cout << contact.name << contact.prefix << contact.number << endl;

                contactManager.addContact(contact);

                break;
            case 2:
                cout << "Enter the name of the contact to delete: " << endl;

                contactManager.getContacts();

                cin >> name;
                contactManager.removeContact(name);

                break;
            case 3:
                cout << "These are the contacts you have stored:" << endl;
                contactManager.getContacts();

                break;
            case 4:
                exit(0);
            default:
                cout << "Please try again" << endl;
                break;
        }
    }
}
