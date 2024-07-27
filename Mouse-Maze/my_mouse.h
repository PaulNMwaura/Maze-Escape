#ifndef MY_MOUSE_H
#define MY_MOUSE_H

// Header files:
#include <stdio.h>      /* printf()                     */
#include <stdlib.h>     /* malloc(), free()             */
#include <stdbool.h>
#include <string.h>


#define DEBUG 0

# define MAP_ERROR "MAP ERROR"

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    int row;
    int col;
    int distance;  // To store the distance from the starting point
} Point;

typedef struct {
    int rows;
    int cols;
    char full_char;                     // '*'
    char empty_char;                    // ' '
    char path_char;                     // 'o'
    char entry_char;                    // '1'
    char exit_char;                     // '2'
    char maze[MAX_ROWS][MAX_COLS];
} Maze;

// Function prototypes
void read_maze(FILE *file, Maze *maze);                             // inside of check_maze.c
void print_maze(const Maze *maze);                                  // inside of check_maze.c
Point find_entry_exit(const Maze *maze, char entryExitChar);        // inside of check_maze.c
void print_point(const Point *point);                               // inside of check_maze.c

bool validate_maze(const Maze *maze);                               // inside of validate.c

bool is_safe(const Maze *maze, int row, int col);                   // inside of find_shortest_path.c
int find_shortest_path(Maze *maze, Point start, Point end, Point *path, int *path_size);

int solve_maze(Maze *maze);                                                         // inside of solve_mark.c
void mark_path(Maze *maze, Point *path, int path_size, Point entry, Point exit);    // inside of solve_mark.c

#endif