/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:36:32 by minseok2          +#+    #+#             */
/*   Updated: 2023/06/23 21:36:32 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie {
private:
    std::string mName;

    Zombie(void);

public:
    Zombie(const std::string &name);
    ~Zombie(void);

    const std::string &getName() const;
    void setName(const std::string &name);

    void announce(void);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif