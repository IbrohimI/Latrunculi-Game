#include <iostream>
#include "Board.h"
#include "Player1x.h"
#include "Player2o.h"

using namespace std;

void gameLogic1(char arrayBoard[][22], int row, int length, char& tempRow, int& tempLength, int& tempR,
                int& legalRow, int& legalLength);
void gameLogic2(char arrayBoard[][22], int row, int length, char& tempRow, int& tempLength, int& tempR,
                int& legalRow, int& legalLength);
void immobilization(char arrayBoard[][22], int row, int length, char& tempRow,
                     int& tempLength, int& tempR, int& legalRow, int& legalLength,
                     bool& isTrue, int& score1, int& score2, bool& gameOver);

int main()
{
    char tempRow;
    int tempR;
    int tempLength;

    int legalRow;
    int legalLength;
    //////////////////////////////////////////
    bool gameOver;
    gameOver = false;
    bool isTrue;

    int row = 18;
    int length = 22;
    char arrayBoard[18][22];

    int score1 = 0;
    int score2 = 0;

    initializeArray(arrayBoard, 18, 22);
    makeGrid(arrayBoard, 18, 22);
    drawBoard(arrayBoard, 18, 22);

    while(!gameOver)
    {
        isTrue = true;
        cout << "Player 1 Select Piece: ";
        cin >> tempRow;
        cin >> tempLength;
        gameLogic1(arrayBoard, 18, 22, tempRow, tempLength, tempR, legalRow, legalLength);
        checkLegalMoves1x(arrayBoard, 18, 22, tempRow, tempLength, tempR, legalRow, legalLength, isTrue);
        immobilization(arrayBoard, row, length, tempRow, tempLength, tempR, legalRow, legalLength,
                       isTrue, score1, score2, gameOver);
        drawBoard(arrayBoard, 18, 22);
        if(isTrue == false)
        {
            continue;
        }
        while(true)
        {
            isTrue = true;
            cout << "Player 2 Select Piece: ";
            cin >> tempRow;
            cin >> tempLength;
            gameLogic2(arrayBoard, 18, 22, tempRow, tempLength, tempR, legalRow, legalLength);
            checkLegalMoves2o(arrayBoard, 18, 22, tempRow, tempLength, tempR, legalRow, legalLength, isTrue);
            immobilization(arrayBoard, row, length, tempRow, tempLength, tempR, legalRow, legalLength,
                            isTrue, score1, score2, gameOver);
            drawBoard(arrayBoard, 18, 22);
            if(isTrue == false)
            {
                continue;
            }
            else
            {
                break;
            }
        }
    }
    return 0;
}

