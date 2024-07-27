#include "my_mouse.h"

int solve_maze(Maze *maze) 
{
    // Find entry and exit points
    Point entry = find_entry_exit(maze, maze->entry_char);
    Point exit = find_entry_exit(maze, maze->exit_char);

    // Find the shortest path and mark the path
    int rows = maze->rows;
    int cols = maze->cols;
    Point* path = (Point*)malloc(rows * cols * sizeof(Point));
    int path_size = 0;
    int steps = find_shortest_path(maze, entry, exit, path, &path_size);
    if (steps >= 0) {
        // Mark the path in the maze
        mark_path(maze, path, path_size, entry, exit);

        print_maze(maze);
        printf("%d STEPS!\n", steps);
        return EXIT_SUCCESS;
    } else {
        printf("No path found!\n");
        return EXIT_FAILURE;
    }
}

void mark_path(Maze *maze, Point *path, int path_size, Point entry, Point exit) 
{
    for (int i = 0; i < path_size; ++i) 
    {
        Point p = path[i];
        maze->maze[p.row][p.col] = maze->path_char;
    }
    // Remark the entry/exit points
    maze->maze[entry.row][entry.col] = maze->entry_char;
    maze->maze[exit.row][exit.col] = maze->exit_char;
}
