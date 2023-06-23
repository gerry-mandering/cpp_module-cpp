#!/bin/bash

# Check if target name and at least one filename are provided
if [ $# -lt 2 ]; then
    echo "Please provide a target name and at least one filename."
    exit 1
fi

# Get the target name
target_name=$1
shift

# Get the user name and email from git config
user_name="minseok2"
user_email="minseok2@student.42seoul.kr"

# Get the current date and time
datetime=$(date '+%Y/%m/%d %H:%M:%S')

# Create .cpp and .hpp files, and add to SRCS
SRCS=""
for filename in "$@"; do
    for extension in cpp hpp; do
        # Create the file
        touch "${filename}.$extension"

        # Set the permissions
        chmod 644 "${filename}.$extension"

        # Calculate the number of space characters needed to align the header
        spaces_filename=$(( 50 - ${#filename} - ${#extension} ))
        spaces_by=$(( 40 - ${#user_name} - ${#user_email} ))
        spaces_created=$(( 37 - ${#datetime} - ${#user_name} ))
        spaces_updated=$(( 36 - ${#datetime} - ${#user_name} ))

        # Write the 42 header
        echo "/* ************************************************************************** */" > "${filename}.$extension"
        echo "/*                                                                            */" >> "${filename}.$extension"
        echo "/*                                                        :::      ::::::::   */" >> "${filename}.$extension"
        printf "/*   %s.%s%*s:+:      :+:    :+:   */\n" "$filename" "$extension" "$spaces_filename" "" >> "${filename}.$extension"
        echo "/*                                                    +:+ +:+         +:+     */" >> "${filename}.$extension"
        printf "/*   By: %s <%s>%*s+#+  +:+       +#+        */\n" "$user_name" "$user_email" "$spaces_by" "" >> "${filename}.$extension"
        echo "/*                                                +#+#+#+#+#+   +#+           */" >> "${filename}.$extension"
        printf "/*   Created: %s by %s%*s+#+    #+#             */\n" "$datetime" "$user_name" "$spaces_created" "" >> "${filename}.$extension"
        printf "/*   Updated: %s by %s%*s###   ########.fr       */\n" "$datetime" "$user_name" "$spaces_updated" "" >> "${filename}.$extension"
        echo "/*                                                                            */" >> "${filename}.$extension"
        echo "/* ************************************************************************** */" >> "${filename}.$extension"
    done

    # Add to SRCS
    SRCS+="\t\t${filename}.cpp \\ \n"
done

touch "main.cpp"

# Set the permissions
chmod 644 "main.cpp"

# Calculate the number of space characters needed to align the header
filename="main"
extension="cpp"
spaces_filename=$(( 50 - ${#filename} - ${#extension} ))
spaces_by=$(( 40 - ${#user_name} - ${#user_email} ))
spaces_created=$(( 37 - ${#datetime} - ${#user_name} ))
spaces_updated=$(( 36 - ${#datetime} - ${#user_name} ))

# Write the 42 header
echo "/* ************************************************************************** */" > "${filename}.$extension"
echo "/*                                                                            */" >> "${filename}.$extension"
echo "/*                                                        :::      ::::::::   */" >> "${filename}.$extension"
printf "/*   %s.%s%*s:+:      :+:    :+:   */\n" "$filename" "$extension" "$spaces_filename" "" >> "${filename}.$extension"
echo "/*                                                    +:+ +:+         +:+     */" >> "${filename}.$extension"
printf "/*   By: %s <%s>%*s+#+  +:+       +#+        */\n" "$user_name" "$user_email" "$spaces_by" "" >> "${filename}.$extension"
echo "/*                                                +#+#+#+#+#+   +#+           */" >> "${filename}.$extension"
printf "/*   Created: %s by %s%*s+#+    #+#             */\n" "$datetime" "$user_name" "$spaces_created" "" >> "${filename}.$extension"
printf "/*   Updated: %s by %s%*s###   ########.fr       */\n" "$datetime" "$user_name" "$spaces_updated" "" >> "${filename}.$extension"
echo "/*                                                                            */" >> "${filename}.$extension"
echo "/* ************************************************************************** */" >> "${filename}.$extension"


# Create a new Makefile or overwrite an existing one
exec 3>Makefile

spaces_by=$(( 40 - ${#user_name} - ${#user_email} ))
spaces_created=$(( 37 - ${#datetime} - ${#user_name} ))
spaces_updated=$(( 36 - ${#datetime} - ${#user_name} ))

# Write the 42 header
echo "# **************************************************************************** #" >&3
echo "#                                                                              #" >&3
echo "#                                                         :::      ::::::::    #" >&3
echo "#    Makefile                                           :+:      :+:    :+:    #" >&3
echo "#                                                     +:+ +:+         +:+      #" >&3
printf "#    By: %s <%s>%*s+#+  +:+       +#+         #\n" "$user_name" "$user_email" "$spaces_by" "" >&3
echo "#                                                 +#+#+#+#+#+   +#+            #" >&3
printf "#    Created: %s by %s%*s#+#    #+#              #\n" "$datetime" "$user_name" "$spaces_created" "" >&3
printf "#    Updated: %s by %s%*s###   ########.fr        #\n" "$datetime" "$user_name" "$spaces_updated" "" >&3
echo "#                                                                              #" >&3
echo "# **************************************************************************** #" >&3
echo "" >&3

# Write the initial part of the Makefile
echo "NAME = $target_name" >&3
echo "CPP = c++" >&3
echo "CPPFLAGS = -Wall -Wextra -Werror -std=c++98" >&3
echo "OBJS = \$(SRCS:.cpp=.o)" >&3
echo "SRCS =  main.cpp \\" >&3
echo -e "$SRCS" >&3

# Write the rest of the Makefile
echo "all: \$(NAME)" >&3
echo "\$(NAME): \$(OBJS)" >&3
echo -e "\t\$(CPP) \$(CPPFLAGS) -o \$@ \$^\n" >&3
echo "%.o: %.cpp" >&3
echo -e "\t\$(CPP) \$(CPPFLAGS) -c \$< -o \$@\n" >&3
echo "clean:" >&3
echo -e "\trm -f \$(OBJS)\n" >&3
echo "fclean: clean" >&3
echo -e "\trm -f \$(NAME)\n" >&3
echo "re: fclean all" >&3
echo ".PHONY: clean fclean all re" >&3

# Close the file descriptor
exec 3>&-

exit 0
