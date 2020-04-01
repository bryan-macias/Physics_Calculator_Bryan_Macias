//Bryan Macias 3/29/2020
//Dr_T : 1437-58000

#include "functions.h" 

int main() 
{
  string option = "";
  string color = "\x1b[" + to_string(35) + ";1m";
  string reset = "\x1b[0m";

  do
  {
    showMenu();
    cout << "Please enter an option: ";
    cout << color;
    option = validateString(option);
    cout << reset;
    handleOption(option);

  }while(option != "e" && option != "E");
  cout << "See you later! " << endl;
  return 0;
}