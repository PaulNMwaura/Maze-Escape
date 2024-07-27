#include "my_mouse.h"

bool validate_dimensions(const Maze *maze) 
{
    // Check if the maze dimensions are within the allowed range
    if (maze->rows <= 0 || maze->rows > MAX_ROWS || maze->cols <= 0 || maze->cols > MAX_COLS) 
    {
        return false;
    }
    return true;
}

void count_entrances_and_exits(const Maze *maze, int *entrance_count, int *exit_count) 
{
    *entrance_count = 0;
    *exit_count = 0;

    for (int i = 0; i < maze->rows; ++i) 
    {
        for (int j = 0; j < maze->cols; ++j) 
        {
            char cell = maze->maze[i][j];
            if (cell == maze->entry_char) 
            {
                (*entrance_count)++;
            } 
            else if (cell == maze->exit_char) 
            {
                (*exit_count)++;
            }
        }
    }
}

bool check_invalid_characters(const Maze *maze) 
{
    for (int i = 0; i < maze->rows; ++i) 
    {
        for (int j = 0; j < maze->cols; ++j) 
        {
            char cell = maze->maze[i][j];
            if (cell != maze->full_char && cell != ' ' && cell != maze->path_char &&
                cell != maze->entry_char && cell != maze->exit_char) 
                {
                return false;
            }
        }
    }
    return true;
}

bool validate_maze(const Maze *maze) 
{
    if (!validate_dimensions(maze)) { // Validate dimensions
        return false;
    }

    // Count entrances and exits
    int entrance_count, exit_count;
    count_entrances_and_exits(maze, &entrance_count, &exit_count);

    if (!check_invalid_characters(maze)) { // Check for invalid characters
        return false;
    }

    // There should be exactly one entrance and one exit
    if (entrance_count != 1 || exit_count != 1) {
        return false;
    }

    // The maze is considered valid if it passes all the checks
    return true;
}
