/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 13:56:17 by minseok2          +#+    #+#             */
/*   Updated: 2023/06/24 13:56:17 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_H
#define HUMAN_B_H

#include "Weapon.hpp"
#include <iostream>

class HumanB {
private:
    std::string name;
    Weapon *weapon;

    HumanB(void);

public:
    HumanB(const std::string &name);

    void setName(const std::string &name);

//    void setWeapon(const Weapon &weapon); 왜 const 빼는가?
    void setWeapon(Weapon &weapon);

    const std::string &getName() const;

    void attack(void) const;
};

#endif
