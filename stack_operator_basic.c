/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operator_basic.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:54:11 by tlegrand          #+#    #+#             */
/*   Updated: 2022/12/16 15:46:01 by tlegrand         ###   ########.fr       */
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
 * @param head_src pointer to first element of source stack
 * @param head_dst ptr to first element of destination stack
 */
void	ft_push(t_stack **head_src, t_stack **head_dst)
{
	t_stack	*tmp_src;

//	printf("z\n");
	if (head_src && *head_src && (*head_src)->next)
	{
	//	printf("0\n");
		tmp_src = (*head_src)->next;
	//	printf("1\n");
		(*head_src)->next = *head_dst;
	//	printf("2\n");
		head_dst = head_src;
	//	printf("3\n");
		head_src = &tmp_src;
	}
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
