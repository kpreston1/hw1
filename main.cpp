#include <iostream>
#include "whats_my_number.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Whats_my_number t;
    t.game_prompt();
    
    cout << "We guessed right!!!!" << endl;
    
    return 0;
}
