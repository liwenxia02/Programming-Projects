//Ex2-1: gpa_simple.c

/* The purpose of this program is to compute GPAs for simple letter
   grades - no +/-, only A, B, C, D, F. Credits may be rational
   numbers.  Also determine and display notices for Dean's List
   (>=3.5) and Academic Probation (< 2.0).

SAMPLE RUN:

Welcome to the GPA calculator!
Enter grade and credits for each course below (ctrl-d to end):
course 1: A 4.0
course 2: b 2.7
course 3: B 3.5
course 4: c 3.0
course 5: f 1
course 6: a 3
course 7: 
Your GPA is 3.06

-----
PSEUDOCODE:

point_sum gets 0
credit_sum gets 0
points gets 0
gpa gets 0

display “Welcome to GPA calculator!”
prompt for list of grade/credits pairs

count gets 1
display "course #", count

repeat while there is a grade and credits to read
    convert grade to points
    add points * credits to point_sum
    add credits to credit_sum
    add 1 to count
    display "course #", count

if credit_sum > 0
   set gpa to point_sum / credit_sum
   display "GPA is ", gpa
   if gpa >= 3.5
      display "Dean's List"
   otherwise if gpa <= 2.0
      display "Uh-oh, Academic Probation..."
otherwise
   display "No credits attempted; no GPA to report"

*/


#include <stdio.h>

int main() {

  //TO DO: add your code here so that your program
  //produces output that would be identical to the
  //given sample run when provided the same input
  int numCourses = 0, numInput = 0;
  double inCredit = 0., inGPA = 0., avgGPA=0.;
  double accCredits = 0., accGPAs = 0.;
  char inGrade = 0;
  printf("Welcome to the GPA calculator!\nEnter grade and credits for each course below (ctrl-d to end):");

  while(printf("course %d: ",++numCourses)&&(numInput=scanf(" %c%lf", &inGrade, &inCredit))!=EOF){
    if(numInput!=2) printf("Wrong # of input for course %d\n", numCourses--);
    else{
      switch(inGrade){
      case 'A': case 'a': inGPA = 4.; break;
      case 'B': case 'b': inGPA = 3.; break;
      case 'C': case 'c': inGPA = 2.; break;
      case 'D': case 'd': inGPA = 1.; break;
      case 'F': case 'f': inGPA = 0.; break;
      default: printf("Wrong letter grade input: %c for course %d\n", inGrade, numCourses--);
  }
      if(inCredit>0){
	accGPAs += inCredit * inGPA;
	accCredits+=inCredit;
      }
      else printf("Input credit should be positive for course %d\n",numCourses--);
    }
  }
    if(accCredits>0){
      avgGPA = accGPAs/ accCredits;
      printf("\nYour GPA is %lf\n", avgGPA);
      if(avgGPA>=3.5) printf("Dean's List\n");
      else if (avgGPA <= 2.0) printf("Uh-oh, Academic Probation...\n");
    }
    else printf("\nNo credits attempted; no GPA to report\n");
 return 0;
}

