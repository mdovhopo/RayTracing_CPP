# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/28 13:12:30 by mdovhopo          #+#    #+#              #
#    Updated: 2019/03/28 16:49:59 by mdovhopo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++
CFLAGS = -c -Wall

INCLUDE_DIRS = 	-I . \
			-I inc/
SOURCE_DIR = src

INCLUDES =	inc/rtv1.hpp \
			inc/vec3.hpp

SOURCES = $(addprefix $(SOURCE_DIR)/, 	main.cpp \
										vec3.cpp \
										shape.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

FLAGS = -std=c++11 #-Wall -Wextra -Werror

EXECUTABLE = RTv1

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(FLAGS) $(INCLUDE_DIRS) $(OBJECTS) -o $@

.cpp.o: $(INCLUDES)
	$(CC) $(FLAGS) $(INCLUDE_DIRS) $(CFLAGS) $< -o $@

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(EXECUTABLE)

re: fclean all
