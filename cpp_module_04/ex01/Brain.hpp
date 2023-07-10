/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:25:03 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/03 13:25:03 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include <sstream>

class Brain {
public:
    Brain();
    ~Brain();
    Brain(const Brain &brain);
    Brain &operator=(const Brain &brain);

private:
    static const int NUMBER_OF_IDEAS = 100;

private:
    std::string ideas[Brain::NUMBER_OF_IDEAS];
};

#endif