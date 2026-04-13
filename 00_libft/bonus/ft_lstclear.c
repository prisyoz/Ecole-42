#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*curr;
	t_list	*ptr;

	curr = *lst;
	if (!lst || !*lst)
		return ;
	while (curr != NULL)
	{
		ptr = curr->next;
		del(curr->content);
		free(curr);
		curr = ptr;
	}
	*lst = NULL;
}
