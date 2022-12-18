#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *right;
  struct Node *left;
};

struct Node *addNode (int val) {
  struct Node *temp;
  temp = (struct Node*)malloc(sizeof(struct Node));

  if (temp != NULL) {
    temp->data = val;
    temp->right = NULL;
    temp->left = NULL;

    return temp;
  }; 

  return temp;
};

void getTree(struct Node *root) {
  if (root == NULL) {
    printf("<Empty>\n");
    return;
  };

  printf(" %d\n", root->data);
  printf("left\n");
  getTree(root->left);
  printf("rigth\n");
  getTree(root->right);
}

int main() {
  struct Node *n1 = addNode(1);
  struct Node *n2 = addNode(2);
  struct Node *n3 = addNode(3);
  struct Node *n4 = addNode(4);
  struct Node *n5 = addNode(5);

  n1->left = n2;
  n1->right = n3;
  n3->left = n4;
  n3->right = n5;

  getTree(n1);

  free(n1);
  free(n2);
  free(n3);
  free(n4);
  free(n5);

  return 0;
};
