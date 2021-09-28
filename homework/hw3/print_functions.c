#include "print_functions.h"
#include <stdio.h>

/**
 * \file print_functions.c
 * \brief Provides print-related functionalities
 *
 * \details This source file implements all print-related functionalities for printing the maze, solution, and errors
 */

// The function to print the maze
void printMaze(char maze[][200], const int maze_width, const int maze_height) {
  // TODO: implement this function
  printf("Maze: %d, %d", maze_width, maze_height);
  for(int r = 0; r <maze_height, ++r){
    for(int c = 0; c < maze_width, ++c){
      if(c==maze_width-1){
	printf("%c\n",maze[r][c]);
      }
      else{
	printf("%c",maze[r][c]);}
}

// The function to print the maze's solution
void printSolution(char maze[][200], const int maze_width, const int maze_height, char sol[][200]) {
  // TODO: implement this function
printf("Solution path (*):");
  for(int r = 0; r <maze_height, ++r){
    for(int c = 0; c < maze_width, ++c){
      if(maze[r][c]==" "&&sol[r][c]!=" "){
	if(c==maze_width-1){
        printf("%c\n",sol[r][c]);
      }
      else{
        printf("%c",sol[r][c]);}
      }
      else{
      if(c==maze_width-1){
        printf("%c\n",maze[r][c]);
      }
      else{
        printf("%c",maze[r][c]);}}
}

// The function to print the error message
void printError(const int return_code, char* argv[]) {
  // TODO: implement this function
}
