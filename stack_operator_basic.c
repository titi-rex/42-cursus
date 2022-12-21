/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operator_basic.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:54:11 by tlegrand          #+#    #+#             */
/*   Updated: 2022/12/21 15:33:03 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief function swapping the two first element of a stack
 * 
 * @param head first element of stack
 */
void	ft_swap(t_stack *head)
{
	t_stack	*tmp;

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
 * @param start_src pointer to first element of source stack
 * @param start_dst ptr to first element of destination stack
 */
void	ft_push(t_stack **start_src, t_stack **start_dst)
{
	t_stack	*tmp_next;
	t_stack	*tmp_src;
	t_stack	*tmp_dst;

	tmp_src = *start_src;
	tmp_dst = *start_dst;
	if (!tmp_src)
		return ;
	tmp_next = tmp_src->next;
	tmp_src->next = tmp_dst;
	tmp_dst = tmp_src;
	tmp_src = tmp_next;
	*start_src = tmp_src;
	*start_dst = tmp_dst;
}

/**
 * @brief shift up all element by one 
 * head becomes last 
 * end stack integrety preserved
 * 
 * @param head ptr to top of stack
 */
void	ft_rotate(t_stack **head)
{
	t_stack	*tmp;

	if (!head)
		return ;
	tmp = (*head)->next;
	(*head)->next = NULL;
	ft_stacklast(*head)->next = *head;
	head = &tmp;
	ft_print_stack(*head);
}

/**
 * @brief shift down all element by one by changing ptr
 * last becomme head
 * end stack integrety preserved 
 * 
 * @param head 
 */
void	ft_rotate_reverse(t_stack **head)
{
	t_stack	*tmp;

	if (!head)
		return ;
	tmp = ft_stack_penultimate(*head);
	tmp->next->next = *head;
	head = &(tmp->next->next);
	tmp->next = NULL;
}
