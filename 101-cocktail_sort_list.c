#include "sort.h"

/**
 * swap_node_ahead - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
    listint_t *tmp = (*shaker)->next;

    if ((*shaker)->prev != NULL)
        (*shaker)->prev->next = tmp;
    else
        *list = tmp;
    if (tmp != NULL)
        tmp->prev = (*shaker)->prev;
    else
        *tail = (*shaker)->prev;
    (*shaker)->next = tmp ? tmp->next : NULL;
    if (tmp && tmp->next != NULL)
        tmp->next->prev = *shaker;
    (*shaker)->prev = tmp;
    if (tmp != NULL)
        tmp->next = *shaker;
    *shaker = tmp ? tmp : *shaker;
}

/**
 * swap_node_behind - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
    listint_t *tmp = (*shaker)->prev;

    if ((*shaker)->next != NULL)
        (*shaker)->next->prev = tmp;
    else
        *tail = tmp;
    tmp->next = (*shaker)->next;
    if (tmp->prev != NULL)
        tmp->prev->next = *shaker;
    else
        *list = *shaker;
    (*shaker)->prev = tmp->prev;
    (*shaker)->next = tmp;
    tmp->prev = *shaker;
    *shaker = tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *tail, *shaker;
    bool shaken_not_stirred = false;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    for (tail = *list; tail->next != NULL; tail = tail->next)
        ;

    while (!shaken_not_stirred)
    {
        shaken_not_stirred = true;
        for (shaker = *list; shaker != tail; shaker = shaker->next)
        {
            if (shaker->n > shaker->next->n)
            {
                swap_node_ahead(list, &tail, &shaker);
                print_list((const listint_t *)*list);
                shaken_not_stirred = false;
            }
        }
        for (shaker = tail; shaker != *list; shaker = shaker->prev)
        {
            if (shaker->n < shaker->prev->n)
            {
                swap_node_behind(list, &tail, &shaker);
                print_list((const listint_t *)*list);
                shaken_not_stirred = false;
            }
        }
    }
}
