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

Character::Character() {}

Character::~Character() {
    for (int i = 0; i < Character::MAX_INVENTORY_SIZE; i++) {
        if (mInventory[i] == NULL)
            break;

        delete mInventory[i];
    }
}

Character::Character(const Character &character) {
    *this = character;
}

Character &Character::operator=(const Character &character) {
    if (this == &character)
        return *this;

    mName = character.getName();
    for (int i = 0; i < Character::MAX_INVENTORY_SIZE; i++) {
        if (mInventory[i] != NULL)
            delete mInventory[i];

        mInventory[i] = character.mInventory[i]->clone();
    }
    mMateriaCount = character.getMateriaCount();

    return *this;
}

Character::Character(const std::string &name) : mName(name), mMateriaCount(0) {
    for (int i = 0; i < Character::MAX_INVENTORY_SIZE; i++) {
        mInventory[i] = NULL;
    }
}

const std::string &Character::getName() const { return mName; }

int Character::getMateriaCount() const { return mMateriaCount; }

void Character::equip(AMateria *m) {
    if (m == NULL) {
        std::cout << "Error: Wrong Materia Input!" << std::endl;
        return;
    }

    if (mMateriaCount == Character::MAX_INVENTORY_SIZE) {
        std::cout << "Error: Character Inventory is Full!" << std::endl;
        delete m;
        return;
    }

    for (int i = 0; i < Character::MAX_INVENTORY_SIZE; i++) {
        if (mInventory[i] == NULL)
        {
            mInventory[i] = m;
            break;
        }
    }

    ++mMateriaCount;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= Character::MAX_INVENTORY_SIZE) {
        std::cout << "Error: Wrong index entered!" << std::endl;
        return;
    }

    if (mInventory[idx] == NULL) {
        std::cout << "Error: Inventory is Empty!" << std::endl;
        return;
    }

    Floor *floor = Floor::getInstance();
    floor->storeMateria(mInventory[idx]);

    mInventory[idx] = NULL;
    --mMateriaCount;
}

void Character::use(int idx, ICharacter &target) {
    if (idx < 0 || idx >= Character::MAX_INVENTORY_SIZE) {
        std::cout << "Error: Wrong index entered!" << std::endl;
        return;
    }

    if (mInventory[idx] == NULL) {
        std::cout << "Error: Inventory is Empty!" << std::endl;
        return;
    }

    mInventory[idx]->use(target);
}
