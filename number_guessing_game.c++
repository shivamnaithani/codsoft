#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    int randomNumber = rand() % 100 + 1;
    int guess;
    int tries = 0;

    cout << "Guess My Number Game\n\n";

    do
    {
        cout << "Enter a guess between 1 and 100 : ";
        cin >> guess;
        ++tries;

        if (guess > randomNumber)
        {
            cout << "Too high!\n\n";
        }
        else if (guess < randomNumber)
        {
            cout << "Too low!\n\n";
        }
        else
        {
            cout << "\nCorrect! You got it in " << tries << " guesses!\n";
        }

    } while (guess != randomNumber);

    return 0;
}
