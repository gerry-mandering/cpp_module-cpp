/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:28:21 by minseok2          +#+    #+#             */
/*   Updated: 2023/06/24 21:28:21 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H

#define TotalComment 4

#include <iostream>

class Harl {
private:
    void debug(void);

    void info(void);

    void warning(void);

    void error(void);

public:
    Harl();

    void complain(std::string level);

    enum CommentType {
        DEBUG,
        INFO,
        WARNING,
        ERROR,
    };

    typedef void (Harl::*CommentFunction)(void);

    CommentFunction commentFunctions[5];
};

#endif