/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:09:30 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/10 14:09:30 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < MateriaSource::MAX_SOURCE_INVENTORY_COUNT; i++) {
        mSourceInventory[i] = NULL;
    }

    mMateriaCount = 0;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < MateriaSource::MAX_SOURCE_INVENTORY_COUNT; i++) {
        if (mSourceInventory[i] == NULL)
            break;

        delete mSourceInventory[i];
    }
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource) {
    *this = materiaSource;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource) {
    if (this == &materiaSource)
        return *this;

    for (int i = 0; i < MateriaSource::MAX_SOURCE_INVENTORY_COUNT; i++) {
        if (mSourceInventory[i] != NULL)
            delete mSourceInventory[i];

        mSourceInventory[i] = materiaSource.mSourceInventory[i]->clone();
    }
    mMateriaCount = materiaSource.getMateriaCount();

    return *this;
}

void MateriaSource::learnMateria(AMateria *materia) {
    if (materia == NULL) {
        std::cout << "Error: Wrong Materia Input!" << std::endl;
        return;
    }

    if (mMateriaCount == MateriaSource::MAX_SOURCE_INVENTORY_COUNT) {
        std::cout << "Error: Source Inventory is Full!" << std::endl;
        delete materia;
        return;
    }

    mSourceInventory[mMateriaCount] = materia;
    ++mMateriaCount;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
    for (int i = 0; i < MateriaSource::MAX_SOURCE_INVENTORY_COUNT; i++) {
        if (mSourceInventory[i] == NULL)
            break;

        if (mSourceInventory[i]->getType() == type) {
            return mSourceInventory[i]->clone();
        }
    }

    return 0;
}

int MateriaSource::getMateriaCount() const { return mMateriaCount; }
