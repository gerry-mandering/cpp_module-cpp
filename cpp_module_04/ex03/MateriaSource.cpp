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
        delete mSourceInventory[i];
    }
}

//고쳐!!!!!!!!!!!!!!!!!
MateriaSource::MateriaSource(const MateriaSource &materiaSource) {
    (void)materiaSource;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource) {
    (void)materiaSource;
    return *this;
}

void MateriaSource::learnMateria(AMateria *materia) {
    if (materia == NULL)
        return;

    if (mMateriaCount == MateriaSource::MAX_SOURCE_INVENTORY_COUNT) {
        delete materia;
        return;
    }

    mSourceInventory[mMateriaCount] = materia;
    mMateriaCount++;
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
