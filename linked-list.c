#include <stdio.h>
#include <stdlib.h>


struct node {
  struct node *next;
  int data;
};

void getNode(struct node* current) {
  struct node* temp = current;
  while(temp != NULL) {
    printf(" %d", temp->data);
    temp = temp->next;
  };
};

struct node *insertNode(int value) {
  struct node *new = malloc(sizeof(struct node));
  new->data = value;
  new->next = NULL;

  return new;
};

int main() {
  struct node *head = NULL;
  struct node *tmp;
  
  for (int i = 0; i < 20; i++) {
    tmp = insertNode(i);
    tmp->next = head;
    head = tmp;
  }

  getNode(head);

  return 0;

};

