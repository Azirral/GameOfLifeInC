#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
char source[MAX_SIZE][MAX_SIZE];
char destiny[MAX_SIZE][MAX_SIZE];

void readData(char tab[MAX_SIZE][MAX_SIZE], const int sizeY, const int sizeX);
void printData(char tab[MAX_SIZE][MAX_SIZE], const int sizeY, const int sizeX);
int isOneAtGivenYX(char source[MAX_SIZE][MAX_SIZE], const int y, const int x, const int sizeY, const int sizeX);
char characterForYX(char source[MAX_SIZE][MAX_SIZE], const int y, const int x, const int sizeY, const int sizeX);
void transformData(char destiny[MAX_SIZE][MAX_SIZE], char source[MAX_SIZE][MAX_SIZE], const int sizeY, const int sizeX);
void swap(char destiny[MAX_SIZE][MAX_SIZE], char source[MAX_SIZE][MAX_SIZE], const int sizeY, const int sizeX);
// size in Y < 100, size in X <100
int main()
{
    int sizeY, sizeX, ctr;
    cin >> sizeY >> sizeX;
    readData(source, sizeY, sizeX);
    cin >> ctr;
    printData(source, sizeY, sizeX);
    for (int i = 0; i < ctr; i++)
    {
        transformData(destiny, source, sizeY, sizeX);
        printData(destiny, sizeY, sizeX);
        swap(destiny, source, sizeY, sizeX);
    }
    return 0;
}
void readData(char tab[MAX_SIZE][MAX_SIZE], const int sizeY, const int sizeX)
{
    for (int y = 0; y < sizeY; y++)
    {
        for (int x = 0; x < sizeX; x++)
        {
            cin >> tab[y][x];
        }
    }
}
void printData(char tab[MAX_SIZE][MAX_SIZE], const int sizeY, const int sizeX)
{
    for (int y = 0; y < sizeY; y++)
    {
        for (int x = 0; x < sizeX; x++)
        {
            cout << tab[y][x];
        }
        cout << endl;
    }
}
int isOneAtGivenYX(char source[MAX_SIZE][MAX_SIZE], const int y, const int x, const int sizeY, const int sizeX)
{
    if (y < 0)
    {
        return 0;
    }
    else if (y >= sizeY)
    {
        return 0;
    }
    else if (x < 0)
    {
        return 0;
    }
    else if (x >= sizeX)
    {
        return 0;
    }
    if (source[y][x] == '1')
        return 1;
    else if( (source[y][x] == '0') || (source[y][x] == 'X') )
        return 0;
}
char characterForYX(char source[MAX_SIZE][MAX_SIZE], const int y, const int x, const int sizeY, const int sizeX)
{

    int OneAbove = isOneAtGivenYX(source, y - 1, x, sizeY, sizeX);
    int OneBelow = isOneAtGivenYX(source, y + 1, x, sizeY, sizeX);
    int OneLeft = isOneAtGivenYX(source, y, x - 1, sizeY, sizeX);
    int OneRight = isOneAtGivenYX(source, y, x + 1, sizeY, sizeX);
    int OneAboveLeft = isOneAtGivenYX(source, y - 1, x - 1, sizeY, sizeX);
    int OneBelowLeft = isOneAtGivenYX(source, y + 1, x - 1, sizeY, sizeX);
    int OneAboveRight = isOneAtGivenYX(source, y - 1, x + 1, sizeY, sizeX);
    int OneBelowRight = isOneAtGivenYX(source, y + 1, x + 1, sizeY, sizeX);
    int count = 0;
    count = OneAbove + OneBelow + OneLeft + OneRight + OneAboveLeft + OneAboveRight + OneBelowLeft + OneBelowRight;
    if (source[y][x] == 'X')
    {
        return 'X';
    }
    else if ( ( ((count == 2) || (count == 3)) && source[y][x]=='1' ) || (source[y][x]=='0' && count==3) )
    {
        return '1';
    }
    else
        return '0'; 
}
void transformData(char destiny[MAX_SIZE][MAX_SIZE], char source[MAX_SIZE][MAX_SIZE], const int sizeY, const int sizeX)
{
    for (int y = 0; y < sizeY; y++)
    {
        for (int x = 0; x < sizeX; x++)
        {
            destiny[y][x] = characterForYX(source, y, x, sizeY, sizeX);
        }
    }
}
void swap(char destiny[MAX_SIZE][MAX_SIZE], char source[MAX_SIZE][MAX_SIZE], const int sizeY, const int sizeX)
{
    char temp;
    for (int y = 0; y < sizeY; y++)
    {
        for (int x = 0; x < sizeX; x++)
        {
            temp = source[y][x];
            source[y][x] = destiny[y][x];
            destiny[y][x] = temp;
        }
    }
}