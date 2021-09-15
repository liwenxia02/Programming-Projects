//96826C
#include <stdio.h>

void machine(int* stock, double profit){
  //lets you know how much of each item is available, acts as interface of vending machine
  printf("[0] %d cola left: cost is $0.75\n[1] %d candybar left: cost is $1.25\n[2] %d popcorn left: cost is $0.50\nMoney made so far is $%0.2f\n",stock[0],stock[1],stock[2],profit);
}

int main (void){
  //all variables initialized
  int stock[]={5,5,5};
  const double price[]={0.75,1.25,0.50};
  double profit = 0.0,cash=0.0,change=0.0;
  int numInput = 0, selection = -1;
  const char item[3][9]={"cola","candybar","popcorn"}; 
  
  printf("Welcome to the Vending Machine!\nEnter your choice by # and input cash amount, repeatedly (^d to end).");
  machine(stock,profit);

  //loop continues until error message or ctrl-d
  while((numInput=scanf(" %d%lf",&selection,&cash))!=EOF){
      //error scenarios
      if(numInput!=2||selection<0||cash<0){
	printf("malformed expression\n");
	return 1;
      }
      if(selection>2||stock[selection]<1){
	printf("invalid item\n");
	return 2;
      }
      if(cash<price[selection]){
	printf("not enough money\n");
	return 3;
      }
      //calculations
      change = cash - price[selection];
      profit+=price[selection];
      stock[selection]--;
      //ending message for each iteration
      printf("%s is dispensed and $%0.2f returned\n",item[selection],change);
      machine(stock,profit);
    }
  printf("Thanks for your patronage!\n");
    return 0;
}
