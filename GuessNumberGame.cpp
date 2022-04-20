/**
 * @file GuessNumberGame.cpp
 * @author Eyasu Yidnekachew Asres
 * @brief This program is a guess game
 * There are two players on this game
 * Each of them has much trail to find the hidden number
 * The program help the players to find the number by tell
 * if the number is greater than the given number
 * look the sample of the game
 * Add player1 name: player1Name
 * Add player2 name: player2Name
 * player1Name's turn
 * player1Name has no previous turn
 * The number greater than: 50 -- here player1 is asking if the number is greater than 50
 * Answer: Yes -- the computer tells if it is greater than 50
 * Guess the number: 75 -- the player guessed 75
 * Wrong number!
 * Press any key to continue . . . press any key then player2 continue
 * This process until the players find the number
 * after many trails, if they didn't find the number,
 * the game will stop
 * @date 2022-04-19
 * 
 */
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <ctime>

using namespace std;

struct Player1
{
    string playerName;
    int guessedNumber;
    int comparedNumber;
    string computerAnswer;
    Player1 *prevGame;
    Player1 *nextGame;
};

struct Player2
{
    string playerName;
    int guessedNumber;
    int comparedNumber;
    string computerAnswer;
    Player2 *prevGame;
    Player2 *nextGame;
};

Player1 *last1 = NULL;
Player1 *first1 = NULL;
Player2 *last2 = NULL;
Player2 *first2 = NULL;
bool gameNumberGuessed = false;
int gameNumber = 5;
string name1;
string name2;
int numberOfPlay = 0;
float gamePercent = 100;

void theNumber()
{
    srand(time(0));
    gameNumber = rand()%100;
}

Player1 *addPlayer1(string name)
{
    Player1 *newPlayer = new Player1;
    newPlayer->playerName = name;
    newPlayer->nextGame = NULL;
    newPlayer->prevGame = NULL;
    return newPlayer;
}

Player2* addPlayer2(string name)
{
    Player2 *newPlayer = new Player2;
    newPlayer->playerName = name;
    newPlayer->nextGame = NULL;
    newPlayer->prevGame = NULL;
    return newPlayer;
}

void addPlayer()
{
    int numberOfPlayers = 2;
    while (numberOfPlayers)
    {
    string playerName;
    cout << "Add player" << 3 - numberOfPlayers << " name: ";
    cin >> playerName;
    if (numberOfPlayers == 2) name1 = playerName;
    else name2 = playerName;
    numberOfPlayers--;
    }
}

void player1PreviousTurn()
{
    Player1 *lastPlay = last1;
    if (lastPlay != NULL)
    {
        cout << "Previous turn of " << name1 << "\n\t\tIs the number greater than: " << last1->comparedNumber << "?\n";
        cout << "\t\tAnswer: " << last1->computerAnswer;
        cout << "\t\tGuess of " << last1->playerName << ": " << last1->guessedNumber << endl;
    } else cout << name1 << " has no previous turn\n";
}

void player2PreviousTurn()
{
    Player2 *lastPlay = last2;
    if (lastPlay != NULL)
    {
        cout << "Previous turn of " << name2 << "\n\t\tIs the number greater than: " << last2->comparedNumber << "?\n";
        cout << "\t\tAnswer: " << last2->computerAnswer;
        cout << "\t\tGuess of " << last2->playerName << ": " << last2->guessedNumber << endl;
    } else cout << name2 << " has no previous turn\n";
}

void comparedPlayer1Number(Player1 *currentGame)
{   
    if (gameNumber >= currentGame->comparedNumber) currentGame->computerAnswer = "Yes\n" ;
    else currentGame->computerAnswer = "No\n" ;
    cout << "Answer: " << currentGame->computerAnswer ; 
}

void comparedPlayer2Number(Player2 *currentGame)
{   
    if (gameNumber >= currentGame->comparedNumber) currentGame->computerAnswer = "Yes\n" ;
    else currentGame->computerAnswer = "No\n" ;
    cout << "Answer: " << currentGame->computerAnswer ; 
}

void checkGuessedNumber(int num, string name)
{
    if (num != gameNumber) cout << "Wrong number!\n" ;
    else
    {
        if (name == name1){
            cout << "You won!\nYour Guessing performace is "<< gamePercent << "%." << endl;
            cout << name2 << " lose the game with the guess performance of " << gamePercent << "%." << endl;
        }
        else{
            cout << "You won!\nYour Guessing performace is "<< gamePercent << "%." << endl;
            cout << name1 << " lose the game with the guess performance of " << gamePercent - 0.326 << "%." << endl;
        }
        gameNumberGuessed = 1;
    }
}

void storePlayer1Data(Player1 *currentGame)
{
    if (last1 == NULL)
    {
        first1 = last1 = currentGame;
        last1->nextGame = NULL;
        last1->prevGame = NULL;
    }
    else 
    {
        currentGame->prevGame = last1;
        currentGame->nextGame = NULL;
        last1->nextGame = currentGame;
        last1 = currentGame;   
    }
}

void storePlayer2Data(Player2 *currentGame)
{
    if (last2 == NULL)
    {
        first2 = last2 = currentGame;
        last2->nextGame = NULL;
        last2->prevGame = NULL;
    }
    else 
    {
        currentGame->prevGame = last2;
        currentGame->nextGame = NULL;
        last2->nextGame = currentGame;
        last2 = currentGame;   
    }
}

int integerInput()
{
    repeat:
    int checkInputValue, number;
    checkInputValue = scanf("%i", &number);
    while (checkInputValue != 1)
    {
        cout << "Please enter an integer value!\n";
        scanf("%*[^\n]");
        checkInputValue = scanf("%d", &number);
    }
    if (number > 100 || number < 0)
    {
        cout << "Large number! Enter number between 0 and 100.\n";
        goto repeat;
    }
    return number;
}

void calPercent()
{
	gamePercent -= 0.326;
}

void playPlayer1()
{
    Player1 *newGame = new Player1;
    newGame = addPlayer1(name1);
    cout << name1 << "'s turn\n";
    player1PreviousTurn();
    cout << "The number greater than: ";
    newGame->comparedNumber = integerInput();
    comparedPlayer1Number(newGame);
    cout << "Guess the number: ";
    newGame->guessedNumber = integerInput();
    checkGuessedNumber(newGame->guessedNumber, name1);
    numberOfPlay++;
    storePlayer1Data(newGame);
    calPercent();
}

void playPlayer2()
{
    Player2 *newGame = new Player2;
    newGame = addPlayer2(name2);
    cout << name2 << "'s turn\n";
    player2PreviousTurn();
    cout << "The number greater than: ";
    newGame->comparedNumber = integerInput();
    comparedPlayer2Number(newGame);
    cout << "Guess the number: ";
    newGame->guessedNumber = integerInput();
    checkGuessedNumber(newGame->guessedNumber, name2);
    numberOfPlay++;
    storePlayer2Data(newGame);
    calPercent();
}

void gameOver()
{
    cout << "Too much trail!!!\n";
    cout << "Game over!\n";
    cout << "Both of you lose the game with game-performace of " << gamePercent <<"%.\n";
    system("pause");
}

int main()
{
    theNumber();
    addPlayer();
    while (!(gameNumberGuessed))
    {
        if (gamePercent < 50)
        {
            system("cls");
            gameOver();
            return 0;
        }
    	if (numberOfPlay % 2 == 0) playPlayer1();
    	else playPlayer2();
    	system("pause");
    	system("cls");
	}
    return 0;
}
