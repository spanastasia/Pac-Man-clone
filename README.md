1. System requirements

Operating system: Windows.

Hardware requirements: user (programmer) requires
- processor: Pentium Processor;
- RAM: 640 Kb (min);
- Hard Disc: 1 Gb (min).


2. About game “Pac-Man”
Pac-Man is a maze chaze video game. The player controls character through an enclosed maze. The objective of the game is to eat all points in the maze avoiding collisions with ghosts. 
Ghosts are in their “house” at the beginning of the game and start moving in a few seconds after start. Each ghost moves with it’s own velocity but slower then Pac-Man and they can chase the character or scatter in the labyrinth. 
There are two large tunnels to the sides of the maze, which allows to travel to the opposite side of the screen. 
Pac-Man has three reserve lives. If Pac-Man collides a ghost and there is at least one reserve life, all characters return to their start positions with saving eated points. Otherwise the game is over.


3. User guide
Find and run file Pacman.exe in folder Pac-Man_clone.
After running the console window with started game will be opened.
Use buttons up “↑”, down “↓”, left “←”, write “→” to run Pac-Man. Try to eat all the points and avoid ghosts. If Pac-Man and the ghosts are on the same position, one live will be lost. The game is over when all points are eaten or all lives are used.
Information about current score and number of reserve lives is placed under the maze.
Press Escape to pause the game. Press Enter to continue playing or Escape to finish the game.
Press Enter to finish the program.


4. Programmer instruction
Find and open the file Pacman.dev in folder Pac-Man_clone. For edition, debugging and compiling program code use Dev C++.

Main global variables:
int arr[LEN][WID] - basic array;
int grid[LEN][WID] - auxiliary array for finding the shortest way;
int px[LEN * WID], py[LEN * WID] - hold coordinates of points on current way;
Square maze[LEN][WID] - array of structures that hold current information about every square in the maze;
Square pacman, Square ghost1, Square ghost2, Square ghost3 - structures that contain current information about each character;
int lives[3] - array of reserve lives;
int prevX[4], int prevY[4] - arrays that hold coordinates of previous position of Pac-Man and a ghost.
Main functions:
void Setup() - initialize an array of Square structures;
void Draw() - gets an array of Square structures as an argument and draws a labyrinth;
void Input() - catches key presses and changes position of Pa-Man;
int leaveHome() - gets a structure of type Square as an argument, moves a character from home and returns 1, or returns 0, if the character is not at home;
void intilizeWaveMatrix() - initializes wave matrix;
int lee() - implementation of Lee algorithm of finding the shortest way from point A to point B;
void drawSquare() - gets number of character (0 - pacman, 1 - 3 is for ghosts), arrays with previous position of character, pointer to this character and array of Squares. Draws characters in their new positions.


5. About author

This project was done by Anastasiia Spiridonova – Vinnitsya IT-Academy student (group B19, March 2020).
