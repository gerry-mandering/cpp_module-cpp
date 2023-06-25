/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:11:35 by minseok2          +#+    #+#             */
/*   Updated: 2023/06/25 15:11:35 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_H
#define SED_H

#include <iostream>
#include <fstream>

bool readContent(char *filename, std::string &content);
bool openNewFile(char *filename, std::ofstream &outputStream);
void replaceContent(std::ofstream &outputStream, const std::string &content, char** argv);

#endif