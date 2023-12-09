//
//  main.cpp
//  TAKE HOME EXAM 3
//
//  Created by Osman Berk An on 26.11.2022.
//

// OSMAN BERK AN 28849


#include <iostream>
#include <string>

using namespace std;

void print(string tictactoeBoard[3][3])   // printing tictactoe board correctly...
{
    cout << "Current board: " << endl;
    for(unsigned int i=0; i<3; i++)
    {
        for(unsigned int j=0; j<3; j++)
        {
            if (j == 0){
                cout <<" ";
            }
            cout << tictactoeBoard[i][j];
            if (j != 2){
                cout <<" | ";
            }

        }
        cout << endl;
        if ( i != 2){
            cout << "-----------"<<endl;
        }
        
    }
}


bool checkFormat(string move)  // check the syntax of move
{
    string tictactoeBoard[3][3];
    bool result;
    if(move == "1-1" || move == "1-2" || move == "1-3" || move == "2-1" || move== "2-2" || move == "2-3" || move== "3-1" || move== "3-2" || move == "3-3")
    {
        result = true;
    }
    else{
        cout << "Please enter correct move format!" << endl;
        result = false;
       
    }
    return result;
}


bool checkWinner(string tictactoeBoard[3][3], string sign)     // check the winner X or O, or  draw
{
    bool winner = false;
    //sign = " " + sign + " ";
    // yatay
    if( tictactoeBoard[0][0] == sign && tictactoeBoard[0][1] == sign && tictactoeBoard[0][2] == sign){
        winner = true;
    }
    else if ( tictactoeBoard[1][0] == sign && tictactoeBoard[1][1] == sign && tictactoeBoard[1][2] == sign){
        winner = true;
    }
    else if ( tictactoeBoard[2][0] == sign && tictactoeBoard[2][1] == sign && tictactoeBoard[2][2] == sign){
        winner = true;
    }
    
    // dikey
    else if ( tictactoeBoard[0][0] == sign && tictactoeBoard[1][0] == sign && tictactoeBoard[2][0] == sign){
        winner = true;
    }

    else if ( tictactoeBoard[0][1] == sign && tictactoeBoard[1][1] == sign && tictactoeBoard[2][1] == sign){
        winner = true;
    }

    else if ( tictactoeBoard[0][2] == sign && tictactoeBoard[1][2] == sign && tictactoeBoard[2][2] == sign){
        winner = true;
    }

    // diagonal
    else if ( tictactoeBoard[0][0] == sign && tictactoeBoard[1][1] == sign && tictactoeBoard[2][2] == sign){
        winner = true;
    }

    else if ( tictactoeBoard[0][2] == sign && tictactoeBoard[1][1] == sign && tictactoeBoard[2][0] == sign){
        winner = true;
    }
    else
        winner = false;
    
    return winner;
}

    

void playerMove(string name, string sign, string tictactoeBoard[3][3])
{
    string location;
    string move;                // move = 1-3
    char move1 , move2;
    
    
    
    cout << name << ", please enter your move: ";
    cin >> move;
    
    if ( checkFormat(move) == false){
        playerMove(name,sign,tictactoeBoard);
        
    }

    else if ( checkFormat(move) == true){
        move1 = move[0]-1;
        move2 = move[2]-1;
        
        // must take move1 and move2 as integers
        int move1_int = int(move1)- int('0');
        int move2_int = int(move2)- int('0');
        
        
        if (tictactoeBoard[move1_int][move2_int] != " " && checkFormat(move) == true)
        {
            cout << "That location is already full!" << endl;
            playerMove(name,sign,tictactoeBoard);
        }
    
        else if (tictactoeBoard[move1_int][move2_int]  == " "  && checkFormat(move) == true){
            tictactoeBoard[move1_int][move2_int] = sign ;
        }
    }
}

void playGame(string &name1, string  &name2, string sign1, string sign2, int & score1, int & score2)
{
    string tictactoeBoard[3][3];
    for(unsigned int i=0; i<3; i++)
    {
        for(unsigned int j=0; j<3; j++)
        {
            tictactoeBoard[i][j] = " ";
        }
    }
    
    int sayac = 0;
    
    while( checkWinner(tictactoeBoard, sign1) == false && checkWinner(tictactoeBoard, sign2) == false && sayac < 9){
        print(tictactoeBoard);
        playerMove(name1, sign1, tictactoeBoard);
        
        sayac ++;
        if (checkWinner(tictactoeBoard, sign1) == false && sayac <9){
            print(tictactoeBoard);
            playerMove(name2, sign2, tictactoeBoard);
            sayac ++;
        }
    }
    
    if (checkWinner(tictactoeBoard, sign1) == true){
        score1++;
        cout << name1 << " is the winner!" << endl;
        
    }
    else if (checkWinner(tictactoeBoard, sign2) == true){
        score2++;
        cout << name2 << " is the winner!" << endl;
        
    }
    else if (checkWinner(tictactoeBoard, sign1) == false && checkWinner(tictactoeBoard, sign2) == false){
        cout << "The game ended in a draw!"<<endl;
        
    }
    
    
    
    
}


int main()
{
 
    string sign1 = "X";
    string sign2 = "O";
    int score1 = 0,score2 = 0;
    string player1, player2;
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "Player 1, please enter your name: ";
    cin >> player1;
    cout << "Hello, " << player1 << ". " << "You are going to play with X" << endl;
    cout << "Player 2, please enter your name: ";
    cin >> player2;
    cout << "Hello, " << player2 << ". " << "You are going to play with O" << endl;
    cout << endl;
    cout << "Starting a new game..." << endl;
    
 
    
    playGame(player1, player2, "X" , "O" , score1, score2);
    cout << "Current Scores: " << endl;
    cout << player1 << ": " << score1 << "   " << player2 << ": " << score2;
    
    cout << endl<< endl;
    
    cout << "Starting a new game..." << endl;
    
    playGame(player2,player1, "O","X",score2,score1);
    cout << "Current Scores: " << endl;
    cout << player1 << ": " << score1 << "   " << player2 << ": " << score2;
    
    cout << endl << endl;
    
    if(score1 == score2){
        cout << "Final Scores: " << endl;
        cout << player1 << ": " << score1 << "   " << player2 << ": " << score2 << endl;
        cout << "The overall game ended in a draw! " << endl;
    }
    
    else if(score1 > score2){
        cout << "Final Scores: " << endl;
        cout << player1 << ": " << score1 << "   " << player2 << ": " << score2 << endl;
        cout << player1 << " is the overall winner!" << endl;
    }
    
    else if(score2 > score1){
        cout << "Final Scores: " << endl;
        cout << player1 << ": " << score1 << "   " << player2 << ": " << score2 << endl;
        cout << player2 << " is the overall winner!" << endl;
    }
    
    return 0;
}
