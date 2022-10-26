#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
using namespace std;
void saveScore(int count)
{
    ifstream input("highscore.txt");
    if (!input.is_open())
    {
        cout<<"Unable to read file";
        return;
    }
    
    int highscore;
    input >> highscore;

    ofstream output("highscore.txt");
    if (!output.is_open())
    {
        cout<<"Unable to read file";
        return;
    }
    if (count < highscore)
    {
        output<<"High Score:\t"<<count;
    }
    else
    {
        output << highscore;
    }
    
}

void printVector(vector<int>vector)
{
    int i;
    cout << "Here are your guesses:\n";
    for (i = 0; i < vector.size(); i++)
    {
        cout<<vector[i]<<"\t";
    }
    cout<<endl<<"You tried "<<i<<" times\n";
      
}
void playGame()
{
    vector<int>guesses;
    int count = 0;
    
    int random = rand() % 251;
    cout<<random<<endl;
    cout<<"Guess a number: ";
    while (true)
    {
        int guess;
        cin>> guess;
        count++;
        guesses.push_back(guess);
       
        if (guess == random)
        {
            cout<<"Congratulatons! You win!\n";
            break;
        }
        else if (guess < random)
        {
            cout<<"Too low, try again\n";
        }
        else
        {
            cout<<"Too high, try again\n";
        }
        
        
    }

    saveScore(count);
    printVector(guesses);

}
int main()
{
    srand(time(NULL));
    int choice;
    do
    {
        cout <<"Press\n1. Play Game"<<endl<<"2. Quit"<<endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            playGame();
            break;
        case 2:
            break;
        }
    }while(choice!=2);
    return 0;
}