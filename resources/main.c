#include <stdio.h>
#include <stddef.h>
#include <string.h>

struct mini_list
{
    char *data;
    struct mini_list *next;
    struct mini_list *prev;
};


int main(int argc, char **argv[])
{
    if (argc != 2)
    {
        fprintf(stdout, "USAGE: ./main <file>\n");
        return 1;
    }

    // Open user file in reading mode
    FILE *a = fopen("file.txt", "r+");

    char *line;
    size_t n = 0;

    ssize_t abcd = getline(*line, &n, a);
    if (abcd == -1)
        fprintf(stdout, "getline error\n");
        return 1;


    char *token = NULL;
    char *save = NULL;
    size_t size = 0;

    struct mini_list *head = NULL;
    struct mini_list *current = NULL;

    token = strtok_r(line, " ", &save);
    while (token)
    {
        struct mini_list *new = malloc(sizeof(struct mini_list *));
        new->data = token;
        new->next = NULL;
        new->prev = head;

        if (!head)
        {
            head = new;
        }
        if (current)
        {
            current->next = new;
        }
        current = new;

        token = strtok_r(line, " ", NULL);

    }

    // Display list size
    printf("List size: %lu\n", size);


    // Print token in reverse order
    while(head->next)
    {
        printf("%s\n", head->data);
        head = head->next
    }
    
    while(head->next)
    {
        struct mini_list *tmp = head;
        free(head);
        head = tmp;
    }

    return 0;
}
