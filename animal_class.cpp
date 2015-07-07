//
//  main.cpp
//  workshop
//
//  Created by Kyle Preston on 6/24/15.
//  Copyright (c) 2015 Kyle Preston. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

const string unk = "unknown";
const string clone_prefix = "clone-";

class Animal {
    string _type = "";
    string _name = "";
    string _sound = "";
public:
    Animal(); //default constructor (name same as the class name)
    Animal(const string & type, const string & name, const string & sound);
    
    Animal(const Animal &); //copy constructor (because it's only parameter is an object of the same class)
    Animal & operator=(const Animal &);
    ~Animal(); //destructor
    void print() const;
};

Animal::Animal() : _type(unk), _name(unk), _sound(unk) { //initialization list(colon)
    puts("default constructor");
}

Animal::Animal(const string & type, const string & name, const string & sound)
: _type(type), _name(name), _sound(sound) {
    puts("constructor with arguments");
}

Animal::Animal(const Animal & a) {
    puts("copy constructor");
    _name = clone_prefix + a._name;
    _type = a._type;
    _sound = a._sound;
}

Animal::~Animal() {
    printf("destructor: %s the %s\n", _name.c_str(), _type.c_str());
}

void Animal::print() const {
    printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

Animal & Animal::operator=(const Animal & o) {
    puts("assignment operator");
    if(this != &o) {
        _name = clone_prefix + o._name;
        _type = o._type;
        _sound = o._sound;
    }
    return *this;
}

int main ()
{
    Animal a;
    a.print();
    
    const Animal b("goat", "bob", "baah");
    b.print();
    
    const Animal c = b;
    c.print();
    
    a = c;
    a.print();
    
    return 0;
}
