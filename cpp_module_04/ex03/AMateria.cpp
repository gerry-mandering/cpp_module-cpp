/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:09:30 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/10 14:09:30 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria &aMateria) {
    *this = aMateria;
}

AMateria &AMateria::operator=(const AMateria &aMateria) {
    if (this != &aMateria)
        return *this;

    return *this;
}

AMateria::AMateria(const std::string &type) {
    mType = type;
}

const std::string &AMateria::getType() const {
    return mType;
}

void AMateria::use(ICharacter &target) {
    //FIX!!!!!!!!







    (void)target;
}
