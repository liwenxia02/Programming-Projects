#include "maze.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * \file maze.c
 * \brief Provides maze-related functionalities
 *
 * \details This source file implements all maze-related functionalities for reading/writing/solving/generating the maze and releasing related memories.
 */

/* The function to read the maze from a file given the filename, maze
   array, maze width and maze height: open file, read sizes, read maze, close file
*/
// TODO: write the entirety of this readMaze function
//ask about readMaze
int readMaze(char* filename, char maze[][200], int* maze_width, int* maze_height){
  FILE*mazePtr=fopen(filename,"r");
  if(mazePtr==NULL){
    return -1;}
  char myChar,newline;
  fscanf(mazePtr, "%d %d", maze_width, maze_height);
  fscanf(mazePtr, "%c",&newline); //used to skip the newline character in the file
  //printf("%d %d", *maze_width, *maze_height);
  for(int r = 0; r < *maze_height; ++r){
    for(int c = 0; c <= *maze_width; ++c){
      fscanf(mazePtr,"%c",&myChar);
      maze[r][c]=myChar;
    }
  }
  if(ferror(mazePtr)){ //error catching
    return -2;}
  fclose(mazePtr);
  return 0;
}

/* The function to write the maze to a file given the filename, maze
   array, maze width and maze height: open file, write maze, close file
*/
// TODO: write the entirety of this writeMaze function

int writeMaze(char* filename, char maze[][200], const int maze_width, const int maze_height){
  FILE*mazePtr=fopen(filename,"w");
  if(mazePtr==NULL){
    return -4;}
  fprintf(mazePtr,"%d %d\n", maze_width, maze_height);
  for (int r = 0; r < maze_height; ++r){
    for(int c = 0; c < maze_width; ++c){
      if(c==maze_width-1)
	{
	  fprintf(mazePtr, "%c\n", maze[r][c]); //prints a newline char if at the end of the row
	}
      else{
	fprintf(mazePtr, "%c", maze[r][c]);
      }}}
  if(ferror(mazePtr)){
    return -5;}
  fclose(mazePtr);
  return 0;
}

// The function to solve a solution path for the maze
int solveMaze(char maze[][200], const int maze_width, const int maze_height, char sol[][200]) {
  // TODO: implement this function
  int startingR, startingC;
  for(int r = 0; r < maze_height; r++){
    for(int c = 0; c < maze_width; c++){
      if(maze[r][c]=='@'){
	 startingR=r;
	 startingC=c; //keeps track of the starting point, not really used but i had it just in case
      }
      sol[r][c]='u'; //marks everything as unvisited
    }
  }
  return solvePath(maze, maze_width, maze_height, startingC, startingR, sol); 
}

// The function to solve a solution path recursively
int solvePath(char maze[][200], const int maze_width, const int maze_height, const int col, const int row, char sol[][200]) {
  // TODO: implement this function
  //don't forget left, right, up, down
  if(maze[row][col]=='@'){
    //marks location of starting point in the solution array
    sol[row][col]='@';}
  if(maze[row][col]=='<'){
    //marks location of ending point in the solution array
    sol[row][col]='<';//base case for recursion
    return 0;}
  else if(sol[row][col]!='v' && maze[row][col]!= '#'){
    if(maze[row][col]!='@'){
      sol[row][col]= 'v';} //marking as visited
    if(!solvePath(maze,maze_width,maze_height,col-1,row,sol)||!solvePath(maze,maze_width,maze_height,col+1,row,sol)||!solvePath(maze,maze_width,maze_height,col,row-1,sol)||!solvePath(maze,maze_width,maze_height,col,row+1,sol)){ //checks each direction in order from left, right, up and down
      if(maze[row][col]!='@'){
	sol[row][col] = '*';}
      return 0;
    }
    else{return 1;} //if no free blocks and not at the end, return 1
  }
  else{return 1;} //if we've already been here or it's a wall, then return 1
}

// The function to generate a maze (given)
void genMaze(char maze[][200], const int maze_width, const int maze_height, const double threshold, const int seed) {
  // set random seed
  srand(seed);
  // gen start and end positions
  int start_x = rand() % (maze_width - 2) + 1;
  int start_y = rand() % (maze_height - 2) + 1;
  int end_x = rand() % (maze_width - 2) + 1;
  int end_y = rand() % (maze_height - 2) + 1;
  // gen maze
  for (int r = 0; r < maze_height; ++r) {
    for (int c = 0; c < maze_width; ++c) {
      if (r == 0 || c == 0 || r == maze_height - 1 || c == maze_width - 1) maze[r][c] = '#';
      else if (c == start_x && r == start_y) maze[r][c] = '@';
      else if (c == end_x && r == end_y) maze[r][c] = '<';
      else {
        double rand_value = rand() / (double) RAND_MAX;
        if (rand_value >= threshold) maze[r][c] = '#';
        else maze[r][c] = ' ';
      }
    }
  }
}

