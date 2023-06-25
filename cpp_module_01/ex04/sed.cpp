/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:11:35 by minseok2          +#+    #+#             */
/*   Updated: 2023/06/25 15:11:35 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

bool readContent(char *filename, std::string &content) {
    std::ifstream inputStream(filename, std::ifstream::in);
    int fileLength;

    if (!inputStream.is_open())
        return false;

    inputStream.seekg(0, inputStream.end);
    fileLength = inputStream.tellg();
    inputStream.seekg(0, inputStream.beg);

    content.resize(fileLength);
    inputStream.read(&content[0], fileLength);

    inputStream.close();

    return true;
}

bool openNewFile(char *filename, std::ofstream &outputStream) {
    std::string newFilename(filename);

    newFilename.append(".replace");
    outputStream.open(newFilename.c_str(), std::ofstream::out);

    if (outputStream.fail())
        return false;
    return true;
}

void replaceContent(std::ofstream &outputStream, const std::string &content, char **argv) {
    std::string oldString(argv[2]);
    std::string newString(argv[3]);
    size_t searchPos = 0;
    size_t foundPos;

    while (true) {
        foundPos = content.find(oldString, searchPos);
        if (foundPos == std::string::npos) {
            outputStream.write(content.c_str() + searchPos, content.size() - searchPos);
            break;
        }
        outputStream.write(content.c_str() + searchPos, foundPos - searchPos);
        outputStream.write(newString.c_str(), newString.size());
        searchPos = foundPos + oldString.size();
    }

    outputStream.close();
}
