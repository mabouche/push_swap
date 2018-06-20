/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 13:57:19 by mabouche          #+#    #+#             */
/*   Updated: 2018/06/19 13:57:19 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Fonction utilitaire pour print la liste
*/

void traverse_print(t_elem* head)
{
    t_elem* cursor;
    cursor = head;
    while(cursor != NULL)
    {
        printf("[%d]", cursor->value);
        cursor = cursor->next;
    }
}

/*
** Creation element
*/

t_elem *create_elem(int data, t_elem *next)
{
    t_elem* new_list = (t_elem*)malloc(sizeof(t_elem));
    if(new_list == NULL)
        return(NULL);
    new_list->value = data;
    new_list->next = next;

    return (new_list);
}

/*
** Lie element en fin de liste
*/

t_elem *append_elem(t_elem *start, int data)
{
    t_elem *cursor;
    t_elem *new;
    if(start == NULL)
        return(NULL);

    cursor = start;
    while(cursor->next != NULL)
        cursor = cursor->next;
    new = (create_elem(data, NULL));
    cursor->next = new;
    return(start);
}

/*
** Initie pile b
*/
t_pile *init_pile_b()
{
    t_pile *start;
    start = (t_pile*)malloc(sizeof(t_list));
    start->first = NULL;
    start->last = NULL;
    start->count = 0;
    return(start);
}

/*
** Parsing argument to chained list
*/

t_elem *init_pile_a(int ac, char **av)
{
    int i;
    i = 1;
    t_elem *start;
    start = create_elem(ft_atoi(av[i]), NULL);
    i++;
    while(i < ac)
    {
        start = append_elem(start, ft_atoi(av[i]));
        i++;
    }
    return(start);
}

/*
** Lie Structure liste avec element (debut, fin, taille)
*/

t_pile *init(t_elem *start)
{
    t_pile *pile;
    t_elem *cursor;
    int i;

    i  = 1;
    pile->first = start;

    cursor = start;
    while(cursor->next != NULL)
    {
        i++;
        cursor = cursor->next;
    }
    pile->last = cursor;
    pile->count = i;
    return(pile);
}
/*
** check if input OK
*/
int ft_error(int ac, char **av)
{
    int i;

    i = 1;
    if(ac <= 1)
        return(1);
    while(i < ac)
    {
        if(ft_atoi(av[i]) == -1981284353 && ft_strcmp(av[i], "-1981284353"))
            return(1);
        if(ft_atoi(av[i]) == 1981284353 && ft_strcmp(av[i], "1981284353"))
            return(1);
        if(ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
            return(1);
        if(ft_atoi(av[i]) == 0 && ft_strcmp("0", av[i]))
            return(1);
        i++;
    }
    return(0);

}

int main(int ac, char **av)
{
    t_elem *start_a;
    t_elem *start_b;
    t_pile *pile_a;
    t_pile *pile_b;
    int size;
    if(ft_error(ac, av))
    {
        printf("error\n");
        return(0);
    }
    else
        start_a = init_pile_a(ac, av);
    pile_a = init(start_a);
    free(start_a);
    pile_b = init_pile_b();
    traverse_print(pile_a->first);
    traverse_print(pile_b->first);
    printf("\n");
    swap_a(pile_a, pile_b);
    push_b(pile_a, pile_b);
    push_b(pile_a, pile_b);
    push_b(pile_a, pile_b);
    rotate_rr(pile_a, pile_b);
    r_rotate_rr(pile_a, pile_b);
    swap_a(pile_a, pile_b);
    push_a(pile_a, pile_b);
    push_a(pile_a, pile_b);
    push_a(pile_a, pile_b);
   // size = pile_a->count;
    //quicksort(pile_a, pile_b, size);
    traverse_print(pile_a->first);
    printf("\n");
    traverse_print(pile_b->first);

}
