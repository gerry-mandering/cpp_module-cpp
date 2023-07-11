/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:09:30 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/10 14:09:30 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MATERIA_H
#define A_MATERIA_H

#include <iostream>

class ICharacter;

class AMateria {
public:
    AMateria();
    virtual ~AMateria();
    AMateria(const AMateria &materia);
    AMateria &operator=(const AMateria &materia);

public:
    AMateria(std::string const &type);

public:
    const std::string &getType() const;

public:
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);

protected:
    std::string mType;
};

#endif