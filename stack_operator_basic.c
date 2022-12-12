/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operator_basic.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:54:11 by tlegrand          #+#    #+#             */
/*   Updated: 2022/12/12 19:38:49 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief function swapping the two first element of a stack
 * 
 * @param head first element of stack
 */
void	ft_swap(t_list *head)
{
	t_list	*tmp;

	if (head->next && head->next->next)
	{
		tmp = head->next->next;
		head->next->next = head;
		head->next = tmp;
	}
}

/**
 * @brief function pushing first element of a stack at top of a second stack
 * 
 * @param head_src pointer to first element of source stack
 * @param head_dst top of destination stack
 */
void	ft_push(t_list **head_src, t_list *head_dst)
{
	t_list	*tmp;

	if (head_src && *head_src && (*head_src)->next)
	{
		tmp = (*head_src)->next;
		(*head_src)->next = head_dst;
		head_src = &tmp;
	}
}

/**
 * @brief shift up all element by one 
 * head becomes last 
 * end stack integrety preserved
 * 
 * @param head ptr to top of stack
 */
void	ft_rotate(t_list **head)
{
	t_list	*tmp;

	if (!head)
		return ;
	tmp = (*head)->next;
	(*head)->next = NULL;
	ft_lstlast(*head)->next = *head;
	head = &tmp;
}

/**
 * @brief simple function searching penultimate element
 * 
 * @param lst 
 * @return t_list* ptr to penutimate element
 */
t_list	*ft_lst_penultimate(t_list *lst)
{
	if (lst && lst->next)
	{
		while (lst->next->next)
			lst = lst->next;
	}
	return (lst);
}

/**
 * @brief shift down all element by one by changing ptr
 * last becomme head
 * end stack integrety preserved 
 * 
 * @param head 
 */
void	ft_rotate_reverse(t_list **head)
{
	t_list	*tmp;

	if (!head)
		return ;
	tmp = ft_lst_penultimate(*head);
	tmp->next->next = *head;
	head = &(tmp->next->next);
	tmp->next = NULL;
}
