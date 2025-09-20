#include <iostream>

//  Small Code problem - Does n't handle continue function and the user types 1- / 0- / -0 (Will fix it soon.)
using namespace std;

/*
    RANDOM NUMBERS:

    - rand() + srand(seed) → pseudo-random (deterministic, predictable if seed known)
      EX. srand(42) → pre-listed numbers: 17, 83, 56, 99, 4, 62, …

    - srand(time(0)) → changing seed, sequence looks random each run
      EX. srand(time(0)) uses seconds since Jan 1, 1970; if we know the seed/current second (e.g., 42), we can reproduce the pre-listsed lists.

    - true random → from physical processes, not predictable, rarely used in normal C++
      (radioactive decay, quantum phenomena)
*/

void askForContinuation(bool* playAgain){
    int option;

    while(true){
        cout << "Do you want to continue?[0]NO/[1]YES: ";
        cin >> option;

        if(cin.fail() || option > 1 || option < 0){
            cout << "Invalid input. Try again. \n" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }else{
            *playAgain = (option == 1);
            break;
        }
    }

}

void inputNumber(string prompt, int* memAddressNum){
    int tempGuess;

    while(true){
        cout << prompt;
        cin >> tempGuess; //deferencing the memory address of guessingNumber -> Using the value of the variable not the memory address.

        if(cin.fail()){
            cout << "Invalid input. Try again. \n" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if(tempGuess > 100 || tempGuess < 0){
            cout << "Number out of bounds. Input from the range.\n" << endl;
            continue;
        }

        *memAddressNum = tempGuess;
        break;
    }
}

int main(){

    int guessingNumber = 0;
    cout << "WELCOME TO C++ GUESSING NUMBER GAME.\n" << endl;
    srand(time(0));
    bool playAgain = true;

    while(playAgain){

        int rando = rand() %101;

        cout << rando << endl;
        inputNumber("Guess the number (1 - 100): ", &guessingNumber);

        if(rando == guessingNumber){
            cout << "You guessed correctly!\n" << endl;
            askForContinuation(&playAgain);
        }else{
            cout << "Sorry better luck next time!\n" << endl;
            askForContinuation(&playAgain);
        }

    }
    return 0;
}

