/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:25:03 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/03 13:25:03 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << PUR "Brain Constructor called" NC << std::endl;

    for (int i = 0; i < Brain::NUMBER_OF_IDEAS; i++) {
        std::stringstream stream;

        stream << "idea" << (i + 1);
        ideas[i] = stream.str();
    }
}

Brain::~Brain() {
    std::cout << PUR "Brain Destructor called" NC << std::endl;
}

Brain::Brain(const Brain &brain) {
    *this = brain;
}

Brain &Brain::operator=(const Brain &brain) {
    if (this == &brain)
        return *this;

    for (int i = 0; i < Brain::NUMBER_OF_IDEAS; i++) {
        ideas[i] = brain.ideas[i];
    }

    return *this;
}