#include <iostream>
using namespace std;
#include <cstring>
#include <cctype>

//Constant Variable
const int SIZE = 25;  //Size of the arrays

//Function Prototypes
void welcome();
void get_original(char original[]);
void create_answer(char source[], char result[]);
void display(char answer[], int score);
char guess();
bool match(char guess, char answer[], char key[]);
bool done(int score, char answer[], char key[]);
bool again();

//Main Function
int main()
{
    //Variable definitions
    char original[SIZE];  //original phrase
    char answer[SIZE]; //starts as _, evolves with response
    int bad_guess = 0; //increase as misses occur
    char players_guess;
    int score = 0;
    
    welcome();  //call the welcome function
    do
    {
        score = 0; //reset the score each time through
        get_original(original); //Call "original" function
        create_answer(original, answer); //fill the answer '_'
        display(answer,score);
        do
        {
            players_guess = guess();
            
            //Find out if there is a match, if not
            //add one to the score
            if (!match(players_guess, answer, original))
                ++score;
            display(answer, score);
        }while (!done(score, answer, original));
    } while (again());
    cout <<"Thanks for playing Hangman!" <<endl;
    
    
    cin.get();  //ending pause
    return 0;
}


//This function will explain the rules of the game
void welcome()
{
    cout << "Welcome to the hangman program" << endl
    <<"This is a two player game, one player will enter in the original "
    <<"phrase to guess and the other will guess the answer, character by character"
    <<"\n\n\n\n\n" <<endl;
}

//Read in the original phrase from the user
void get_original(char original[])
{
    char response = 'N';
    do
    {
        cout << "Please enter a phrase: ";
        cin.get(original, SIZE, '\n');
        cin.ignore(100,'\n');
        
        //echo the phrase entered:
        cout <<"Your phrase is: " <<original <<endl;
        cout <<"Would you like to re-enter it? (Y or N) ";
        cin >>response;
        cin.ignore(100,'\n');
    }while(toupper(response) == 'Y');
    
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

//Create an answer array with underscores where-ever
//there is a non-blank character. Stop at the '\0'
void create_answer(char source[], char result[])
{
    int length = strlen(source);
    
    for (int i=0; i < length; ++i)
    {
        if (source[i] == ' ')
            result[i] = ' ';
        else
            result[i] = '_';
    }
    result[i] = '\0';
}

//Display the answer with a space between
//each character for readability
void display(char answer[], int score)
{
    int length = strlen(answer);
    
    for (int i=0; i < length; ++i)
    {
        cout << answer[i] <<' ';
    }
    cout << endl;
    cout << "Your score is: " <<score <<endl <<endl;
}

//Prompt and allow the user to enter in a guess
//This guess will be returned
char guess()
{
    char input; //player's guess
    cout << "What is your guess? Enter a single character: ";
    cin >> input;
    cin.get();
    return input;
}

//Check for a match and update the answer if there is a match
//This function returns true if the guess exists anywhere
//in the "key" array, otherwise false
//If there is a match, the corresponding index
//in the "answer" array will set to that character
bool match(char guess, char answer[], char key[])
{
    int len = strlen(key);
    bool found = false;
    
    for (int i =0; i < len; ++i)
    {
        if (guess == key[i])  //match
        {
            answer[i] = guess;
            found = true;
        }
    }
    return found;//return false if no match!
}

//This function will return true if we are done
//playing. This will occur when the answer is the
//same as the key OR when the score is 7
bool done(int score, char answer[], char key[])
{
    bool finished = false; //not finished
    if (strcmp(answer, key) == 0)  //same
    {
        finished = true;
        cout <<"GREAT JOB! " << endl;
    }
    else if (score >= 7)
    {
        finished = true;
        cout <<"Not so good...better luck next time"
        <<endl;
    }
    return finished;
}

//Do you want to do this again?
//Returns true if yes, false otherwise
bool again()
{
    bool yes = false;//play again?
    char response = 'n';
    
    cout <<"Would you like to play again? Y or N ";
    cin >> response;
    cin.ignore(100,'\n');
    if (response == 'y' || response == 'Y')
        yes = true;
    
    return yes;
}    
