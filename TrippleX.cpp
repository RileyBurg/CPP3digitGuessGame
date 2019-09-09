#include <iostream>

void printIntroduction(int Difficulty)
{
    std::cout << "\nYou're currently at level: " << Difficulty << std::endl;
    std::cout << "Enter the correct code to continue...\n";
}

bool PlayGame(int Difficulty)
{
    printIntroduction(Difficulty);
    
    //Declare the 3 number code.
    const int a {rand() % Difficulty + 1};
    const int b {rand() % Difficulty + 1};
    const int c {rand() % Difficulty + 1};

    const int sum = a + b + c;
    const int product = a*b*c;

    //Print sum and product to the terminal
    std::cout << "\n+ There are 3 numbers in the code." << std::endl;
    std::cout << "+ The codes add-up to : " << sum << std::endl;
    std::cout << "+ The codes multiply to give: " << product << std::endl;

    int guessA, guessB, guessC;
    std::cin >> guessA;
    std::cin >> guessB;
    std::cin >> guessC;
    std::cout << "You entered: " << guessA << " " << guessB << " " << guessC;;

    int guessSum = guessA + guessB + guessC;
    int guessProd = guessA * guessB * guessC;
    
    if (guessSum == sum && guessProd == product)
    {
        std::cout << "\n**You've guessed correct! Keep going.**" << std::endl;
        return true;
    }
    else
    {
        std::cout << "\n**You have failed. Try again!**"<<std::endl;
        return false;
    }
    
}

int main()
{
    int const maxDifficulty = 5;
    int levelDifficulty = 1;
    while (levelDifficulty <= maxDifficulty)
    {
       bool bLevelComplete = PlayGame(levelDifficulty);
       std::cin.clear();
       std::cin.ignore();

       if(bLevelComplete)
       {
           ++levelDifficulty;
       }
    }
    std::cout << "\nYou have completed the game!" << std::endl;
    return 0;
}