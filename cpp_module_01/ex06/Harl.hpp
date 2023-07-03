/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:48:06 by minseok2          +#+    #+#             */
/*   Updated: 2023/06/25 13:48:06 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H

#include <iostream>
#include "HarlEnum.hpp"

class Harl {
public:
    Harl();

    const std::string &getLevel() const;

    void printInstruction() const;
    void receiveInput();
    void complain(std::string level);

private:
    std::string mLevel;

    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

    typedef void (Harl::*CommentFunction)(void);

    bool getCommentType(const std::string &level, CommentType &commentType) const;
};

#endif
