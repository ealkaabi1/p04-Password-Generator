// Eisa Alkaabi
// password.h

#ifndef PASSWORD_H
#define PASSWORD_H

#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

class Password
{
  public:
    // create password object and calls generate()
    Password(int len, int t);

    // return the password text
    string get();

  private:
    // make the password
    void generate();

    int length;
    int type;
    string text;

    // store the possible characters in a vector
    vector<string> domain;
};

#endif
