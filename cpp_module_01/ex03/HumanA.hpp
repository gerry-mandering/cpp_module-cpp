/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 13:56:17 by minseok2          +#+    #+#             */
/*   Updated: 2023/06/24 13:56:17 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_H
#define HUMAN_A_H

#include "Weapon.hpp"
#include <iostream>

class HumanA {
private:
    std::string name;
    Weapon &weapon;

public:
//    HumanA(const std::string &name, const Weapon &weapon); 왜 const를 빼야 하는가?
    HumanA(const std::string &name, Weapon &weapon);

    void setName(const std::string &name);

    const std::string &getName() const;

    void attack(void) const;
};

#endif