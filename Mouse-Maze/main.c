#include <stdlib.h>
#include "my_mouse.h"

int parse_arguments(int argc, char *argv[]) 
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <maze_file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int process_file(const char *filename, Maze *maze) 
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) 
    {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    read_maze(file, maze);
    fclose(file);
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) 
{
    if (parse_arguments(argc, argv) != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }

    Maze maze;
    if (process_file(argv[1], &maze) != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }
    
    if (!validate_maze(&maze)) {
        fprintf(stderr, MAP_ERROR);
        return EXIT_FAILURE;
    }

    return solve_maze(&maze);
}
