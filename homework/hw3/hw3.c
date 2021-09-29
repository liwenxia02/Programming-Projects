#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maze.h"
#include "print_functions.h"

/**
 * \file hw3.c
 * \brief The main driver function of HW 3
 *
 * \details This source file implements the main function for HW 3. It checks the input command line arguments and calls the corresponding modules.
 */

//I included the string library to convert string arguments into integers in my program
int main(int argc, char* argv[]) {
  int return_code = 0;
  
  // check input arguments
  // solve maze: ./hw3 <maze_file>
  // gen maze: ./hw3 <maze_file> <width> <height> [threshold = 0.5] [seed = 0]

  if ( /* TODO: Replace this stub to check command line arguments */
      !(argc>2 && argc<7 ))
    return_code = 2; // invalid input arguments
  else {
    char maze[200][200];
    int maze_width = 0;
    int maze_height = 0;
    if (argc == 2) { // solve maze
      // read maze file
      return_code = readMaze(argv[1], maze, &maze_width, &maze_height) ;   // TODO: replace with call to your readMaze function 
      if (!return_code) {
        // print maze
        printMaze(maze, maze_width, maze_height);
        // solve maze
        char soln[200][200];  
        return_code = solveMaze(maze, maze_width, maze_height, soln);
        if (!return_code) {
          // print solution
          printSolution(maze, maze_width, maze_height, soln);
        }
      }
    }
    else { // gen maze
      // parse input arguments
      if(atoi(argv[2])<1||atoi(argv[3])<1)
	{
	  return_code = -3;}
      int seed = 0;
      double threshold = 0.5;
      if(argc>4){
	threshold = atof(argv[4]);
	seed = atoi(argv[5]);}
      // TODO: add your argument parsing code and input validation code here
      // remember to set the correct return_code
      
      if (!return_code) {
        // gen maze
        genMaze(maze, maze_width, maze_height, threshold, seed);
        // print maze
        printMaze(maze, maze_width, maze_height);
        // write maze
        return_code = writeMaze(argv[1],maze,maze_width,maze_height);   // TODO: replace with call to your writeMaze function
      }
    }
  }
  
  if (return_code) printError(return_code, argv);
  
  return return_code;
}
