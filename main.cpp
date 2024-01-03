#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int NUM_CHARITIES = 3;

struct Charity {
    string name;
    int totalDonation;
};

// Task 1 - Set up the donation system
void setupDonationSystem(Charity charities[]) {
    for (int i = 0; i < NUM_CHARITIES; ++i) {
        cout << "Enter the name of Charity " << i + 1 << ": ";
        cin >> charities[i].name;
    }

    cout << "Charities available for donation:\n";
    for (int i = 0; i < NUM_CHARITIES; ++i) {
        cout << i + 1 << ". " << charities[i].name << endl;
    }
}

// Task 2 - Record and total each donation
void recordDonation(Charity charities[]) {
    int choice;
    float shoppingBill;

    cout << "Enter your charity choice (1, 2, or 3): ";
    cin >> choice;

    if (choice < 1 || choice > NUM_CHARITIES) {
        cout << "Invalid choice. Please select between 1, 2, or 3." << endl;
        return;
    }

    cout << "Enter the value of your shopping bill: $";
    cin >> shoppingBill;

    float donation = shoppingBill * 0.01;
    charities[choice - 1].totalDonation += donation;

    cout << "Donation of $" << fixed << setprecision(2) << donation << " made to " << charities[choice - 1].name << endl;
}

// Task 3 - Show the totals so far
void showTotals(Charity charities[]) {
    cout << "Charity Totals So Far:\n";

    // Sort the charities based on total donation in descending order
    for (int i = 0; i < NUM_CHARITIES - 1; ++i) {
        for (int j = i + 1; j < NUM_CHARITIES; ++j) {
            if (charities[i].totalDonation < charities[j].totalDonation) {
                swap(charities[i], charities[j]);
            }
        }
    }

    for (int i = 0; i < NUM_CHARITIES; ++i) {
        cout << charities[i].name << ": $" << fixed << setprecision(2) << charities[i].totalDonation << endl;
    }

    float grandTotal = 0;
    for (int i = 0; i < NUM_CHARITIES; ++i) {
        grandTotal += charities[i].totalDonation;
    }

    cout << "GRAND TOTAL DONATED TO CHARITY: $" << fixed << setprecision(2) << grandTotal << endl;
}

int main() {
    Charity charities[NUM_CHARITIES];

    // Task 1 - Set up the donation system
    setupDonationSystem(charities);

    // Task 2 - Record and total each donation
    int choice;
    do {
        recordDonation(charities);

        cout << "Enter -1 to show totals so far or any other number to continue: ";
        cin >> choice;

        if (choice == -1) {
            showTotals(charities);
        }
    } while (choice != -1);

    return 0;
}

