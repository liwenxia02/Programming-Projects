
#include <string.h>
#include "string_functions.h"

int concat(const char word1[], const char word2[], char result[], int result_capacity){

   //TODO: replace the following stub with a correct function body so that                             
   //      this function behaves as indicated in the comment above                                     
   //                                                                                                  
   //NOTE: you may not use the strcat or strcpy library functions in your solution!                    

  if ((int)(strlen(word1)+strlen(word2)+1)>result_capacity) return 1;
  int index = 0;
  while(index<result_capacity-1)
    {
      if(index>(int)strlen(word1)-1){
        result[index]=word2[index-strlen(word1)];
      }
      else{
        result[index]=word1[index];
      }
      index++;
    }
  result[result_capacity]='\0';
  return 0;
}
