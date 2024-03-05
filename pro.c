#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  char name[100];
  int id;
  struct Node* next;
};


struct Node* head = NULL;

void OrderInsert(char name[100], int id) {
  struct Node* newnode = malloc(sizeof(struct Node));
  strcpy(newnode->name, name);
  newnode->id = id;
  newnode->next = NULL;

  if (head == NULL || id < head->id) {
    newnode->next = head;
    head = newnode;
    return;
  }

  struct Node *current = head;
  while (current != NULL) {
    if (current->id == id) {
      printf("Sorry!  ID already exists : %d!\n", id);
      free(newnode);
      return;
    }
    current = current->next;
  }

  current = head;

  while (current->next != NULL && current->next->id < id) {
    current = current->next;
  }

  newnode->next = current->next;
  current->next = newnode;
}

void Update(int id, char name[100]) {

  struct Node* current = head;

  while (current != NULL && current->id != id) {
    current = current->next;
  }

  if (current != NULL) {
    strcpy(current->name, name);
  }

  else {
    printf("Sorry! There is no such person : %d!\n", id);
    return;
  }

}

void Delete(int id) {

  if (!head) {
    printf("Sorry! There is no such person: %d!\\n", id);
    return;
  }

  struct Node* current = head;

  if (head->id == id) {
    head = head->next;
    free(current);
    return;
  }

  struct Node* prev = NULL;

  while (current != NULL && current->id != id) {
    prev = current;
    current = current->next;
  }

  if (!current) {
    printf("Sorry! There is no such person: %d!\\n", id);
    return;
  }

  
  prev->next = current->next;

  free(current);

}

void Print() {
  struct Node *current;
  current = head;
  while (current != NULL) {
    printf("%s %d\n", current->name, current->id);
    current = current->next;
  }

}

int main() {

  char command[40];

  char name[100];

  int id;

  int result;

  while ((result = scanf("%s", command)) != EOF) {

    if (strcmp(command, "q") == 0) {
      break;
    }

    if ( strcmp(command, "a") == 0 ) {
      scanf("%s", name);
      scanf("%d", &id);
      OrderInsert(name, id);
    }

    else if ( strcmp(command, "d") == 0 ) {
      scanf("%d", &id);
      Delete(id);
    }

    else if ( strcmp(command, "u") == 0 ) {
      scanf("%d", &id);
      scanf("%s", name);
      Update(id, name);
    }

    else if ( strcmp(command, "p") == 0 ) {
      Print();
    }

    else {
      printf("Sorry! There is no such command: %s!\n", command);
    }

  }

  return 0;

}
