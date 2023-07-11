/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:09:30 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/10 14:09:30 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_H
#define MATERIA_SOURCE_H

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
public:
    MateriaSource();
    ~MateriaSource();
    MateriaSource(const MateriaSource &materiaSource);
    MateriaSource &operator=(const MateriaSource &materiaSource);

public:
    void learnMateria(AMateria *materia);
    AMateria *createMateria(std::string const &type);

public:
    int getMateriaCount() const;

private:
    static const int MAX_SOURCE_INVENTORY_COUNT = 4;

private:
    AMateria *mSourceInventory[MateriaSource::MAX_SOURCE_INVENTORY_COUNT];

private:
    int mMateriaCount;
};

#endif