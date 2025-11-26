Snake Game in C++

A simple and classic Snake Game implemented in C++ using the Windows Console.
The player controls the snake using the arrow keys, eats fruits to grow the tail, and increases the score.
The game ends when the snake hits the wall or its own tail.

🎮 Features

✔ Arrow key controls (↑ ↓ ← →)

✔ Dynamic tail growth

✔ Score tracking

✔ Random fruit generation

✔ Difficulty selection (Easy / Medium / Hard)

✔ Game Over detection

✔ Clean and structured C++ OOP design

📂 Project Structure
SnakeGame/
│── snake.cpp       # Main game logic
│── README.md       # Documentation
│── .gitignore      # (Optional)

🛠 Requirements

This project uses Windows-specific headers:

  <conio.h> for _kbhit() and _getch()

  <windows.h> for Sleep()

Supported Platforms:

  Windows 10 / 11

Compilers:

  MinGW g++


▶️ How to Compile & Run
1. Compile the program

Using MinGW (g++):

  g++ snake.cpp -o snake.exe

2. Run the game
  ./snake.exe

🎮 Controls
Key	Action
↑	Move Up
↓	Move Down
←	Move Left
→	Move Right
X	Exit Game
🧱 Gameplay

The snake (O) moves around in a bordered area.

Fruit (#) appears at random positions.

Eating a fruit:

Increases score (+10)

Increases tail size

Game ends if:

Snake hits the wall

Snake hits its own tail

Player presses X

⚙️ Difficulty Levels

At the start, you can choose:

1 → Easy (slow speed)

2 → Medium (default)

3 → Hard (fast speed)

Each option adjusts the delay using Sleep().

📝 Code Highlights

Object-oriented design
All game logic handled inside the SnakeGame class.

Real-time input detection
With _kbhit() and _getch() to detect arrow keys.

Tail movement logic
Uses arrays to shift previous coordinates and update the tail.

👩‍💻 Author

Arya Ravi

Project created as part of learning C++, game logic, and console-based programming.
