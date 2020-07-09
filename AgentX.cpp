#include<iostream>
#include<ctime>
void PrintIntroduction(int Difficulty)
{
  std::cout<< "\n\nYou are a secret agent breaking into a level "<< Difficulty;
  std::cout<< " secure room...\nEnter the correct code to continue...\n\n";
}
bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

 // Print welcome messages to the terminal
    // std::cout<<"You are a secret agent breaking into a secure server room..."<<"\n";
    // std::cout<<"Enter the correct code to continue..." << "\n" ;

   //Declare 3 number code
    const int CodeA = rand() % Difficulty+Difficulty , CodeB = rand() % Difficulty+Difficulty , CodeC = rand() % Difficulty+Difficulty ;

    const int CodeSum = CodeA + CodeB + CodeC ;
    const int CodeProduct = CodeA * CodeB * CodeC ;


    std::cout << "\n" ;
    std::cout<<"+ There are 3 numbers in the code"<<"\n";
    std::cout<< "+ The codes add-up to: " << CodeSum << "\n" << "+ The codes multiply to give: " << CodeProduct << "\n" ;

    //Store Player guess

    int GuessA, GuessB, GuessC, GuessSum, GuessProduct;
    std::cin >> GuessA >> GuessB >> GuessC;

    GuessSum=GuessA + GuessB + GuessC;
    GuessProduct=GuessA * GuessB * GuessC;

    //std::cout, << "You entered: " << GuessA <<" "<< GuessB <<" " << GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {

        std::cout<< "\n*** Well done agent! You have extracted a file! Keep going! ***\n";
        return true;
    }
    else{
        std::cout<< "\n*** You entered the wrong code! Careful agent! Try again! ***\n";
        return false;
    }
}

int main()
{
    srand(time(NULL)); //create new random sequence based on time of day
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;
    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels completes
     {

       bool bLevelComplete = PlayGame(LevelDifficulty);
       std::cin.clear(); // Clears any errors
       std::cin.ignore(); // Discards the buffer
       if (bLevelComplete)
          {
             ++LevelDifficulty;
          }


    }
    std::cout<< "\n*** Great work agent! You get all the files! Now get out there! ***\n";

   return 0;
}
