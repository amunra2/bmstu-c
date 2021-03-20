#include"../inc/list_work.h"


void free_list(node_t *list)
{
    node_t *next;

    for (; list; list = next)
    {
        next = list->next;
        free(list);
    }
}


int cheack_prime(int num)
{
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return NO_PRIME;
        }
    }

    return PRIME;
}


int get_new_prime_num(int last_num)
{
    int count = 0;

    while (count++ < INT_MAX)
    {
        LOG_DEBUG("%d", last_num);
        if (cheack_prime(++last_num))
        {
            return last_num;
        }
    }

    return last_num;
}


node_t *create_node(int num)
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


int push_node_back(node_t **list, int num)
{
    node_t *tmp = create_node(num);

    if (!tmp)
    {
        return ERR_ALLOCATE_MEMORY;
    }

    if (!(*list))
    {
        *list = tmp;

        return OK_PUSH_NODE;
    }

    node_t *tmp_head = *list;

    while (tmp_head->next != NULL)
    {
        tmp_head = tmp_head->next;
    }

    tmp_head->next = tmp;

    return OK_PUSH_NODE;
}


int pop_front(node_t **list, int *data)
{
    if (!list || !(*list))
    {
        return ERR_LIST_EMPTY;
    }

    *data = (*list)->data;

    node_t *tmp = *list;
    *list = (*list)->next;

    free(tmp);

    return OK_POP;
}


int translate_num(node_t **list, int num)
{
    if (num < 2)
    {
        return ERR_IMP_TRANSALATE;
    }

    int last_num = 1;
    int power = 0;

    while (num != 1)
    {
        last_num = get_new_prime_num(last_num);

        if (last_num == INT_MAX)
        {
            return ERR_NO_PRIME_NUMS_LEFT_IN_INT;
        }

        LOG_DEBUG("%d", last_num);

        while (num % last_num == 0)
        {
            num /= last_num;
            LOG_DEBUG("%d", num);
            power++;
        }

        if (push_node_back(list, power) != NO_MISTAKES)
        {
            return ERR_PUSH_NODE;
        }

        power = 0;
    }

    return OK_TRANSLATE;
}


int print_num(void)
{
    int num;

    int rc = scanf("%d", &num);

    if (rc != OK_READ_NUM)
    {
        return ERR_WRONG_NUM;
    }

    node_t *list = NULL;

    if (translate_num(&list, num) != NO_MISTAKES)
    {
        return ERR_TRANSLATE_NUM;
    }

    print_list(list);

    free_list(list);

    return OK_PRINT_NUM;
}


int multiply(node_t *list_a, node_t *list_b)
{
    int rc = NO_MISTAKES;

    if (!list_a || !list_b)
    {
        return ERR_LIST_EMPTY;
    }
    
    node_t *tmp_b = list_b, *tmp_a = list_a;

    while (tmp_b != NULL)
    {
        if (tmp_a)
        {
            tmp_a->data += tmp_b->data;
            tmp_a = tmp_a->next;
        }
        else
        {
            LOG_INFO("%s", "here in push");

            rc = push_node_back(&list_a, tmp_b->data);

            if (rc != NO_MISTAKES)
            {
                return rc;
            }
        }

        tmp_b = tmp_b->next;
    }

    return OK_MULTI;
}


int mult_nums(void)
{
    int num_a, num_b;

    int rc = scanf("%d", &num_a);

    if (rc != OK_READ_NUM)
    {
        return ERR_WRONG_NUM;
    }

    rc = scanf("%d", &num_b);

    if (rc != OK_READ_NUM)
    {
        return ERR_WRONG_NUM;
    }

    LOG_DEBUG("%d %d", num_a, num_b);

    node_t *list_a = NULL;
    if (translate_num(&list_a, num_a) != NO_MISTAKES)
    {
        return ERR_TRANSLATE_NUM;
    }

    node_t *list_b = NULL;
    if (translate_num(&list_b, num_b) != NO_MISTAKES)
    {
        free_list(list_a);
        return ERR_TRANSLATE_NUM;
    }

    rc = multiply(list_a, list_b);

    if (rc != NO_MISTAKES)
    {
        free_list(list_a);
        free_list(list_b);
        return rc;
    }

    print_list(list_a);

    free_list(list_a);
    free_list(list_b);

    return OK_MULTI;
}


int division(node_t **res, int a, int b)
{
    if (b == 0)
    {
        return ERR_ZERO_DIVISION;
    }

    int res_num = 0;

    if (a % b == 0)
    {
        res_num = a / b;
    }
    else
    {
        return ERR_DIVISION;
    }

    if (translate_num(res, res_num) != NO_MISTAKES)
    {
        return ERR_TRANSLATE_NUM;
    }            

    return OK_DIV;
}


int div_nums(void)
{
    int num_a, num_b;

    int rc = scanf("%d", &num_a);

    if (rc != OK_READ_NUM)
    {
        return ERR_WRONG_NUM;
    }

    rc = scanf("%d", &num_b);

    if (rc != OK_READ_NUM)
    {
        return ERR_WRONG_NUM;
    }

    LOG_DEBUG("%d %d", num_a, num_b);    

    node_t *res = NULL;
    rc = division(&res, num_a, num_b);

    if (rc != NO_MISTAKES)
    {
        return rc;
    }

    print_list(res);

    free_list(res);

    return OK_DIV;
}


int square_num(void)
{
    int num;

    int rc = scanf("%d", &num);

    if (rc != OK_READ_NUM)
    {
        return ERR_WRONG_NUM;
    }

    node_t *list = NULL;

    if (translate_num(&list, num) != NO_MISTAKES)
    {
        return ERR_TRANSLATE_NUM;
    }

    rc = multiply(list, list);

    if (rc != NO_MISTAKES)
    {
        free_list(list);
        return rc;
    }

    print_list(list);

    free_list(list);

    return OK_SQUARE;    
}