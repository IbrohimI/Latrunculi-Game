#include <iostream>

using namespace std;

void checkLegalMoves2o(char arrayBoard[][22], int row, int length, char& tempRow,
                     int& tempLength, int& tempR, int& legalRow, int& legalLength, bool& isTrue)
{
    if(legalRow != tempR && legalLength != tempLength)
    {
        cout << "Illegal Move Try Again!!!" << endl;
        tempR = legalRow;
        tempLength = legalLength;
        arrayBoard[tempR][tempLength] = 'o';
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
                tempR = legalRow;
                tempLength = legalLength;
                arrayBoard[tempR][tempLength] = 'o';
                isTrue = false;
            }
            else if((arrayBoard[tempR][index] != 'x' || arrayBoard[tempR][index] != 'o' ||
               arrayBoard[tempR][index] != 'X' || arrayBoard[tempR][index] != 'O') && index == tempLength)
            {
                arrayBoard[tempR][tempLength] = 'o';
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
                arrayBoard[tempR][tempLength] = 'o';
                isTrue = false;
                break;
            }
            else if((arrayBoard[index][legalLength] != 'x' || arrayBoard[index][legalLength] != 'o' ||
               arrayBoard[index][legalLength] != 'X' || arrayBoard[index][legalLength] != 'O') && index == tempR)
            {
                arrayBoard[tempR][tempLength] = 'o';
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
                arrayBoard[tempR][tempLength] = 'o';
                isTrue = false;
            }
            else if((arrayBoard[tempR][index] != 'x' || arrayBoard[tempR][index] != 'o' ||
               arrayBoard[tempR][index] != 'X' || arrayBoard[tempR][index] != 'O') && index == tempLength)
            {
                arrayBoard[tempR][tempLength] = 'o';
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
                arrayBoard[tempR][tempLength] = 'o';
                isTrue = false;
                break;
            }
            else if((arrayBoard[index][legalLength] != 'x' || arrayBoard[index][legalLength] != 'o' ||
               arrayBoard[index][legalLength] != 'X' || arrayBoard[index][legalLength] != 'O') && index == tempR)
            {
                arrayBoard[tempR][tempLength] = 'o';
            }
        }
        //arrayBoard[tempR][tempLength] = 'x';
    }

}
