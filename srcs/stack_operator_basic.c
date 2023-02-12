/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operator_basic.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:54:11 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/12 19:43:29 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief function swapping the two first element of a stack
 * 
 * @param start ptr to first element of stack
 */
void	ft_swap(t_stack **start)
{
	t_stack	*remain;
	t_stack	*tmp;
	t_stack	*head;

	head = *start;
	if (!head || !(head->next))
		return ;
	remain = head->next->next;
	tmp = head;
	head = head->next;
	head->next = tmp;
	head->next->next = remain;
	*start = head;
}

/**
 * @brief function pushing first element of a stack at top of a second stack
 * 
 * @param start_src pointer to first element of source stack
 * @param start_dst ptr to first element of destination stack
 */
void	ft_push(t_stack **start_src, t_stack **start_dst)
{
	t_stack	*tmp;
	t_stack	*src;
	t_stack	*dst;
	int		wit;

	if (!start_src)
		return ;
	wit = 0;
	if (((*start_src)->next) == NULL)
		wit = 1;
	src = *start_src;
	dst = *start_dst;
	tmp = src->next;
	src->next = dst;
	dst = src;
	src = tmp;
	*start_dst = dst;
	if (wit == 1)
		*start_src = NULL;
	else
		*start_src = src;
}

/**
 * @brief shift up all element by one 
 * head becomes last 
 * end stack integrety preserved
 * 
 * @param start ptr to top of stack
 */
void	ft_rotate(t_stack **start)
{
	t_stack	*tmp;
	t_stack	*head;

	if (!start || !*start)
		return ;
	head = *start;
	tmp = head->next;
	ft_stacklast(head)->next = head;
	head->next = NULL;
	head = tmp;
	*start = head;
}

/**
 * @brief shift down all element by one by changing ptr
 * last becomme head
 * end stack integrety preserved 
 * 
 * @param start 
 */
void	ft_rotate_reverse(t_stack **start)
{
	t_stack	*tmp;
	t_stack	*head;

	if (!start)
		return ;
	head = *start;
	tmp = ft_stack_penultimate(head);
	tmp->next->next = head;
	head = tmp->next;
	tmp->next = NULL;
	*start = head;
}
