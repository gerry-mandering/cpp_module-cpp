/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:09:30 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/10 14:09:30 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource() {}

IMateriaSource::~IMateriaSource() {}

IMateriaSource::IMateriaSource(const IMateriaSource &iMateriaSource) {
    (void)iMateriaSource;
}

IMateriaSource &IMateriaSource::operator=(const IMateriaSource &iMateriaSource) {
    (void )iMateriaSource;

    return *this;
}