// Official tax calculator based on income brackets and children

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    string name;
    float income;
    string occupation;
    int children;
    float tax;

    // Gets user inputs for profile
    cout << "Name: ";
    getline(cin, name);
    if(name == ""){
        cout << "---" << endl << "You must enter a name";
        return 1;
    } // Accounts for bad input

    cout << "Taxable income: ";
    cin >> income;
    if (income < 0){
        cout << "---" << endl << "The taxable income must not be negative";
        return 1;
    }

    cin.ignore(10000, '\n');
    cout << "Occupation: ";
    getline(cin, occupation);
    if (occupation == ""){
        cout << "---" << endl << "You must enter an occupation";
        return 1;
    }

    cout << "Number of children: ";
    cin >> children;
    if (children < 0){
        cout << "---" << endl << "The number of children must not be negative";
        return 1;
    }

    cout << "---" << endl;
    
    // Calculates tax, providing two branches for special occupations
    if(occupation == "nurse" || occupation == "teacher"){
        if(income < 55000){
            tax = income * 0.04;
        }
        else if(income > 55000 && income < 125000){
            tax = 55000 * 0.04 + (income - 55000) * 0.05;
        }
        else if(income > 125000){
            tax = 55000 * 0.04 + 15000 * 0.05 + (income - 125000) * 0.093;
        }
    }

    else {
        if(income < 55000){
            tax = income * 0.04;
        }
        else if(income > 55000 && income < 125000){
            tax = 55000 * 0.04 + (income - 55000) * 0.07;
        }
        else if(income > 125000){
            tax = 55000 * 0.04 + 15000 * 0.05 + (income - 125000) * 0.093;
        }
    }

    // Reduces tax for number of children
    while(income < 125000 && children > 0){
        tax -= 200;
        children--;
    }

    if (tax < 0) {tax = 0;}

    // Prints final answer with 2 decimal points
    cout << name << " would pay $";
    cout << fixed << setprecision(2) << tax << endl;
}
