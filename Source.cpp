#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <array>
#include <ctime>

//Part 1F----------------------------------------------------------------------------------------
const int Array_Size = 4;
using namespace std;
void convertNumber(int num, int Array[Array_Size])
{
    // Is used to conver Guess to Array.
    for (int i = 0; i < Array_Size; ++i)
    {
        Array[i] = num;
    }
    Array[0] = (num % 10000) / 1000;
    Array[1] = (num % 1000) / 100;
    Array[2] = (num % 100) / 10;
    Array[3] = (num % 10);


}
void printArray(int Array[Array_Size])
{
    for (int i = 0; i < Array_Size; ++i)
    {
        cout << Array[i] << " ";
    }
    cout << endl;
}
//Part 1F---------------------------------------------------------------------------------------  

//Part 3F---------------------------------------------------------------------------------------
bool checkForBulls(int answer[Array_Size], int guess[Array_Size])
{

    int bulls = 0;

    // Counts Bulls is Numbers and position match.
    for (int i = 0; i < Array_Size; ++i)
    {
        if (guess[i] == answer[i])
            ++bulls;
    }
    cout << bulls << " Bulls.\n";

    if (bulls == 4)
    {
        return true;
    }
    else
        return false;


}
//Part 3F--------------------------------------------------------------------------------------

//Part 4F--------------------------------------------------------------------------------------
int checkForCows(int answer[Array_Size], int guess[Array_Size])
{
    int cows = 0;

    // Counts cows if numbers match.
    for (int i = 0; i < Array_Size; ++i)
    {
        if (guess[0] == answer[i])
            ++cows;
        if (guess[1] == answer[i])
            ++cows;
        if (guess[2] == answer[i])
            ++cows;
        if (guess[3] == answer[i])
            ++cows;
    }
    cout << cows << " Cows, ";
    return 0;

}
//Part 4F------------------------------------------------------------------------------------------

//Part 5F: It was easier to create a function and call it in main----------------------------------
int* makeRandom(int numberDigits, int bagSize)
{
    // This is the
    int* bagOfNumbers = (int*)malloc(bagSize * sizeof(int));

    // This will be the resulting array
    int* generatedNumbers = (int*)malloc(numberDigits * sizeof(int));


    int counter;
    int randomIndex;
    int tempIndex;


    srand(time(NULL));

    // Generates all the posible numbers to choose from.
    for (counter = 0; counter < bagSize; counter++)
        bagOfNumbers[counter] = counter;

    // Main loop
    for (counter = 0; counter < numberDigits; counter++) {

        // Picks a number from the bagOfNumbers by selecting
        // a valid index
        randomIndex = rand() % bagSize;
        generatedNumbers[counter] = bagOfNumbers[randomIndex];

        // After choosing one, it removes that number by moving downwards
        // the rest of the numbers. It shrinks the bagSize by one.
        // Now its imposible to pick the same number again, even if
        // the same index comes up.

        for (tempIndex = randomIndex; tempIndex < bagSize - 1; tempIndex++) {
            bagOfNumbers[tempIndex] = bagOfNumbers[tempIndex + 1];
        }

        bagSize--;

    }

    // Important, no memory leaking :D
    free(bagOfNumbers);

    // Remember to free this pointer later
    return generatedNumbers;
}
//Part 5F-------------------------------------------------------------------------------------

//All parts put together, including 2F--------------------------------------------------------
int main()
{
    int Answer[Array_Size]; //Answer Array
    int Guess[Array_Size];// Guess Array
    int* myNumbers;

    myNumbers = makeRandom(4, 9); // 4 digit number, choosing from 9 digits options
    //I set Answer Array equal to random numbers generated.
    Answer[0] = myNumbers[0];
    Answer[1] = myNumbers[1];
    Answer[2] = myNumbers[2];
    Answer[3] = myNumbers[3];
    int Number;

    cout << "Welcome to Bulls and Cows!\nDo you want to play? ";

    int play = false; // Game recognizes when to play by starting off false unless..

    // Players reply.
    string reply;
    cin >> reply;

    if (reply == "yes" || reply == "Yes" || reply == "y" || reply == "Y")
    {
        play = true; // Plays the game.
    }

    if (reply == "no" || reply == "No" || reply == "n" || reply == "N")
    {
        cout << "Ok. Goodbye.\n";
        return EXIT_SUCCESS; // "Exits the game. 
    }
    cout << "press '0' at any time to quit.\n";


    //Bulk of the game.
    while (play == true)
    {
        cout << "Your guess? ";
        cin >> Number; // Players guess.
        if (Number > 9999)
        {
            cout << "not a valid guess!\n";
        }
        if (Number < 10000 && Number != 0)
        {
            printArray(Answer); // This is to make it easier for you to grade and because the instructions say to print this.
            convertNumber(Number, Guess); // Converts Number to Guess.
            checkForCows(Answer, Guess); // Checks to see if Anser and Guess are the same number.
        }

        if (checkForBulls(Answer, Guess) == true) // Exits game if bulls = 4.
        {
            cout << "Congrats! You won!\n";
            cout << "Thanks for playing :D\n";
            return EXIT_SUCCESS;
        }
        if (Number == 0) // Exits game if user types 0 for guess at any time.
        {
            cout << "Thanks for playing :)\n";
            system("pause");
            cout << "Quiter...\n"; // Oh, this too..
            system("pause");
            return EXIT_SUCCESS;
        }

    }
    system("pause");
}
//All parts put together, including 2F--------------------------------------------------------
