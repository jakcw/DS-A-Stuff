#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List new_list() {
    List temp;
    temp.head = NULL;
    return temp;
}

void print_list(List *self) {   

    ListNodePtr current = self->head;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;

        if (current != NULL) {
            printf(", ");
        }
    }
} 

void insert_front(List *self, int data) {
    ListNodePtr new_node = malloc(sizeof *new_node);
    new_node->data = data;
    new_node->next = self->head;
    self->head = new_node;
}

void insert_in_order(List *self, int data) {
    ListNodePtr current = self->head;
    ListNodePtr prev = NULL;

    ListNodePtr new_node = malloc(sizeof *new_node);
    new_node->data = data;
    new_node->next=NULL;

    while (current != NULL && current->data < data) {
        prev = current;
        current = current->next;
    }

    if (current == self->head) {
        new_node->next = current;
        self->head = new_node;
    } else {
        new_node->next = current;
        prev->next = new_node;
    }
}

void delete_from_list(List *self, int data) {
    ListNodePtr current = self->head;
    ListNodePtr prev = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (prev == NULL) {
                self->head = current->next;
                free(current);
                current = self->head;
            } else {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void destroy_list(List *self) {
    ListNodePtr current = self->head;
    while (current != NULL) {
        ListNodePtr to_free = current;
        current = current->next;
        free(to_free);
    }
    self->head = NULL;
}

// slow and simple reverse list approach
List reverse_list(List *self) {
    List reverse = new_list();
    ListNodePtr current = self->head;
    while (current != NULL) {
        insert_front(&reverse,current->data);
        current = current->next;
    }
    return reverse;
}

// slow and simple merge list approach
List merge_list(List* self, List* other) {
    List merged = new_list();
    ListNodePtr current = self->head;
    ListNodePtr current_other = other->head;

    while (current != NULL || current_other != NULL) {
        insert_in_order(&merged, current->data);
        insert_in_order(&merged, current_other->data);
        current = current->next;
        current_other = current_other->next;
    }

    return merged;
  
}