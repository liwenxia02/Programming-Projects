#include <stdio.h>

// TODO: declare the getDate function
int getDate(int *month, int *day, int *year);


int main() {

  int mon = 0;
  int day = 0;
  int yr = 0;

  // TODO: declare and initialize an array of strings that are the names of the
  // months of the year. You can use their 3-character abbreviations, such as "Feb".
  char *months[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
  
  while (  /* TODO: call the getDate function */getDate(&mon,&day,&yr) == 3) {
    printf("%s %d, %d\n", months[mon-1], day, yr);
  }
  
  return 0;
}

// TODO: define the getDate function to prompt for and read a date in the form
// MM/DD/YYYY, passing the inputs as integers back to main through the parameters
// and returning the number of values successfully read
int getDate(int *month, int *day, int *year){
  int m, d, y;
  int inputs;
  printf("enter date in MM/DD/YYYY format: ");
  inputs = scanf("%d/%d/%d",&m,&d,&y);
  *month = m;
  *day = d;
  *year = y;
  return inputs;}
  
