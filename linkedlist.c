#include <stdio.h>
#include <stdlib.h>

struct node {int i; struct node *knowed;};

void print_list(struct node *nod) {
  printf("[");
  while (nod) {
    printf("%d ", nod->i);
    nod = nod->knowed;
  }
  printf("]\n");
}

struct node *free_list(struct node *beg) {
  struct node *init = beg;
  struct node *knowed=(struct node *)malloc(sizeof(struct node));
  while (beg) {
    knowed = beg->knowed;
    free(beg);
    beg = knowed;
  }
  return init;
}

struct node *insert_front(struct node* nod, int d) {
  struct node *new=(struct node *)malloc(sizeof(struct node));
  new->i=d;
  new->knowed=nod;
  return new;
}

int main() {
  struct node *a;
  a=(struct node *)malloc(sizeof(struct node));
  a->knowed=NULL;
  a->i=5;
	
  struct node *b;
  b=(struct node *)malloc(sizeof(struct node));
  b->knowed=NULL;
  b->i=8;
	
  printf("---- testing print_list\n");
  print_list(a);
	 
  printf("---- testing insert_front\n");
  printf("about to call insert_front (a, 4) ...\n");
  a=insert_front (a,4);
  print_list(a);
	 
  printf("---- testing free_list(a)\n");
  free_list(a);
  printf("a=");
  print_list(a);
	 
}
