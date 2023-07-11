/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:09:30 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/10 14:09:30 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_H
#define FLOOR_H

#include <cstdlib>
#include "AMateria.hpp"

class Floor {
public:
    ~Floor();
    Floor(const Floor &floor);
    Floor &operator=(const Floor &floor);

public:
    static Floor *getInstance();
    static void clearInstance();

public:
    void storeMateria(AMateria *materia);

private:
    static Floor* mFloorInstancePtr;

private:
    static const int MAX_STORE_SIZE = 100;

private:
    static AMateria *mStoredMaterias[Floor::MAX_STORE_SIZE];

private:
    static int mStoredMateriaCount;

private:
    Floor();
};

#endif