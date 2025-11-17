#include <stdio.h>
    #include <stdlib.h>

    char board[3][3]; //here we define a 2d array

    void initializeBoard() {
        for(int i = 0; i < 3; i++)  //we loop throug all the rows of the array
            for(int j = 0; j < 3; j++) //loop through all the coloumns of the array
                board[i][j] = ' ';  //iniialize all the rows and coloumns of the 2 d array to be empty
    }

    void printStartGuide() {
        printf("\nChoose your move using these numbers:\n\n"); //here we dispay a sample tic tac toe table for the players help to tell them which digit corresponds to which place in the  tic tac toe table 
        printf(" 1 | 2 | 3 \n"); //it is the row 1
        printf("---|---|---\n");
        printf(" 4 | 5 | 6 \n");  //it is the row 2
        printf("---|---|---\n");  
        printf(" 7 | 8 | 9 \n\n"); //it is the row 3
    }

    void printBoard() {
        system("cls");  //it prvents printing of the tic tac toe table again and again

        printf("\n"); //print newline
        for(int i = 0; i < 3; i++) { //loop through all the rows of the 2d array
            printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]); //here the coloumns are fixed ony the rows are acessed by the loop
            if(i < 2) printf("---|---|---\n"); //it is used to print the space after the 0th and the 1 th count
        }
        printf("\n");//it is to print a new line after every iteration
    }

    char checkWinner() { //it check for any combination that mkes the plaer1 or player2 a winner
        for(int i = 0; i < 3; i++) {  // Check each row for a win 
            if(board[i][0] == board[i][1] &&
            board[i][1] == board[i][2] &&
            board[i][0] != ' ')
                return board[i][0]; // it is used for checking that if al thrre rows have the same symbol and is not empty then return winner either player1 or player2 

            if(board[0][i] == board[1][i] && // Check each coloumn for a win 
            board[1][i] == board[2][i] &&
            board[0][i] != ' ')
                return board[0][i];// it is used for checking that if all three coloumns have the same symbol and is not empty then return winner either player1 or player2
        }

        if(board[0][0] == board[1][1] && // Check the main diagonal from top-left to bottom-right
        board[1][1] == board[2][2] &&
        board[0][0] != ' ')
            return board[0][0];// it is used for checking that if all three main diagonal have the same symbol and is not empty then return winner either player1 or player2

        if(board[0][2] == board[1][1] &&// Check the anti  diagonal from top-right to bottom-left
        board[1][1] == board[2][0] &&
        board[0][2] != ' ')
            return board[0][2];// it is used for checking that if all three   anti diagonal have the same symbol and is not empty then return winner either player1 or player

        return ' ';// If no one has won return space to the function call to indicate no winner
    }

    int isDraw() {
        for(int i = 0; i < 3; i++) // go through each row of the board
            for(int j = 0; j < 3; j++) // go through each column in the row step by step 
                if(board[i][j] == ' ')// check if any cell is  empty or not
                    return 0;  // If there is an empty cell it is not  draw yet
        return 1;// If all the cells in the board are filled and no winner has announced yet return 1 to indicate a draw
    }
int getMove() {
    char input[100]; //used to store the digit in the character form the players type according to the sample tic tac toe table 
    int move; //after validating that the players type the right digit we change the character to the int using sscanf 
    char extra;//to detect that if the player enter the extra characters

    while(1) { //this is ued to repeat the loop until the player type the right input
        printf("Enter position (1-9): "); //ask the user to enter the digit
        if (!fgets(input, sizeof(input), stdin)) { // if the eading input fails ask the player again for the input
            continue; 
        }

        
        if (sscanf(input, " %d %c", &move, &extra) != 1) { //this block ensures that exactly one digit is inputed from the user if there is any more then ask the player again
            printf("Invalid input. Only whole numbers 1-9 allowed.\n");
            continue;
        }

        if (move < 1 || move > 9) { //check that the player input is the range of 1 to 9 only
            printf("Number must be between 1 and 9.\n");
            continue;
        }

        return move; //  if it is a valid move return the move to the main function
    }
}



    int main() {
        char player1[5], player2[5]; //here we define two variables to store the names of two players playing
        char player = 'X';           //the game will stat from the first player
        int choice;                //it is to keep the track of the choices the player1 and player2 are chosing
        
        printf("Enter name for Player X: ");
        scanf("%s", player1);  //stores the name of first player
        
        printf("Enter name for Player O: ");
        scanf("%s", player2); //stores the name of second player
        
        initializeBoard();   //now we call the function to make a 2d array in the memory
        
        printStartGuide();    // here we call the function 2 to print a sample tic tac toe table showing the position where the user will enter their symbol 
        printf("Press any key to start___"); //ask the user to start the game
        getchar(); //the first getchar is used to absorb the new line by the input taking
        getchar(); //the second getchar wait so that the user can press any key
        
        printBoard();          // it is a function call to print the current staus of the tic tac toe board
        
       while(1) { //it is a loop to keep runing the code untils any layer win lose or it is a draw
    printf("%s (%c), enter position (1-9): ", //here is the use of ternary operator to keep the track of which players turn is now going on and to prints ts name by printf statement
        (player == 'X' ? player1 : player2), player);//if the player is x then it will be player 1 otherwise player 2
        
    choice = getMove();  //here we call the function to take input from the player respectively
    
    int row = (choice - 1) / 3;// Convert the player's choice (1-9) into a row index (0-2)
    int col = (choice - 1) % 3;// Convert the player's choice (1-9) into a column index (0-2)
    
    if(board[row][col] != ' ') {// Check if the chosen cell which the player chose is already occupied
        printf("That spot is already taken!\n");//give Warning to the player
        continue; //repeat the loop again
    }
    
    board[row][col] = player;// Place the current player's symbol (X or O) in the chosen cell
    printBoard();// Display the updated tic tac toe board on the screen
    
    char winner = checkWinner();// Call the function to check if any player has won
    if(winner != ' ') {   //it  checks that if the winner is someone. 
    
        if(winner == 'X')  // If the winner is 'X'
            printf("%s wins!\n", player1);//used to print player X's name as the winner
        else
            printf("%s wins!\n", player2);  // If the winner is not 'X', it must be 'O'
        break;  // Stop the game loop because the game is over 
    }
    
    if(isDraw()) {
        printf("It's a draw!\n");// If the board is full and no one has won print that it is a draw
        break; //stop the loop
    }

    player = (player == 'X') ? 'O' : 'X';   // used to switch the player  if current player is X  make it O; if O, make it X
}
        return 0; // end the program successful`ly
    }