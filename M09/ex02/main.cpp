/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:02:24 by tlegrand          #+#    #+#             */
/*   Updated: 2024/05/30 22:17:27 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char** arg)
{
    if (ac == 1)
    {
        std::cerr << "Error: no number provided" << std::endl;
        return (1);
    }

    std::vector<int>    v_input;
    std::deque<int>     d_input;
    std::vector<int>    v_sorted;
    std::deque<int>     d_sorted;

    PmergeMe    m(false);
    
    for (int i = 1; i < ac; ++i)
    {
        v_input.push_back(std::atoi(arg[i]));
        d_input.push_back(std::atoi(arg[i]));
        
    }

    std::cout << "Raw: (size: " << v_input.size() << ") ";
    printContainer(v_input);

    double v_time = m.timer(v_input, v_sorted);
    double d_time = m.timer(d_input, d_sorted);
    
    std::cout << "Container: vector" << std::endl;
    validate(v_input, v_sorted);
    std::cout << std::fixed << std::setprecision(2) << "Time: " << v_time << "us" << std::endl;
    std::cout << "Sorted: (size: " << v_sorted.size() << ") ";
    printContainer(v_sorted);


    std::cout << "Container: deque" << std::endl;
    validate(d_input, d_sorted);
    std::cout << std::fixed << std::setprecision(2) << "Time: " << d_time << "us" << std::endl;
    std::cout << "Sorted: (size: " << d_sorted.size() << ") ";
    printContainer(d_sorted);

    return (0);
}

// 49 19 87 10 6 50 62 81 42 56 53 28 13 4 45 68 73 9 75 94 85 64 34 67 72 89 25 17 33 3
// X [all]
// S1 [X/2]
// S2 [S1/2]
// S3 [S2/2]
// sorted []

// depth1
// list      [ 6 7 8 5 3 1 2 4]
// pair    [(6 7) (8 5) (3 1) (2 4)]
// sort    [(6 7) (5 8) (1 3) (2 4)]
// extract  [ 7     8     3     4]

// rec until one pair
// depth2
// list      [7  8  3  4]
// pair     [(7 8) (3 4)]
// sort      [(7 8) (3 4)]
// extract    [ 8      4]

// depth3
// list       [8   4]
// pair     [(8 4)] 
// sort      [(4 8)] 
// extract   --> one pair stop rec 

// depth 2 
// sorted        [4 8]
// uppairs      [(7 8) (3 4)]
// sort uppair  [(3 4) (7 8)]  (based on sorted (for each eleemtn in))
// in jetc min  ->
        // sorted  [3 4  / 8]
        // list [(3 4) (7 8) ]
        // list w/out sorted : [7 ]
        // inject list with bin search 

// depth 1  


/*
0 0 1 2 3 4 5 
0 1 2 4 8 16 32
   
U(n) = U(n-1) + U(n-2) * 2

n    u
n0    0
n1   2
n2   n1 + n0 * 2 = 2 + 0 * 2 = 2
n3   n2 + n1 * 2 = 2 + 2 * 2 = 6
n4   n3 + n2 * 2 = 6 + 2 * 2 = 10
n5   n4 + n3 * 2 = 10 + 6 * 2 = 22
n6   ...


*/

/*
bin search :
sorted : [ 3 4 8]
input: [(3 4) 7 (8)]

[ (5 8 )(9 5) (1 2 5 8 4 7) 4 ]
2 2 6


*/