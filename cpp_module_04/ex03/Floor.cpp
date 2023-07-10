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

Floor::Floor() {
    mStoredMateriaCount = 0;

    for (int i = 0; i < Floor::MAX_STORE_SIZE; i++) {
        mStoredMaterias[i] = NULL;
    }
}

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

void Floor::resetInstance() {
    delete mFloorInstancePtr;
    mFloorInstancePtr = NULL;
}