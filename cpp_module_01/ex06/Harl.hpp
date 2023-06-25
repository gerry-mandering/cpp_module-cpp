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

#define TotalComment 4

#include <iostream>

class Harl {
private:
    void debug(void);

    void info(void);

    void warning(void);

    void error(void);

    typedef enum commentType {
        DEBUG,
        INFO,
        WARNING,
        ERROR,
    } CommentType;

    typedef void (Harl::*CommentFunction)(void);

    CommentFunction commentFunctions[5];

    bool getCommentType(const std::string &level, CommentType &commentType) const;

public:
    Harl();

    void complain(std::string level);
};

#endif
