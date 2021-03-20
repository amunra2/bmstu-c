#include"../inc/list_work.h"


int check_empty(FILE *f)
{
    if (fseek(f, 0, SEEK_END) != OK_SEEK)
    {
        return ERR_FILE_CLEAR;
    }

    size_t current_size = ftell(f);

    if (current_size <= 0)
    {
        return ERR_FILE_CLEAR;
    }

    return fseek(f, 0, SEEK_SET);
}


int read_data(char *file_in_name, arr_t *arr)
{
    FILE *file_in = fopen(file_in_name, "r");

    if (!file_in)
    {
        return ERR_NO_FILE;
    }

    LOG_INFO("%s", "ok open");

    if (check_empty(file_in) != OK_FILE)
    {
        fclose(file_in);
        return ERR_FILE_EMPTY;
    }

    LOG_INFO("%s", "not empty");

    int i = 0, len;

    if (fscanf(file_in, "%d", &len) != OK_NUM)
    {
        fclose(file_in);
        return ERR_READ_NUM;
    }

    arr->data = calloc(len * sizeof(int), sizeof(int));

    if (!arr->data)
    {
        fclose(file_in);
        return ERR_ALLOCATE_MEMORY;
    }

    while (!feof(file_in))
    {
        if (fscanf(file_in, "%d", &arr->data[i++]) != OK_NUM)
        {
            fclose(file_in);
            return ERR_READ_NUM;
        }
    }

    arr->len = i;

    if (fclose(file_in) != NO_MISTAKES)
    {
        LOG_ERROR("Faild file close, code: %d", ERR_CLOSING_FILE);
        return ERR_CLOSING_FILE;
    }

    if (i != len)
    {
        return ERR_WRONG_AMOUNT_ELEMS;
    }

    return OK_READ;
}


node_t *create_node(void *num)
{
    node_t *tmp_elem = malloc(sizeof(node_t));

    if (!tmp_elem)
    {
        return NULL;
    }

    tmp_elem->data = num;
    tmp_elem->next = NULL;

    return tmp_elem;
}


int push_node_front(node_t **list, void *num)
{
    node_t *tmp = create_node(num);

    if (!tmp)
    {
        return ERR_ALLOCATE_MEMORY;
    }

    if (!(*list))
    {
        *list = tmp;

        LOG_INFO("%s", "list clear");

        return OK_PUSH_NODE;
    }

    tmp->next = *list;
    *list = tmp;
    
    return OK_PUSH_NODE;
}


int push_node_back(node_t **list, void *num)
{
    node_t *tmp = create_node(num);

    if (!tmp)
    {
        return ERR_ALLOCATE_MEMORY;
    }

    LOG_DEBUG("%s", "OK PUSH");

    if (!(*list))
    {
        *list = tmp;

        LOG_INFO("%s", "list clear");

        return OK_PUSH_NODE;
    }

    node_t *tmp_elem = *list;

    while (tmp_elem->next != NULL)
    {
        tmp_elem = tmp_elem->next;
    }

    tmp_elem->next = tmp;

    return OK_PUSH_NODE;
}


int fill_list(char *file_in_name, node_t **list, arr_t *arr)
{
    if (read_data(file_in_name, arr) != OK_READ)
    {
        return ERR_READ_NUM;
    }

    int count = arr->len, i = 0;

    while (count > 0)
    {
        if (push_node_back(list, &arr->data[i]) != NO_MISTAKES) // add define
        {
            return ERR_PUSH_NODE;
        }

        count--;
        i++;
    }

    return OK_LIST_CREATE;
}


int print_list(node_t *list)
{
    if (!list)
    {
        return ERR_LIST_EMPTY;
    }

    LOG_INFO("%s", "in print");

    node_t *tmp = list;

    while (tmp != NULL)
    {
        printf("%d\n", *(int*)tmp->data);
        tmp = tmp->next;
    }

    return OK_PRINT_LIST;
}


int write_file_list(char *file_out_name, node_t *list)
{
    if (!list)
    {
        return ERR_LIST_EMPTY;
    }

    FILE *file_out = fopen(file_out_name, "w");

    if (!file_out)
    {
        return ERR_NO_FILE;
    }

    node_t *tmp = list;

    while (tmp != NULL)
    {
        if (fprintf(file_out, "%d\n", *(int*)tmp->data) < OK_WRITE_NUM)
        {
            return ERR_WRITE_FILE;
        }

        tmp = tmp->next;
    }

    if (fclose(file_out) != NO_MISTAKES)
    {
        LOG_ERROR("Faild file close, code: %d", ERR_CLOSING_FILE);
        return ERR_CLOSING_FILE;
    }

    return OK_WRITE;
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


void *pop_front(node_t **head)
{
    if (!head || !(*head))
    {
        return NULL;
    }

    void *data = (*head)->data;

    node_t *tmp = *head;

    *head = (*head)->next;

    free(tmp);

    return data;
}


void *pop_back(node_t **head)
{
    if (!head || !(*head))
    {
        return NULL;
    }

    node_t *tmp = *head, *end;

    if (tmp->next == NULL)
    {
        void *data = tmp->data;
        *head = NULL;
        free(tmp);

        return data;
    }

    while (tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }

    void *data = tmp->next->data;
    
    end = tmp->next;
    tmp->next = NULL;

    free(end);
    
    return data;
}


node_t *reverse(node_t *head)
{
    if (!head)
    {
        return NULL;
    }

    node_t *new_head = NULL;

    node_t *tmp = head;

    while (tmp != NULL)
    {
        void *data = pop_front(&tmp);

        if (push_node_front(&new_head, data) != OK_PUSH_NODE)
        {
            return NULL;
        }
    }

    return new_head;
}


int comparator(const void *a, const void* b)
{
    return (*(int*)a - *(int*)b);
}


void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *))
{
    LOG_DEBUG("#### %d ###\n", *(int*)element->data);

    element->next = NULL;

    if (!(*head)) // если список пуст - вставить элемент
    {
        LOG_INFO("%s", "in 1");
        *head = element;

        return;
    }

    node_t *tmp_head = *head;

    if (comparator(tmp_head->data, element->data) > 0) // если новый элемент должен встать в начало списка
    {
        node_t *tmp_elem = (*head);

        *head = element;
        element->next = tmp_elem;

        return;
    }

    while (tmp_head->next != NULL) // если новый элемент должен встать в любом месте списка
    {
        LOG_DEBUG("@@@ %d %d @@@\n", *(int*)tmp_head->data, *(int*)element->data);

        if (comparator(tmp_head->next->data, element->data) > 0)
        {
            LOG_INFO("%s", "in comp");

            node_t *tmp_elem = tmp_head->next;

            tmp_head->next = element;
            element->next = tmp_elem;

            return;
        }

        tmp_head = tmp_head->next;
    }

    tmp_head->next = element; // если массив уже отсортирован, то просто вставить элемент
}


node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    if (!head)
    {
        return NULL;
    }

    if (!comparator)
    {
        return NULL;
    }


    node_t *new_head = NULL, *next_el;

    while (head != NULL)
    {
        next_el = head->next;
    
        sorted_insert(&new_head, head, comparator);

        head = next_el;
    }

    return new_head;
}







