#include"func.h"


int check_empty(FILE *f_in)
{
    if (fseek(f_in, 0, SEEK_END) != 0)
    {
        return ERR_FILE_EMPTY;
    }

    size_t size = ftell(f_in);

    if (size <= 0)
    {
        return ERR_FILE_EMPTY;
    }

    return fseek(f_in, 0, SEEK_SET);
}


node_t *create_node(char sym)
{
    node_t *tmp = malloc(sizeof(node_t));

    if (!tmp)
    {
        return NULL;
    }

    tmp->data = sym;

    tmp->next = NULL;

    return tmp;
}


int push_node_back(node_t **list, char sym)
{
    node_t *tmp = create_node(sym);

    if (!tmp)
    {
        return ERR_NODE;
    }

    if (!(*list))
    {
        *list = tmp;

        return OK_NODE;
    }

    node_t *go_to_end = *list;

    while (go_to_end->next != NULL)
    {
        go_to_end = go_to_end->next;
    }

    go_to_end->next = tmp;

    return OK_NODE;
}


int read(FILE *f_in, node_t **list)
{
    int rc = check_empty(f_in);

    if (rc != NO_MISTAKES)
    {
        return ERR_FILE_EMPTY;
    }

    char ch;

    while (fscanf(f_in, "%c", &ch) == 1)
    {
        if (ch == '\n')
        {
            ch = ' ';
        }

        LOG_DEBUG("%c", ch);

        if (push_node_back(list, ch) != OK_NODE)
        {
            return ERR_NODE;
        }
    }

    return OK;
}


void free_list(node_t *list)
{
    node_t *next;

    for (; list; list = next)
    {
        next = list->next;
        free(list);
    }
}


int print_list(node_t *list)
{
    if (!list)
    {
        return ERR_LIST_EMPTY;
    }

    node_t *tmp = list;

    while (tmp != NULL)
    {
        printf("%c\n", tmp->data);
        tmp = tmp->next;
    }

    return OK;
}


int print_list_file(FILE *f_out, node_t *list)
{
    if (!list)
    {
        return ERR_LIST_EMPTY;
    }

    node_t *tmp = list;

    while (tmp != NULL)
    {
        char sym = tmp->data;

        if (sym == ' ')
        {
            sym = '\n';
        }

        fprintf(f_out, "%c", sym);
        tmp = tmp->next;
    }

    return OK;
}



int reverse(node_t **list)
{
    if (!(*list))
    {
        return ERR_LIST_EMPTY;
    }

    node_t *tmp = *list;

    node_t *next, *prev = NULL;

    while (tmp != NULL)
    {
        next = tmp->next;
        tmp->next = prev;

        prev = tmp;
        tmp = next;
    }

    *list = prev;

    return OK;
}