/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:30:01 by minseok2          +#+    #+#             */
/*   Updated: 2023/06/23 22:30:01 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie {
public:
    Zombie(void);
    ~Zombie(void);

    const std::string &getName() const;
    void setName(const std::string &name);

    void announce(void);

private:
    std::string mName;
};

Zombie *zombieHorde(int N, std::string name);

#endif