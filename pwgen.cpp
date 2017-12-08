// Eisa Alkaabi
// pwgen.cpp

#include "password.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

// return true if the option is in the range inclusive
// return false if the option not in the range
bool in_range(int lower, int upper, char option);

// create the passwords and push them to the password vector
void get_passwords(vector<Password>& passwords, int amount, int length, 
    int option);

int main()
{
  // seed function for random number generator
  srand(time(NULL));

  // store the user menu option
  char option = '0';

  while (option != '7')
  {
    vector<Password> current_passwords;
    
    cout << "Password type:" << endl;

    cout << "  1. Lowercase letters only\n"
         << "  2. Uppercase letters only\n"
         << "  3. Mixed case letters only\n"
         << "  4. Numbers only\n"
         << "  5. Letters + numbers\n"
         << "  6. Letters + numbers + symbols\n"
         << "  7. Exit program"
         << endl << endl;
    
    // keep track if they entered a good input
    bool passed;

    do
    {
      option = cin.get();
      cin.clear();
      cin.ignore();
      
      passed = in_range(1, 7, option) && isdigit(option);

      if (!passed)
        cout << "The option is invalid." << endl;
    } while (!passed);

    if (option != '7')
    {
      int length;

      do
      {
        cout << "Password length: ";
        cin >> length;
        cin.clear();
        cin.ignore();

        if (length <= 0)
          cout << "The length must be greater than 0." << endl;
      } while (length <= 0);

      int amount;

      do
      {
        cout << "Number of passwords: ";
        cin >> amount;
        cin.clear();
        cin.ignore();

        if (amount <= 0)
          cout << "The amount must be greater than 0." << endl;
      } while (amount <= 0);

      int option_num = option - '0';

      cout << "Generating";

      get_passwords(current_passwords, amount, length, option_num);

      for (int i = 0; i < current_passwords.size(); i++)
        cout << current_passwords.at(i).get() << endl << endl;

     // got this idea from http://www.cplusplus.com/reference/ctime/clock/ 
      clock_t t = clock();
      cout << endl
           << "Done in " << static_cast<float>(t)/CLOCKS_PER_SEC << " secs." 
           << endl;

      char yn;

      do
      {
        cout << endl;
        cout << "Save to file? (Y or N)" << endl;
        yn = cin.get();
        cin.clear();
        cin.ignore();
        cout << endl;
       
       if (yn != 'y' && yn != 'Y' && yn != 'n' && yn != 'N')
         cout << "Y or N." << endl;
      } while (yn != 'y' && yn != 'Y' && yn != 'n' && yn != 'N');

      if (yn == 'y' || yn == 'Y')
      {
        string file;
        ofstream of;
        cout << "Filename:" << endl;
        getline(cin, file);
        of.open(file);

        for (int i = 0; i < current_passwords.size(); i++)
        {
          of << current_passwords.at(i).get() << endl;
          // print new line after each password but not the lastone
          if (i < current_passwords.size() - 1)
            of << endl;
        }
        of.close();
        cout << "Passwords saved in: " << file << "." << endl << endl;
      }
      current_passwords.clear();
    }
  }
    
  return 0;
}

bool in_range(int lower, int upper, char option)
{
  int op_num = option - '0';

  if (op_num < lower || op_num > upper)
  {
    return false;
  }
  else
  {
    return true;
  }
}

void get_passwords(vector<Password>& passwords, int amount, int length, 
    int option)
{
  for (int i = 0; i < amount; i++)
  {
    Password pw(length, option);
    passwords.push_back(pw);
    // print dots to show the progress
    cout << ".";
  }
  cout << endl
       << endl;
}
