#define _CRT_SECURE_NO_WARNINGS // so scanf can be used
#include <stdio.h>
#include "bst.h"
#include "list.h"


void option_insert(List* self) {
    int value; // value to be inserted

    printf("Enter a value: ");
    scanf("%d", &value);

    insert_front(self, value);
}


void option_delete(List* self) {
    int value; // value to delete

    printf("Enter a value: ");
    scanf("%d", &value);

    delete_from_list(self, value);
}


void option_print(List* self) {
    print_list(self);
    printf("\n");
}

void option_reverse(List* self) {
    *self = reverse_list(self);
}




int main(void) {

    List my_list = new_list();

    
    /*  code for testing merge
    List merge = new_list();
    List merge_two = new_list();
    insert_front(&merge, 3);
    insert_front(&merge, 8);
    insert_front(&merge, 2);
    insert_front(&merge_two, 1);
    insert_front(&merge_two, 20);
    insert_front(&merge_two, 9);
    List merged = merge_list(&merge, &merge_two);
    */

    // value used to exit program
    int quit = 0;

    while (!quit) {

        int option;

        printf("Options \n\n");
        printf("0. Exit program\n");
        printf("1. Insert value to front of list\n");
        printf("2. Delete value from list\n");
        printf("3. Print list\n");
        printf("4. Reverse list\n");
        // printf("5. Merge two lists\n");
        scanf("%d", &option);
        printf("\n");

        if (option == 0) {
            quit = 1;
        }
        else if (option == 1) {
            option_insert(&my_list);
            printf("\n");
        }
        else if (option == 2) {
            option_delete(&my_list);
            printf("\n");
        }
        else if (option == 3) {
            option_print(&my_list);
           
        }
        else if (option == 4) {
            option_reverse(&my_list);
            printf("\n");
        }
        /*
        else if (option == 5) {
            print_list(&merged);
            printf("\n");
        }
        */
        else {
            printf("Enter a valid option\n");
        }

    }

}

/* main function for BST tests

int main(void) {
    BST tree = new_bst();
    int quit = 0;
    int data;

    while (quit == 0) {
        printf("Enter some data: ");
        scanf("%d", &data);
        if (data != 0) {
            insert_bst(&tree, data);
        }
        else {
            quit = 1;
        }
    }

    print_pre_order_bst(&tree);
    printf("\n");
    print_in_order_bst(&tree);
    printf("\n");
    print_post_order_bst(&tree);
    printf("\n");
    printf("%d", bst_height(&tree));
    printf("\n);
}
*/