void immobilization(char arrayBoard[][22], int row, int length, char& tempRow,
                     int& tempLength, int& tempR, int& legalRow, int& legalLength,
                     bool& isTrue, int& score1, int& score2, bool& gameOver)
{
    /// o is immobilized
    if(arrayBoard[tempR][tempLength] == 'x' || arrayBoard[tempR][tempLength] == 'X')
    {
        if(arrayBoard[tempR + 2][tempLength] == 'o'
            && (arrayBoard[tempR + 4][tempLength] == 'x' || arrayBoard[tempR][tempLength] == 'X'))
        {
            arrayBoard[tempR + 2][tempLength] = ' ';
            score1 = score1 + 1;
            cout << "Player 1 Score: " << score1 << endl;
        }
        else if(arrayBoard[tempR - 2][tempLength] == 'o'
            && (arrayBoard[tempR - 4][tempLength] == 'x' || arrayBoard[tempR][tempLength] == 'X'))
        {
            arrayBoard[tempR - 2][tempLength] = ' ';
            score1 = score1 + 1;
            cout << "Player 1 Score: " << score1 << endl;
        }
        else if(arrayBoard[tempR][tempLength + 2] == 'o'
            && (arrayBoard[tempR][tempLength + 4] == 'x' || arrayBoard[tempR][tempLength] == 'X'))
        {
            arrayBoard[tempR][tempLength + 2] = ' ';
            score1 = score1 + 1;
            cout << "Player 1 Score: " << score1 << endl;
        }
        else if(arrayBoard[tempR][tempLength - 2] == 'o'
            && (arrayBoard[tempR][tempLength - 4] == 'x' || arrayBoard[tempR][tempLength] == 'X'))
        {
            arrayBoard[tempR][tempLength - 2] = ' ';
            score1 = score1 + 1;
            cout << "Player 1 Score: " << score1 << endl;
        }
        if(score1 == 8)
        {
            cout << "Player 1 win the game!" << endl;
            gameOver = true;
        }
    }
    /// x is immobilized
    if(arrayBoard[tempR][tempLength] == 'o')
    {
        if(arrayBoard[tempR + 2][tempLength] == 'x'
            && arrayBoard[tempR + 4][tempLength] == 'o')
        {
            arrayBoard[tempR + 2][tempLength] = ' ';
            score1 = score1 + 1;
            cout << "Player 2 Score: " << score2 << endl;
        }
        else if(arrayBoard[tempR - 2][tempLength] == 'x'
            && arrayBoard[tempR - 4][tempLength] == 'o')
        {
            arrayBoard[tempR - 2][tempLength] = ' ';
            score1 = score1 + 1;
            cout << "Player 2 Score: " << score2 << endl;
        }
        else if(arrayBoard[tempR][tempLength + 2] == 'x'
            && arrayBoard[tempR][tempLength + 4] == 'o')
        {
            arrayBoard[tempR][tempLength + 2] = ' ';
            score1 = score1 + 1;
            cout << "Player 2 Score: " << score2 << endl;
        }
        else if(arrayBoard[tempR][tempLength - 2] == 'x'
            && arrayBoard[tempR][tempLength - 4] == 'o')
        {
            arrayBoard[tempR][tempLength - 2] = ' ';
            score1 = score1 + 1;
            cout << "Player 2 Score: " << score2 << endl;
        }
        if(score1 == 8)
        {
            cout << "Player 1 win the game!" << endl;
            gameOver = true;
        }
    }
    return;
}

void gameLogic2(char arrayBoard[][22], int row, int length, char& tempRow, int& tempLength, int& tempR,
                int& legalRow, int& legalLength)
{
    int index1;
    int index;
    for(index = 0; index < tempLength; index++)
    {
        index = index;
    }
    tempLength = tempLength + 5 + index;
    legalLength = tempLength;

    for(index1 = 0; index1 < int(tempRow - 'a'); index1++)
    {
        index1 = index1;
    }
    tempR = int(tempRow - 'a') + 2 + index1;
    legalRow = tempR;

    if(arrayBoard[tempR][tempLength] == 'o')
    {
        arrayBoard[tempR][tempLength] = ' ';
        cout << "Player 2 Where to Move Piece?(-1 to cancel): ";// << endl;
        cin >> tempRow;
        cin >> tempLength;
        //////////////////////////////////////////////////////////////////////////////////////////////
        for(index = 0; index < tempLength; index++)
        {
            index = index;
        }
        tempLength = tempLength + 5 + index;

        for(index1 = 0; index1 < int(tempRow - 'a'); index1++)
        {
            index1 = index1;
        }

        tempR = int(tempRow - 'a') + 2 + index1;

        //arrayBoard[tempR][tempLength] = 'o';
        ///////////////////////////////////////////////////////////////////////////////////////////////
        cout << endl;
    }
    else if(arrayBoard[tempR][tempLength] == 'O')
    {
        arrayBoard[tempR][tempLength] = ' ';
        cout << "Player 2 Where to Move Piece?(-1 to cancel): ";// << endl;
        cin >> tempRow;
        cin >> tempLength;
        //////////////////////////////////////////////////////////////////////////////////////////////
        for(index = 0; index < tempLength; index++)
        {
            index = index;
        }
        tempLength = tempLength + 5 + index;

        for(index1 = 0; index1 < int(tempRow - 'a'); index1++)
        {
            index1 = index1;
        }

        tempR = int(tempRow - 'a') + 2 + index1;
        arrayBoard[tempR][tempLength] = 'O';
        ///////////////////////////////////////////////////////////////////////////////////////////////
        cout << endl;
    }
    else
    {
        cout << "No Piece Found at a given location" << endl;
    }

    return;
}
