/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:09:30 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/10 14:09:30 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Floor.hpp"

class Character : public ICharacter {
public:
    ~Character();
    Character(const Character &character);
    Character &operator=(const Character &character);

public:
    Character(const std::string &name);

public:
    const std::string &getName() const;
    int getMateriaCount() const;

public:
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);

private:
    static const int MAX_INVENTORY_SIZE = 4;

private:
    std::string mName;
    AMateria *mInventory[Character::MAX_INVENTORY_SIZE];

private:
    int mMateriaCount;

private:
    Character();
};

#endif