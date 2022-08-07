#pragma once

typedef struct listNode {
    int data;
    struct listNode *next;
} *ListNodePtr;


typedef struct list {
    ListNodePtr head;
} List;

List new_list();

void print_list(List *self);

void insert_front(List *self, int data);

void insert_in_order(List *self, int data);

void delete_from_list(List *self, int data);

void destroy_list(List *self);

List reverse_list(List *self);

List merge_list(List *self, List *other);


