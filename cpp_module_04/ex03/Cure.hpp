/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:09:30 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/10 14:09:30 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
#define CURE_H

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
public:
    Cure();
    ~Cure();
    Cure(const Cure &cure);
    Cure &operator=(const Cure &cure);

public:
    Cure *clone() const;
    void use(ICharacter &target);

private:
    static const std::string DEFAULT_TYPE;
};

#endif
