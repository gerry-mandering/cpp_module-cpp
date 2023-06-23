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
private:
    std::string mName;

public:
    Zombie(void);

    Zombie(const std::string &name);

    ~Zombie(void);

    void SetName(const std::string &name);

    const std::string &GetName() const;

    void announce(void);
};

#endif