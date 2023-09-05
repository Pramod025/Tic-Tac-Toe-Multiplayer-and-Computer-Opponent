#include <iostream>
#include<ctime>
#include<random>
using namespace std;

char space[3][3] = { { '1','2','3' },{ '4','5','6' },{ '7','8','9' } };
string n1 = "";
string n2 = "";
int row, col;
char token = 'x';
bool tie = false;
int mode;
string player_name="";
int player1_wins = 0,player2_wins = 0;

// Function to print the game board
void printBoard() {
    system("cls"); // Clear the console (Unix-based systems)
    cout << "Tic-Tac-Toe\n";
    cout << "      |     |    \n";
    cout << "   " << space[0][0] << "  |  " << space[0][1] << "  |  " << space[0][2] << "    \n";
    cout << "______|_____|____\n";
    cout << "      |     |    \n";
    cout << "   " << space[1][0] << "  |  " << space[1][1] << "  |  " << space[1][2] << "    \n";
    cout << "______|_____|____\n";
    cout << "      |     |    \n";
    cout << "   " << space[2][0] << "  |  " << space[2][1] << "  |  " << space[2][2] << "    \n";
    cout << "      |     |    \n";
}

void getcomputerchoice()
{
    srand(time(0));
    int choice;
    do {
        choice = rand() % 9 + 1; // Generate a random number between 1 and 9
        row = (choice - 1) / 3;
        col = (choice - 1) % 3;
    } while (space[row][col] == 'x' || space[row][col] == 'o'); // Repeat until an empty cell is found

   space[row][col] = token;
    token = (token == 'x' ? 'o' : 'x'); // Switch player's turn
}



// Function to get a valid player move
void getPlayerMove() {
    int digit;
    if(mode==1)
    {
         cout << player_name<<"'s Turn"<<endl<< "Please enter a valid move (1-9): ";
    }
    else{
        cout << (token == 'x' ? n1 : n2) <<"'s Turn"<<endl<< "Please enter a valid move (1-9): ";
    }
        cin >> digit;
        if (digit >= 1 && digit <= 9) {
            row = (digit - 1) / 3;
            col = (digit - 1) % 3;
        }
        else cout << "Invalid move. Try again." << endl;
    if((token=='x'||token=='o')&&space[row][col]!='x'&&space[row][col]!='o')
    {
    space[row][col] = token;
    token = (token == 'x' ? 'o' : 'x'); // Switch player's turn
    }
    else{
        cout<<"There's no empty space. Invalid move. Try again."<<endl;
        getPlayerMove();}

}


// Function to check for a win
bool checkForWin() {
    for (int i = 0; i < 3; i++) {
        if (space[i][0] == space[i][1] && space[i][1] == space[i][2] ||
            space[0][i] == space[1][i] && space[1][i] == space[2][i]) {
            return true;
        }
    }
    if (space[0][0] == space[1][1] && space[1][1] == space[2][2] ||
        space[0][2] == space[1][1] && space[1][1] == space[2][0]) {
        return true;
    }

    // Check for a tie
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'x' && space[i][j] != 'o') {
                return false; // At least one empty cell
            }
        }
    }
    tie = true; // All cells are filled
    return true;
}

void computer_vs_player()
{
    cout<<"Enter player name";
    cin>>player_name;
     while (!checkForWin()) {
            printBoard();
        getPlayerMove();
        
        // After the player's move, check for a win or tie
        if (checkForWin()) {
            break;  // Exit the loop if there's a win or tie
        }
        
        getcomputerchoice();
        
        // After the computer's move, check for a win or tie
        if (checkForWin()) {
            break;  // Exit the loop if there's a win or tie
        }
        }
                printBoard(); // Display the final board
                 if (tie) {
        cout << "It's a draw!" << endl;
    } else if (token == 'o') {
        cout << player_name << " Wins!!" << endl;
        player1_wins++;
    } else {
        cout << "Computer Wins!!" << endl;
        player2_wins++;
    }
}
void player_vs_player()
{
cout << "Enter the name of the 1st player: ";
    cin >> n1;
    cout << "Enter the name of the 2nd player: ";
    cin >> n2;

    cout << endl << "############# " << n1 << " is player 1, and " << n2 << " is player 2 #############" << endl << endl;

        while (!checkForWin()) {
            printBoard();
            getPlayerMove();
        }
                printBoard(); // Display the final board
                if (tie) {
        cout << "It's a draw!" << endl;
    } else if (token == 'x') {
        cout << n2 << " Wins!!" << endl;
        player1_wins++;
    } else {
        cout << n1 << " Wins!!" << endl;
        player2_wins++;
    }
          
}
// Function to reset the game board
void resetBoard() {
    char ch = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            space[i][j] = ch++; // Reset the cell to its original value
        }
    }
    token = 'x'; // Reset the starting player to 'x'
    tie = false;  // Reset the tie flag
}

int main() {

    char wannaplay = 'y';
    do{
    cout<<" 1.Computer vs Player"<<endl;
    cout<<" 2.Player vs Player"<<endl;
    cout<<"Select Game Mode"<<endl;
    cin>>mode;
    
    switch(mode)
    {
        case 1:
        computer_vs_player();
        break;
        case 2:
        player_vs_player();
        break;
        default:
        cout<<"Please select valid game mode"<<endl;
    }

       cout << "Player 1 wins: " << player1_wins << endl;
        cout << "Player 2 wins: " << player2_wins << endl;

        cout << "Do you want to play again (y/n): ";
        cin >> wannaplay;
        if (wannaplay == 'n') {
            cout << "Thanks for playing my game!!!" << endl;
        }
        resetBoard(); // Reset the game board for a new round
    } while (wannaplay == 'y');

    return 0;
}
