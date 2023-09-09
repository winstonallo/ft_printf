#include "libft.h"


// Define your t_list and related functions here

void ft_delete_node(void *before_del)
{
    t_list *temp;
    temp = ((t_list*)before_del)->next;
    ((t_list*)before_del)->next = temp->next;
    free(temp);
}

void *ft_do_something(void *old)
{
    int *content = (int *)((t_list *)old)->content;
    (*content)++;
    return old;
}

int main()
{
    t_list *test = NULL;

    for (int i = 0; i < 5; i++)
    {
        ft_lstadd_back(&test, ft_lstnew((void *)(&i)));
        printf("OLD LIST ---> content of node %d: %d\n", i, *((int *)test->content));
    }

    t_list *new_list = ft_lstmap(test, ft_do_something, ft_delete_node);
    t_list *temp = new_list;
    
    for (int i = 0; i < 5; i++)
    {
        printf("NEW LIST ---> content of node %d: %d\n", i, *((int *)temp->content));
        temp = temp->next;
    }

    // Clean up memory
    ft_lstclear(&test, NULL);
    ft_lstclear(&new_list, ft_delete_node);

    return (0);
}




