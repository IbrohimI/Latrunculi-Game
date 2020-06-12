#include <iostream>

using namespace std;

void drawBoard(char arrayBoard [][22], int row, int length)
{
    for(int indexRow = 0; indexRow < row; indexRow++)
    {
        for(int indexLength = 0; indexLength < length; indexLength++)
        {
            cout << arrayBoard[indexRow][indexLength];
        }
        cout << endl;
    }
}

void makeGrid(char arrayBoard [][22], int row, int length)
{
    ///Row
    arrayBoard[0][5] = '0';
    arrayBoard[0][7] = '1';
    arrayBoard[0][9] = '2';
    arrayBoard[0][11] = '3';
    arrayBoard[0][13] = '4';
    arrayBoard[0][15] = '5';
    arrayBoard[0][17] = '6';
    arrayBoard[0][19] = '7';

    ///Length
    arrayBoard[2][0] = 'a';
    arrayBoard[4][0] = 'b';
    arrayBoard[6][0] = 'c';
    arrayBoard[8][0] = 'd';
    arrayBoard[10][0] = 'e';
    arrayBoard[12][0] = 'f';
    arrayBoard[14][0] = 'g';
    arrayBoard[16][0] = 'h';

    for(int indexRow = 0; indexRow < row; indexRow++)
    {
        for(int indexLength = 0; indexLength < length; indexLength++)
        {
            if(indexRow % 2 != 0 && indexLength >= 4 && indexLength < length - 1)
            {
                arrayBoard[indexRow][indexLength] = '-';
            }
            if(indexRow % 2 == 0 && indexRow != 0 && indexLength >= 4 && indexLength % 2 == 0)
            {
                arrayBoard[indexRow][indexLength] = '|';
            }
            if(indexRow == 2 && indexLength >= 4 && indexLength % 2 != 0 && indexLength < length - 1)
            {
                arrayBoard[indexRow][indexLength] = 'x';
            }
            if(indexRow == 16 && indexLength >= 4 && indexLength % 2 != 0 && indexLength < length - 1)
            {
                arrayBoard[indexRow][indexLength] = 'o';
            }
            if(indexRow == 14 && indexLength == 9)
            {
                arrayBoard[indexRow][indexLength] = 'O';
            }
            if(indexRow == 4 && indexLength == 11)
            {
                arrayBoard[indexRow][indexLength] = 'X';
            }
        }
    }


    return;
}

void initializeArray(char arrayBoard[][22], int row, int length)
{
    for(int indexRow = 0; indexRow < row; indexRow++)
    {
        for(int indexLength = 0; indexLength < length; indexLength++)
        {
            arrayBoard[indexRow][indexLength] = ' ';
        }
    }
}

