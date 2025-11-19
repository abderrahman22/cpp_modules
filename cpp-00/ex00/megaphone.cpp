/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 00:53:15 by abchaman          #+#    #+#             */
/*   Updated: 2025/11/19 01:44:25 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    if (ac > 1)
    {
        std::string line;
        int i = 0;
        int j;
        while (i < ac && av[i + 1] != NULL)
        {
            line = av[i + 1];
            j = 0;
            while (line[j])
            {
                if (line[j] >= 'a' && line[j] <= 'z')
                    line[j] -= 32;
                j++;
            }
            std::cout << line;
            if (av[i + 2] != NULL)
                std::cout << " ";
            i++;
        }
        std::cout << std::endl; 
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl; 
}