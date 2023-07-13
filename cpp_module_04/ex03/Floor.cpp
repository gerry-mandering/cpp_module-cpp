/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:09:30 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/10 14:09:30 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"

Floor *Floor::mFloorInstancePtr = NULL;
AMateria* Floor::mStoredMaterias[Floor::MAX_STORE_SIZE];
int Floor::mStoredMateriaCount = 0;

Floor::Floor() {}

Floor::~Floor() {}

Floor::Floor(const Floor &floor) {
    (void)floor;
}

Floor &Floor::operator=(const Floor &floor) {
    (void)floor;
    return *this;
}

Floor *Floor::getInstance() {
    if (mFloorInstancePtr == NULL) {
        mFloorInstancePtr = new Floor();
        std::atexit(Floor::clearInstance);
    }

    return mFloorInstancePtr;
}

void Floor::storeMateria(AMateria *materia) {
    if (mStoredMateriaCount == Floor::MAX_STORE_SIZE)
        mStoredMateriaCount = 0;

    if (mStoredMaterias[mStoredMateriaCount] != NULL)
        delete mStoredMaterias[mStoredMateriaCount];

    mStoredMaterias[mStoredMateriaCount] = materia;
    ++mStoredMateriaCount;
}

void Floor::clearInstance() {
    for (int i = 0; i < Floor::MAX_STORE_SIZE; i++) {
        if (mStoredMaterias[i] == NULL)
            break;

        delete mStoredMaterias[i];
    }

    mStoredMateriaCount = 0;

    delete mFloorInstancePtr;
    mFloorInstancePtr = NULL;
}