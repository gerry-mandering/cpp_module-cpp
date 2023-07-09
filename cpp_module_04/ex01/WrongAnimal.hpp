/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:24:22 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/03 13:24:22 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_H
#define WRONG_ANIMAL_H

#include <iostream>

class WrongAnimal {
public:
    WrongAnimal();
    ~WrongAnimal();
    WrongAnimal(const WrongAnimal &wrongAnimal);
    WrongAnimal &operator=(const WrongAnimal &wrongAnimal);

public:
    const std::string &getType() const;

public:
    void makeSound() const;

protected:
    std::string type;

private:
    static const std::string DEFAULT_TYPE;
};

#endif