#include <iostream>
using namespace std;
int main()
{
    double amount, convert, D, E, P;
    char letter;
    cout << "Enter amount in GEL : ";
    cin >> amount;
    cout << "Enter the first letter of currency\n"
        "you wish to convert to (D, E or P): ";
    cin >> letter;
    cout << "Enter Current Exchange course" << endl;
    switch (letter) {
    case 'D':cin >> D; convert = amount *D;
        cout << amount << " GEL = " << convert << " US DOLLAR\n";
        break;
    case 'E': cin >> E; convert = amount * E;
        cout << amount << " GEL = " << convert << " EURO\n";
        break;
    case 'P': cin >> P; convert = amount * P;
        cout << amount << " GEL = " << convert << " POUND STERLING\n";
        break;
    default:
        cout << "Unknown currency unit called '" << letter << "'\n";
    }
}

	









