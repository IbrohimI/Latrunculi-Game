#include <iostream>

using namespace std;

void gameLogic1(char arrayBoard[][22], int row, int length, char& tempRow, int& tempLength, int& tempR,
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

    if(arrayBoard[tempR][tempLength] == 'x')
    {
        arrayBoard[tempR][tempLength] = ' ';
        cout << "Player 1 Where to Move Piece?(-1 to cancel): ";// << endl;
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

        //arrayBoard[tempR][tempLength] = 'x';
        ///////////////////////////////////////////////////////////////////////////////////////////////
        cout << endl;
    }
    else if(arrayBoard[tempR][tempLength] == 'X')
    {
        arrayBoard[tempR][tempLength] = ' ';
        cout << "Player 1 Where to Move Piece?(-1 to cancel): ";// << endl;
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
        //arrayBoard[tempR][tempLength] = 'X';
        ///////////////////////////////////////////////////////////////////////////////////////////////
        cout << endl;
    }
    else
    {
        cout << "No Piece Found at a given location" << endl;
    }

    return;
}


void checkLegalMoves1x(char arrayBoard[][22], int row, int length, char& tempRow,
                     int& tempLength, int& tempR, int& legalRow, int& legalLength, bool& isTrue)
{
    if(legalRow != tempR && legalLength != tempLength)
    {
        cout << "Illegal Move Try Again!!!" << endl;
        cerr << "OK1" << endl;
        tempR = legalRow;
        tempLength = legalLength;
        arrayBoard[tempR][tempLength] = 'x';
        isTrue = false;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    ///Forward Move

    else if(legalRow == tempR && legalLength != tempLength && legalLength < tempLength)
    {
        for(int index = legalLength; index <= tempLength; index++)
        {
            if(arrayBoard[tempR][index] == 'x' || arrayBoard[tempR][index] == 'o' ||
               arrayBoard[tempR][index] == 'X' || arrayBoard[tempR][index] == 'O')
            {
                cout << "Illegal Move Try Again!!!" << endl;
                cerr << "OK2" << endl;
                tempR = legalRow;
                tempLength = legalLength;
                arrayBoard[tempR][tempLength] = 'x';
                isTrue = false;
            }
            else if((arrayBoard[tempR][index] != 'x' || arrayBoard[tempR][index] != 'o' ||
               arrayBoard[tempR][index] != 'X' || arrayBoard[tempR][index] != 'O') && index == tempLength)
            {
                cerr << "OK3" << endl;
                arrayBoard[tempR][tempLength] = 'x';
            }
        }
        //arrayBoard[tempR][tempLength] = 'x';
    }
    else if(legalRow != tempR && legalLength == tempLength && legalRow < tempR)
    {
        for(int index = legalRow; index <= tempR; index++)
        {
            if(arrayBoard[index][legalLength] == 'x' || arrayBoard[index][legalLength] == 'o' ||
               arrayBoard[index][legalLength] == 'X' || arrayBoard[index][legalLength] == 'O')
            {
                cout << "Illegal Move Try Again!!!" << endl;
                tempR = legalRow;
                tempLength = legalLength;
                arrayBoard[tempR][tempLength] = 'x';
                isTrue = false;
                break;
            }
            else if((arrayBoard[index][legalLength] != 'x' || arrayBoard[index][legalLength] != 'o' ||
               arrayBoard[index][legalLength] != 'X' || arrayBoard[index][legalLength] != 'O') && index == tempR)
            {
                arrayBoard[tempR][tempLength] = 'x';
            }
        }
        //arrayBoard[tempR][tempLength] = 'x';
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///Backward Move
    else if(legalRow == tempR && legalLength != tempLength && legalLength > tempLength)
    {
        for(int index = legalLength; index >= tempLength; --index)
        {
            if(arrayBoard[tempR][index] == 'x' || arrayBoard[tempR][index] == 'o' ||
               arrayBoard[tempR][index] == 'X' || arrayBoard[tempR][index] == 'O')
            {
                cout << "Illegal Move Try Again!!!" << endl;
                tempR = legalRow;
                tempLength = legalLength;
                arrayBoard[tempR][tempLength] = 'x';
                isTrue = false;
            }
            else if((arrayBoard[tempR][index] != 'x' || arrayBoard[tempR][index] != 'o' ||
               arrayBoard[tempR][index] != 'X' || arrayBoard[tempR][index] != 'O') && index == tempLength)
            {
                arrayBoard[tempR][tempLength] = 'x';
            }
        }
        //arrayBoard[tempR][tempLength] = 'x';
    }
    else if(legalRow != tempR && legalLength == tempLength && legalRow > tempR)
    {
        for(int index = legalRow; index >= tempR; --index)
        {
            if(arrayBoard[index][legalLength] == 'x' || arrayBoard[index][legalLength] == 'o' ||
               arrayBoard[index][legalLength] == 'X' || arrayBoard[index][legalLength] == 'O')
            {
                cout << "Illegal Move Try Again!!!" << endl;
                tempR = legalRow;
                tempLength = legalLength;
                arrayBoard[tempR][tempLength] = 'x';
                isTrue = false;
                break;
            }
            else if((arrayBoard[index][legalLength] != 'x' || arrayBoard[index][legalLength] != 'o' ||
               arrayBoard[index][legalLength] != 'X' || arrayBoard[index][legalLength] != 'O') && index == tempR)
            {
                arrayBoard[tempR][tempLength] = 'x';
            }
        }
        //arrayBoard[tempR][tempLength] = 'x';
    }

}
