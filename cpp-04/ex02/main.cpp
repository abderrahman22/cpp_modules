	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaman <abchaman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:53:20 by abchaman          #+#    #+#             */
/*   Updated: 2026/01/14 16:06:37 by abchaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const int num_animals = 4;
	Animal* animals[num_animals];

	for (int i = 0; i < num_animals; i++)
	{
		if (i < num_animals / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "\nCleaning up array..." << std::endl;
	for (int i = 0; i < num_animals; i++)
	{
		delete animals[i];
	}

	Dog* jack = new Dog();
	jack->getBrain()->setIdea(0, "I love bones");
	std::cout << jack->getBrain()->getIdea(0) << std::endl;
	Dog* copy_of_jack = new Dog(*jack);

	std::cout << "Address of jack's brain: " << jack->getBrain() << std::endl;
	std::cout << "Address of copy_of_jack's brain:  " << copy_of_jack->getBrain() << std::endl;

	if (jack->getBrain() != copy_of_jack->getBrain())
	{
		std::cout << "SUCCESS: Brains have different addresses! (Deep Copy)" << std::endl;
	}
	else
	{
		std::cout << "FAILURE: Brains share the same address! (Shallow Copy)" << std::endl;
	}

	delete jack;
	delete copy_of_jack;

	std::cout << "\n--- TEST 3: Assignment Operator ---" << std::endl;
	Dog a;
	Dog b;
	b = a;
	a = a;

	std::cout << "\n--- END OF TESTS ---" << std::endl;


	return 0;
}
