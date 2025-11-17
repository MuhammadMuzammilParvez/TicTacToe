Tic-Tac-Toe Console Game in C

Description

This project is a console-based two-player Tic-Tac-Toe game implemented in the C programming language. Two players take turns placing their symbols (X or O) on a 3×3 grid. The game automatically checks for wins, draws, and ensures that all moves are valid. It provides a clear, interactive interface to guide players, making it simple and engaging for users to play directly in the terminal.

The program is designed for beginners learning C and game logic implementation, focusing on arrays, input validation, loops, and condition checking.

Features

Interactive 3×3 grid displayed in the console

Players can enter moves using numbers 1–9 corresponding to board positions

Input validation ensures only numbers within range are accepted

Prevents moves on already occupied cells

Automatic detection of winners (checks all rows, columns, and diagonals)

Detects draw conditions when the board is full without a winner

Alternates turns between players

Displays the board after every move for better game tracking

Player names are stored and displayed for a personalized experience

Technologies Used

Programming Language: C

Libraries:

stdio.h – for input/output operations

stdlib.h – for system commands like clearing the console

Compatible with Windows (system("cls"))

Can be modified for Linux/Mac by replacing system("cls") with system("clear")

How to Run

Save the source code as tictactoe.c.

Open a terminal or command prompt.

Compile the program using a C compiler:

gcc tictactoe.c -o tictactoe

Run the compiled program:

./tictactoe

Enter names for Player X and Player O.

Follow the on-screen prompts to select positions (1–9) and play the game.

The game will continue until a player wins or a draw occurs.

Example Gameplay

Enter name for Player X: Alice
Enter name for Player O: Bob

Choose your move using these numbers:

 1 | 2 | 3
---|---|---
 4 | 5 | 6
---|---|---
 7 | 8 | 9


Alice wins!

<img width="480" height="218" alt="image" src="https://github.com/user-attachments/assets/47636c65-6802-4078-863f-d3f77e00f548" />

Contributors

**Muhammad Muzammil CT-129 
Muhammad Yaqoob Aziz CT-140
Muhammad Hammad CT-125
Syed Muhammad Hanzila CT-127**



