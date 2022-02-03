#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: pointer to the head of a list
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
    listint_t *slow_hd, *fast_hd;

    /* condition when the list is empty or
        have to a one element (isn't a cycle)*/
    if (list == NULL || list->next == NULL)
        return (0);

    /* slow, moves forwar one node and
       fast jumps forward two nodes */
    slow_hd = list->next;
    fast_hd = list->next->next;

    while (slow_hd && fast_hd && fast_hd->next)
    {
        /* both pointers point to the same node */
        if (slow_hd == fast_hd->next)
            return (1);
        slow_hd = slow_hd->next;
        fast_hd = fast_hd->next->next;
    }
    return (0);
}
