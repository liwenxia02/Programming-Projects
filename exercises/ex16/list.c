#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// put char into a newly created node
Node * create_node(char ch) {
  Node * node = (Node *) malloc(sizeof(Node));
  assert(node); //confirm malloc didn't fail

  node->data = ch;
  node->next = NULL;
  return node;
}

// output the list iteratively
void print(const Node * cur) {
  while (cur != NULL) {
    printf("%c ", cur->data);
    cur = cur->next;  // advance to next node
  }
}

int length(const Node * cur){
  const Node *cur2 = cur;
  int c = 0;
  while(cur2){
    c++;
    cur2=cur2->next;}
  return c;}

void add_after(Node * cur, char data){
  assert(cur);
  Node * new_node = create_node(data);
  new_node->next=cur->next;
  cur->next = new_node;}

void reverse_print(const Node * cur){
  if(cur->next){
    reverse_print(cur->next);}
  printf("%c ", cur->data);}
