# p04-Password-Generator
Generate different types of unique password and save them to file

## Input/Output
[pwgwn.cpp lines 31-135] ([/pwgen.cpp](/pwgen.cpp "pwgen.cpp"))
I show the user a menu and they must enter an option from it and then I ask the user to input the length for the password and if they want to save to a file. Then based on the user inputs I display the generated passwords to the console.

## Control Flow
[pwgen.cpp lines 53,57,68,81,111,115,127,144,148] ([/pwgen.cpp](/pwgen.cpp "pwgen.cpp"))
[password.cpp lines 14,54] ([/password.cpp](/password.cpp "password.cpp"))
I use if, else, and switch statement to control the logic in my program. For the menu options I use switch statement and if/else for small decision.

## Iteration
[pwgen.cpp lines 27,55,70,83,113] ([/pwgen.cpp](/pwgen.cpp "pwgen.cpp"))
[password.cpp lines 41,50] ([/password.cpp](/password.cpp "password.cpp"))
I use while, do-while, and for loop to iterate in my program. I run the menu in a while loop until the user enter 7. I use for loop to iterate the vector when I print and save it to file.

## Data Structure
[password.h line 30] ([/password.h](/password.h "password.h"))
[password.cpp lines 18-42] ([/password.cpp](/password.cpp "password.cpp"))
[pwgen.cpp lines 16,29,160] ([/pwgen.cpp](/pwgen.cpp "pwgen.cpp"))
I use a vector of strings to store the domain of the possible characters based on the user input. Also I use a vector to store all of the generated passwords so I can save them to a file later if the user want.

## Function
[pwgen.cpp lines 140-166] ([/pwgen.cpp](/pwgen.cpp "pwgen.cpp"))
[password.cpp] ([/password.cpp](/password.cpp "password.cpp"))
I use 2 function in pwgen.cpp where the main() is to check if the option the user entered is in a certain range and another function that creates the password objects and push them to the vector. And also I make the functions in password.cpp so that the password can be generated and retrieved.

## File IO
[pwgwn.cpp lines 118-130] ([/pwgen.cpp](/pwgen.cpp "pwgen.cpp"))
I use ofstream to make output file to save the vector of password texts. I loop through the vector with a for loop and output each password on own line and put a new line in between.

## Class
[password.h] ([/password.h](/password.h "password.h"))
[password.cpp] ([/password.cpp](/password.cpp "password.cpp"))
I create the class Password to make password object in the main. It has a constructor to create the object and call the private function generate(). Also I have a public function get() to return the password text.
