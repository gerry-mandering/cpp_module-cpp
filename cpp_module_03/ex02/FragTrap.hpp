/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:00:21 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/02 20:00:21 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
private:
    FragTrap();

public:
    ~FragTrap();
    FragTrap(const FragTrap &fragTrap);
    FragTrap &operator=(const FragTrap &fragTrap);

public:
    FragTrap(const std::string &name);

public:
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

public:
    void highFiveGuys(void);
};

#endif