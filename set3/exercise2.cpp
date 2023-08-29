#include <iostream>
#include <set>

int main() {
    std::multiset<int> bag;

    std::string command;
    while (std::cin >> command) {
        if (command == "add") {
            int x;
            std::cin >> x;
            bag.insert(x);
        } else if (command == "del") {
            int x;
            std::cin >> x;
            auto iter = bag.find(x);
            if (iter != bag.end()) {
                bag.erase(iter);
            }
        } else if (command == "qry") {
            int x;
            std::cin >> x;
            if (bag.find(x) != bag.end()) {
                std::cout << "T";
            } else {
                std::cout << "F";
            }
        } else if (command == "quit") {
            break;
        }
    }

    return 0;
}
