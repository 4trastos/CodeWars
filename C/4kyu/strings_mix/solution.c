#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct s_list
{
    char            type;
    char            c;
    int             count;
    struct s_list  *next;
}   t_list;

int ft_type_weight(char type)
{
    if (type == '1')
        return (1);
    if (type == '2')
        return (2);
    return (3);
}

void    ft_sort_list(t_list *node)
{
    t_list  *ptr1;
    int     swapped = 1;
    int     do_swap = 0; 
    
    if (!node)
        return;
    while (swapped)
    {
        swapped = 0;
        ptr1 = node;
        while (ptr1->next != NULL)
        {
            do_swap = 0;

            if (ptr1->count < ptr1->next->count)
                do_swap = 1;
            else if (ptr1->count == ptr1->next->count)
            {
                if (ft_type_weight(ptr1->type) > ft_type_weight(ptr1->next->type))
                    do_swap = 1;
                // 3er Criterio: Orden alfabético ascendente
                else if (ptr1->type == ptr1->next->type)
                {
                    if (ptr1->c > ptr1->next->c)
                        do_swap = 1;
                }
            }

            if (do_swap)
            {
                int t_cnt = ptr1->count;
                ptr1->count = ptr1->next->count;
                ptr1->next->count = t_cnt;

                char t_typ = ptr1->type;
                ptr1->type = ptr1->next->type;
                ptr1->next->type = t_typ;

                char t_c = ptr1->c;
                ptr1->c = ptr1->next->c;
                ptr1->next->c = t_c;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
    }
}

char    *ft_sorter(t_list **node, char *str)
{
    t_list  *aux;
    char    temp_block[512];
    int     first = 1;
    int     len = 0;

    ft_sort_list(*node);
    aux = *node;

    while (aux)
    {
        memset(temp_block, 0, 512);
        len = 0;
        
        if (!first)
            temp_block[len++] = '/';
        
        temp_block[len++] = aux->type;
        temp_block[len++] = ':';
        
        for (int j = 0; j < aux->count; j++)
            temp_block[len++] = aux->c;
        
        temp_block[len] = '\0';

        str = realloc(str, strlen(str) + strlen(temp_block) + 1);
        strcat(str, temp_block);
        
        first = 0;
        aux = aux->next;
    }
    return (str);
}

t_list  *ft_create_node(char type, char c, int count)
{
    t_list *new;

    new = malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->c = c;
    new->count = count;
    new->type = type;
    new->next = NULL;

    return (new);
}

void    ft_stack_node(t_list **node, t_list *new)
{
    t_list *aux;

    aux = *node;
    if (!aux)
    {
        *node = new;
        return;
    }

    while (aux->next != NULL)
        aux = aux->next;
    aux->next = new;
    new->next = NULL;
}


char *mix(const char *s1, const char *s2)
{
    t_list  *node = NULL;
    char    *alfabt = "abcdefghijklmnopqrstuvwxyz";
    char    *str;
    int     i, x, count_a, count_b;
    char    type;

    i = 0;
    str = malloc(1);
    if (!str)
     return(NULL);
    str[0] = '\0';

    while (alfabt[i] != '\0')
    {
        x = 0;
        count_a = 0;
        count_b = 0;
        type = '0';
        while (s1[x] != '\0')
        {
            if (s1[x] == alfabt[i])
                count_a++;
            x++;
        }
        x = 0;
        while (s2[x] != '\0')
        {
            if (s2[x] == alfabt[i])
                count_b++;
            x++;
        }
        if (count_a > 1 || count_b > 1)
        {
            if (count_a > count_b)
            {
                type = '1';
                ft_stack_node(&node, ft_create_node(type, alfabt[i], count_a));
            }
            else if (count_b > count_a)
            {
                type = '2';
                ft_stack_node(&node, ft_create_node(type, alfabt[i], count_b));
            }
            else
            {
                type = '=';
                ft_stack_node(&node, ft_create_node(type, alfabt[i], count_a));
            }
        }
        i++;
    }
    str = ft_sorter(&node, str);
	return (str);
}