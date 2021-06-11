#include <iostream>
#include "src/HashingAlgorithms/HashMD5.h"
#include "src/HashingAlgorithms/HashSHA1.h"
using namespace std;

int main() {

    string password;
    int option;
    cout << "Enter the password that you want to get hashed: " << endl;
    cin >> password;

    cout << "Now type '0' if you want to hash your password using MD5" << endl;
    cout << "Or type '1' if you want to hash your password using SHA-1" <<endl;
    cout << "Or type '2' if you want to exit" <<endl;
    cin >> option;

    switch (option) {
        case 0:
            cout << "Hashing" << " " << password << " using MD5: " << initHashMD5(password);
            break;
        case 1:
            cout << "Hashing" << " " << password << " using SHA-1: " << initHashSHA1(password);
            break;
        case 2:
            break;
    }


    return 0;
}
