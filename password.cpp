// Eisa Alkaabi
// password.cpp

#include "password.h"

Password::Password(int len, int t): length(len), type(t), text("")
{
  string possible[4];
  possible[0] = "abcdefghijklmnopqrstuvwxyz";
  possible[1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  possible[2] = "0123456789";
  possible[3] = ",./<>?;':\"[]\\{}|-=_+`~!@#$%^&*()";

  switch (type)
  {
    //lowercase only
    case 1:
      domain.push_back(possible[0]);
      break;
    //uppercase only
    case 2:
      domain.push_back(possible[1]);
      break;
    //mixed-case letters
    case 3:
      domain.push_back(possible[0]);
      domain.push_back(possible[1]);
      break;
    //numbers only
    case 4:
      domain.push_back(possible[2]);
      break;
    //letters + numbers
    case 5:
      domain.push_back(possible[0]);
      domain.push_back(possible[1]);
      domain.push_back(possible[2]);
      break;
    //letters + numbers + symbols
    case 6:
      for (int i = 0; i < 4; i++)
        domain.push_back(possible[i]);
      break;
  }
  generate();
}

void Password::generate()
{
  for (int i = 0; i < length; i++)
  {
    int first_index, second_index;
  
    switch (type)
    {
      case 1:
        // down to case 4
      case 2:
        // down to case 4
      case 4:
        first_index = 0;
        break;
      case 3:
        first_index = rand() % 2;
        break;
      case 5:
        first_index = rand() % 3;
        break;
      case 6:
        first_index = rand() % 4;
        break;
    }
    second_index = rand() % domain[first_index].length();
    text += domain[first_index][second_index];
  }
}

string Password::get()
{
  return text;
}
