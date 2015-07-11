#ifndef __Homework_1__whats_my_number__
#define __Homework_1__whats_my_number__

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

class Whats_my_number {
public:
    Whats_my_number();
    ~Whats_my_number() { cout << "destroyed"; };
    Whats_my_number(const int & upper, const int & lower);
    //void setupper ( const int upper ) { upper_bound = upper; }
    void setlower ( const int lower) {lower_bound = lower; }
    int getlower() {return lower_bound; }
    int getupper() {return upper_bound; }
    void game_prompt();
    void check_bounds();
    void initialize_vector();
    void dirty_biz();
    void raise_input();
    void checking();
private:
    int check_bound;
    int lower_bound = 1;
    int upper_bound;
    bool check = true;
    bool is_digit = false;
    string user_response = " ";
    vector<int> choices = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
    vector<int> range_array = {};
    int input;
    char happy;
    char input_c;
    
};


#endif /* defined(__Homework_1__whats_my_number__) */
