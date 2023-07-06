/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 19:59:17 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/02 19:59:17 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include "MessageEnum.hpp"

class ClapTrap {
public:
    ClapTrap();
    ~ClapTrap();
    ClapTrap(const ClapTrap &clapTrap);
    ClapTrap &operator=(const ClapTrap &clapTrap);

public:
    ClapTrap(const std::string &name);

public:
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

protected:
    const std::string &getName() const;
    const unsigned int &getHitPoint() const;
    const unsigned int &getEnergyPoint() const;
    const unsigned int &getAttackDamage() const;

    void setName(const std::string &name);
    void setHitPoint(const unsigned int &hitPoint);
    void setEnergyPoint(const unsigned int &energyPoint);
    void setAttackDamage(const unsigned int &attackDamage);

protected:
    void useEnergy();

private:
    std::string mName;
    unsigned int mHitPoint;
    unsigned int mEnergyPoint;
    unsigned int mAttackDamage;

private:
    unsigned int mMaxHitPoint;

private:
    void printErrorMessage(eErrorMessage errorMessage) const;
};

#endif