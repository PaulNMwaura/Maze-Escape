# Mouse-Maze
Mouse-Maze is a C program designed to read a maze from a file, identify the starting and exit coordinates, and find and display the shortest path between them by Utilizing the BFS algorithm as well as backtracking.

# How it works
First the program reads the maze from a file and into a 2d matrix.
It then traverses the maze to find the entry and exit coordinates.
It creates a queue and traverses the maze starting from the entry point, each time checking for empty coordinates that may lead to our exit coordinate.
When it traverses on a coordinate, it checks if it is valid (meaning it is in bounds of the maze), and if it too has a next coordinate that is valid.
If so, we add it to the queue, then move to the next empty coordinate. 
We repeat this process until we reach the exit, or until we are unable to move any further, in which case the program ends either if since no path was found or
the maze is invalid.

## Features
Given a maze, the program finds the starting point, the end point, and the shortest path between
the two while also returning the distance of the shortest path. 
The maze is represented by a file passed as the argument.

## Maze File Format
The maze file should be formatted as follows:  
    - The first line of the file contains  
        • [<rows>]: Number of rows in the maze.  
        • [<cols>]: Number of columns in the maze.  
        • [<full_char>]: Character representing walls ('*').  
        • [<path_char>]: Character representing the path ('o').  
        • [<entry_char>]: Character representing the entry point ('1').  
        • [<exit_char>]: Character representing the exit point ('2').  
    - Followed by the Maze grid  
```
<rows>x<cols> <full_char> <path_char> <entry_char> <exit_char>
<maze_row_1>
<maze_row_2>
...
<maze_row_n>
```
# Example
```
4x4* o12
**1*
*  *
*2**
```

## Requirements
    • GCC (GNU Compiler Collection)  
    • GNU Make Utility  

## Installation
1. Clone this repository:
```
git clone https://github.com/PaulNMwaura/Mouse-Maze-Escape.git
cd Mouse-Maze
```
2. Build the program using the provided Makefile:  
```
make
```


## Usage
Given a correctly formatted maze, the program will mark the shortest path from the starting point to the exit point as well as print the distance of that path (If there is one).  
If there is no path to the exit, "No path found!" will be printed out.  
If the map is not formatted correctly, "MAP ERROR" will be printed out.  

Run the program with the following command:
```
./my_mouse [<file_with_maze>]
```
Replace [<file_with_maze>] with the path to your maze file.  

### The Core Team
<span><i>This project was built in collaboration between Selcuk Aksoy and Paul Mwaura</i></span>
