/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:25:03 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/03 13:25:03 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void) {

    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    delete dog;//should not create a leak
    delete cat;

    Cat a;
    {
        Cat b = a;
    }

    return 0;
}