/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:09:30 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/10 14:09:30 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

//private?
Character::Character() {}

Character::~Character() {}

Character::Character(const Character &character) {
    *this = character;
}

Character &Character::operator=(const Character &character) {
    if (this == &character)
        return *this;

    mName = character.getName();
    for (int i = 0; i < Character::MAX_INVENTORY_SIZE; i++) {
        if (character.mInventory[i] == NULL)
            break;

        mInventory[i] = character.mInventory[i]->clone();
    }
    mMateriaCount = character.mMateriaCount;

    return *this;
}

Character::Character(const std::string &name) : mName(name) {
    for (int i = 0; i < Character::MAX_INVENTORY_SIZE; i++) {
        mInventory[i] = NULL;
    }

    mMateriaCount = 0;
}

const std::string &Character::getName() const { return mName; }

void Character::equip(AMateria *m) {
    if (m == NULL)
        return;

    if (mMateriaCount == Character::MAX_INVENTORY_SIZE) {
        delete m;
        return;
    }

    mInventory[mMateriaCount - 1] = m;
    mMateriaCount++;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= Character::MAX_INVENTORY_SIZE)
        return;

    if (mInventory[idx] == NULL)
        return;

    Floor *floor = Floor::getInstance();
    floor->storeMateria(mInventory[idx]);

    for (int i = idx; i < Character::MAX_INVENTORY_SIZE - 1; i++) {
        mInventory[i] = mInventory[i + 1];
    }
    mInventory[Character::MAX_INVENTORY_SIZE - 1] = NULL;
}

void Character::use(int idx, ICharacter &target) {
    if (idx < 0 || idx >= Character::MAX_INVENTORY_SIZE)
        return;

    if (mInventory[idx] == NULL)
        return;

    mInventory[idx]->use(target);
}
