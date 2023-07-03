/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:53:35 by minseok2          +#+    #+#             */
/*   Updated: 2023/06/23 22:53:35 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

int main(void) {

    std::string greetings("HI THIS IS BRAIN");
    std::string *stringPTR = &greetings;
    std::string &stringREF = greetings;

    std::cout
            << std::setw(39) << std::left << "The Memory Address of greetings : " << &greetings << std::endl
            << std::setw(39) << std::left << "The Memory Address held by stringPTR : " << stringPTR << std::endl
            << std::setw(39) << std::left << "The Memory Address held by stringREF : " << &stringREF << std::endl;

    std::cout
            << std::setw(33) << std::left << "The Value of greetings : " << greetings << std::endl
            << std::setw(33) << std::left << "The Value Pointed by stringPTR : " << *stringPTR << std::endl
            << std::setw(33) << std::left << "The Value Pointed by stringREF : " << stringREF << std::endl;

    return 0;
}