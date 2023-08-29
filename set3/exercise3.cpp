#include <iostream>
#include <string>
using namespace std;

// Structure to hold contact information
struct Contact {
    string firstName;
    string middleName;
    string lastName;
    string phoneNumber;
    string streetAddress;
    string houseNumber;
    string zipCode;
    string region;
};

void printContact(const Contact& contact) {
    cout << contact.firstName << "," << contact.middleName << ","
         << contact.lastName << "," << contact.phoneNumber << ","
         << contact.streetAddress << "," << contact.houseNumber << ","
         << contact.zipCode << "," << contact.region << endl;
}

int main() {
    const int maxPages = 50;
    Contact addressBook[maxPages];

    string command;
    while (cin >> command) {
        if (command == "add") {
            int page;
            cin >> page;

            if (page >= 1 && page <= maxPages) {
                Contact& contact = addressBook[page - 1];
                cin >> contact.firstName >> contact.middleName >>
                    contact.lastName >> contact.phoneNumber >>
                    contact.streetAddress >> contact.houseNumber >>
                    contact.zipCode >> contact.region;
            }
        } else if (command == "clr") {
            int page;
            cin >> page;

            if (page >= 1 && page <= maxPages) {
                addressBook[page - 1] = Contact();
            }
        } else if (command == "qry") {
            int page;
            cin >> page;

            if (page >= 1 && page <= maxPages &&
                !addressBook[page - 1].firstName.empty()) {
                printContact(addressBook[page - 1]);
            }
        } else if (command == "quit") {
            break;
        }
    }

    return 0;
}

// add 1 John B. Doe 12345678 Richard_Petersen_Plads 321 2800 Hovedstaden
// add 2 Jane A. Wolford 98765432 Fredrik_Bajers_Vej 7 9220 Nordjylland
// qry 1 qry 2
// quit
