#include "my_mouse.h"

void read_maze(FILE *file, Maze *maze) 
{
    fscanf(file, "%dx%d %c %c %c %c\n", &maze->rows, &maze->cols, &maze->full_char, &maze->path_char, &maze->entry_char, &maze->exit_char);
    // Function fscanf can't scan ' ' so i added separetly
    maze->empty_char = ' ';

    for (int i = 0; i < maze->rows; ++i) {
        if (fgets(maze->maze[i], MAX_COLS + 1, file) == NULL) {
            fprintf(stderr, "Error reading maze.\n");
            exit(EXIT_FAILURE);
        }

        // Remove newline character if present
        size_t len = strlen(maze->maze[i]);
        if (len > 0 && maze->maze[i][len - 1] == '\n') {
            maze->maze[i][len - 1] = '\0';
        }
    }
}


void print_maze(const Maze *maze) 
{
    printf("%dx%d%c%c%c%c%c\n", maze->rows, maze->cols, maze->full_char, ' ', maze->path_char, maze->entry_char, maze->exit_char);
    for (int i = 0; i < maze->rows; ++i) 
    {
        printf("%s\n", maze->maze[i]);
    }
}

// Find the desired Point of the given char in the Map
Point find_entry_exit(const Maze *maze, char entry_exit_char) 
{
    Point entry_exit = { -1, -1 , 0};

    for (int i = 0; i < maze->rows; ++i) 
    {
        for (int j = 0; j < maze->cols; ++j) 
        {
            if (maze->maze[i][j] == entry_exit_char) 
            {
                entry_exit.row = i;
                entry_exit.col = j;
                return entry_exit;
            }
        }
    }

    return entry_exit;
}

void print_point(const Point *point) 
{
    printf("Row: %d, Col: %d, Steps: %d\n", point->row, point->col, point->distance);
}