#include "whats_my_number.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

Whats_my_number::Whats_my_number() : lower_bound(1), upper_bound(1) {
    puts("default constructor");
}

Whats_my_number::Whats_my_number(const int & upper, const int & lower) : upper_bound(upper), lower_bound(lower) { //initialization list(colon)
    puts("default constructor");
}

void Whats_my_number::check_bounds() {
    while(!(cin >> input)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "That wasn't an option. Please input a valid range: ";
    }
    checking();
    //raise_input();

}
void Whats_my_number::checking() {
    while(check) {
        if (input >= 0 && input <= 11) {
            cout << "Cool beans" << endl;
            check = false;
        }
        else {
            cout << "\nThat is not a given option. Please input a value between 0 to 11: ";
            check_bounds();
        }
    }

    raise_input();
}

void Whats_my_number::game_prompt() {
    cout << "Choose an upper bound of either: '1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, or 2048', by choosing a the power by which you will raise the value of 2 to. (Example: choosing a value of 0, will be 2^0 = 1): ";
    
    check_bounds();
    initialize_vector();
    dirty_biz();
}

void Whats_my_number::initialize_vector() {
    for (int i = 0; i < upper_bound; i++) {
        range_array.push_back(i+1);
    }
}

void Whats_my_number::raise_input() {
    try {
        upper_bound = pow(2, input);
        cout << "This is your upper_bound " << upper_bound << endl;
        cout << "Are you happy with the range [1," << upper_bound << "]? (type: 'y' for yes or 'n' for no, then press enter)" << endl;
        while (cin >> happy){
        if (cin.fail()) {
            throw runtime_error("Input is not a valid input type\n");
        }
        else if (happy == 'n') {
            cout << "Enter in a new power to raise 2 to. " << endl;
            check_bounds();
            break;
        }
        else if (happy == 'y') {
            cout << "Awesome! Now we will guess your number" << endl;
            break;
        }
        else {
            cerr << "Invalid input. Please type in either 'y' or 'n'" << endl;
        }
        }
    } catch (const runtime_error& e) {
        cout << e.what();
    }
}


void Whats_my_number::dirty_biz() {
    int back = 0;
    int front = upper_bound - 1;
    int mid = ceil((front + back)/2);
    while (input_c != 'y') {
        cout << "Is this your number: " << range_array[mid] << " (if it's higher type 'h', if it's lower type 'l', if the guess is correct type 'y')" << endl;
        cin >> input_c;
        if (input_c == 'h') {
            back = mid;
        }
        else if (input_c == 'l'){
            front = mid;
        }
        else
        {
            cout << "That wasn't an option. (if it's higher type 'h', if it's lower type 'l', if the guess is correct type 'y')" << endl;
        }
        mid = ceil((front + back)/2);
    }
}
