/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:11:35 by minseok2          +#+    #+#             */
/*   Updated: 2023/06/25 15:11:35 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int main(int argc, char **argv) {
    std::string content;

    if (argc != 4) {
        std::cout << "Invalid Input" << std::endl;
        return 0;
    }

    if (!readContent(argv[1], content)) {
        std::cout << "Invalid Filename" << std::endl;
        return 0;
    }

    std::ofstream outputStream;
    if (!openNewFile(argv[1], outputStream)) {
        std::cout << "File Open Failure" << std::endl;
        return 0;
    }

    replaceContent(outputStream, content, argv);

    return 0;
}
