/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:00:43 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/02 20:00:43 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_H
#define DIAMOND_TRAP_H

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
public:
    ~DiamondTrap();
    DiamondTrap(const DiamondTrap &diamondTrap);
    DiamondTrap &operator=(const DiamondTrap &diamondTrap);

public:
    DiamondTrap(const std::string &name);

public:
    void attack(const std::string &target);

public:
    void whoAmI();

private:
    std::string mName;

private:
    DiamondTrap();
};

#endif