#include <iostream>
#include <string>

using namespace std;

int rows, cols;
char board[9999][9999];
int playerRow, playerCol;

void createBoard()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            board[i][j] = '_';
        }
    }

    playerRow = rows / 2;
    playerCol = cols / 2;
    board[playerRow][playerCol] = 'A';
}

void displayBoard()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValidMove(int x, int y)
{   
    if (x < 0 || x >= rows || y < 0 || y >= cols)
    {
        cout << "Reach the edge, turn end" << endl;
        board[playerRow][playerCol] = 'A';
        return false;
    }
    return true;
}

void movePlayer(string direction)
{
    board[playerRow][playerCol] = '.';
    int x = playerRow, y = playerCol;
    if (direction == "up")
    {
        x--;
    }
    else if (direction == "down")
    {
        x++;
    }
    else if (direction == "left")
    {
        y--;
    }
    else if (direction == "right")
    {
        y++;
    }
    else
    {
        cout<<"Invalid"<<endl;
    }

    if (isValidMove(x, y))
    {
        playerRow = x;
        playerCol = y;
        board[playerRow][playerCol] = 'A';
    }
}



int main()
{
    cout << "Enter the number of rows  for the board: ";
    cin >> rows;
    cout << "Enter the number of columns for the board: ";
    cin >> cols;

    createBoard();
    displayBoard();

    string direction;
    cout << endl<< "Command>:";
    while (cin >> direction)

    {
        // system("cls"); // undo the comment to test it on cmd terminal
        movePlayer(direction);
        displayBoard();
        
        cout << "Command>: ";
    }

    return 0;
}
