/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:00:21 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/02 20:00:21 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    ~ScavTrap();
    ScavTrap(const ScavTrap &scavTrap);
    ScavTrap &operator=(const ScavTrap &scavTrap);

public:
    ScavTrap(const std::string &name);

public:
    void attack(const std::string &target);

public:
    void guardGate();

private:
    ScavTrap();

private:
    void printErrorMessage(eErrorMessage errorMessage) const;
};

#endif