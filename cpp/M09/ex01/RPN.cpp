/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:42:15 by tlegrand          #+#    #+#             */
/*   Updated: 2024/06/04 13:12:49 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int do_op(int n1, int n2, char op)
{
    switch (op)
    {
        case '+' : return (n1 + n2);
        case '-' : return (n1 - n2);
        case '*' : return (n1 * n2);
        case '/' : 
            if (n2 == 0)
                throw std::runtime_error("division by zero");
            return (n1 / n2);
        default : throw std::runtime_error("unknown character");
    }
}

bool is_op(char c)
{
    switch (c)
    {
        case '+' : return true;
        case '-' : return true;
        case '*' : return true;
        case '/' : return true;
        default : throw std::runtime_error("unknown character");
    }
}

int compute(std::string input)
{
    std::stack<int>     stack;
    std::stringstream   stream(input);
    while (stream)
    {
        char tmp = 0;
        stream >> tmp;
        if (tmp == 0)
            break ;
        if (std::isdigit(tmp))
            stack.push(tmp - 48);
        else if (is_op(tmp))
        {
            if (stack.size() < 2)
                throw std::runtime_error("not enough number");
            int n1 = stack.top();
            stack.pop();
            int n2 = stack.top();
            stack.pop();
            int res = do_op(n2, n1, tmp);
            stack.push(res);
        }
    }
    int res = stack.top();
    stack.pop();
    if (stack.empty() == false)
        throw std::runtime_error("not enough operator");
    return (res);
}
