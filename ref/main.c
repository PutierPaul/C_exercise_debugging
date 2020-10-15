#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct mini_list
{
    char *data;
    struct mini_list *next;
    struct mini_list *prev;
};


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: ./main <file>\n");
        return 1;
    }

    // Open user file in reading mode
    FILE *file = fopen(argv[1], "r");

    char *line = NULL;
    size_t n = 0;

    ssize_t len = getline(&line, &n, file);
    if (len == -1) {
        fprintf(stderr, "getline error\n");
        return 1;
    }

    char *token = NULL;
    char *save = NULL;
    size_t size = 0;

    struct mini_list *head = NULL;
    struct mini_list *current = NULL;

    token = strtok_r(line, " ", &save);
    while (token)
    {
        struct mini_list *new = malloc(sizeof(struct mini_list));
        if (!new) {
            // free & return
            return 1;
        }
        new->data = token;
        new->next = NULL;
        new->prev = current;

        if (!head)
        {
            head = new;
        }
        if (current)
        {
            current->next = new;
        }
        current = new;

        token = strtok_r(NULL, " ", &save);
        size++;
    }

    // Display list size
    printf("List size: %lu\n", size);


    // Print token in reverse order
    while(current)
    {
        printf("%s\n", current->data);
        current = current->prev;
    }


    free(line);
    while(head->next)
    {
        struct mini_list *tmp = head->next;
        free(head);
        head = tmp;
    }
    free(head);

    fclose(file);
    return 0;
}
