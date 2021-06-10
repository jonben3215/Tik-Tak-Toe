#include <iostream>
#include <string.h>
using namespace std;

char squares[9] = {'1','2','3','4','5','6','7','8','9'};
/*
This functions just draws the tik-tak-toe board
*/
void Draw_Board()
{
    system("clear");
    cout << "Tik-Tak-Toe" << endl;
    cout  << "Player 1 = X and Plater 2 = O " << endl;
    cout << "   |   | " << endl;
    cout << squares[0] << "  | " << squares[1] << " | " << squares[2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   | " << endl;
    cout << squares[3] << "  | " << squares[4] << " | " << squares[5] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   | " << endl;
    cout << squares[6] << "  | " << squares[7] << " | " << squares[8] << endl;
    
}
int Check_Win()
{
    if (squares[0] == squares[1] && squares[1] == squares[2])
    {
        return 1; 
    }
    else if(squares[3] == squares[4] && squares[4] == squares[5])
    {
        return 1; 
    }
    else if(squares[6] == squares[7] && squares[7] == squares[8])
    {
        return 1; 
    }
    else if(squares[0] == squares[4] && squares[4] == squares[8])
    {
        return 1; 
    }
    else if(squares[6] == squares[4] && squares[4] == squares[2])
    {
        return 1; 
    }
    //If all the squares have been marked but no one wins then it is a tie
    else if(squares[0] != '1' && squares[1] != '2' && squares[2]!= '3' && squares[3]!= '4' && squares[4]!= '5' && squares[5]!= '6' && squares[6]!= '7' && squares[7]!= '8' && squares[8]!= '9')
    {
        return 0;
    }
    //This just means that none of the squares have not been marked
    else
    {
        return -1;
    }
}
int Game_Mechanics()
{
    int Player = 1, i, choice;
    char mark;
    do
    {
        Draw_Board();
        Player = (Player %2) ? 1 : 2;
        cout << "Player " << Player << " Enter a number" << endl;
        cin >> choice;
        mark = (Player == 1) ? 'X' : 'O';
        if (choice == 1 && squares[0] == '1')
            squares[0] = mark;
        else if (choice == 2 && squares[1] == '2')
            squares[1] = mark;
        else if(choice == 3 && squares[2] == '3')
            squares[2] = mark;
         else if(choice == 4 && squares[3] == '4')
            squares[3] = mark;
         else if(choice == 5 && squares[4] == '5')
            squares[4] = mark;
         else if(choice == 6 && squares[5] == '6')
            squares[5] = mark;
         else if(choice == 7 && squares[6] == '7')
            squares[6] = mark;
         else if(choice == 8 && squares[7] == '8')
            squares[7] = mark;
        else if(choice == 9 && squares[8] == '9')
            squares[8] = mark;
        else 
        {
            cout << "invalid Move" << endl;
            Player --;
            cin.ignore();
            cin.get();
        }
        i=Check_Win();
        Player++;
    }while (i==-1);
    Draw_Board();
    if(i ==1)
        cout << "Player " << --Player << " wins" << endl;
    else 
        cout << "Draw" << endl;

    cin.ignore();
    cin.get();
    return 0;
    
}
int main()
{
    Game_Mechanics();

}