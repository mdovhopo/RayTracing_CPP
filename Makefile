# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/28 13:12:30 by mdovhopo          #+#    #+#              #
#    Updated: 2019/03/30 19:49:30 by mdovhopo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++
CFLAGS = -c -Wall

INCLUDE_DIRS = 	-I . \
			-I inc/	\
			-I frameworks/SDL2_image.framework/Versions/A/Headers \
			-I frameworks/SDL2.framework/Versions/A/Headers \

FRAMEWORKS = -framework OpenCL \
			-F frameworks \
			-rpath frameworks \
			-framework SDL2 \
			-framework SDL2_image \

STANDARTS = -std=c++11 -stdlib=libc++

SOURCE_DIR = src

INCLUDES =	inc/rtv1.hpp \
			inc/vec3.hpp

SOURCES = $(addprefix $(SOURCE_DIR)/, 	main.cpp \
										vec3.cpp \
										compute_light.cpp \
										math_util.cpp \
										sdl_abstraction.cpp \
										get_shape_normal.cpp \
										trace.cpp \
										shape_intersection.cpp)

OBJECTS = $(SOURCES:.cpp=.o)

EXECUTABLE = RTv1

.PHONY: all multi

multi:
	@$(MAKE) -j8 all

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(STANDARTS) $(FLAGS) $(INCLUDE_DIRS) $(OBJECTS) $(FRAMEWORKS) -o $@ 

.cpp.o: $(INCLUDES)
	$(CC) $(STANDARTS) $(FLAGS) $(INCLUDE_DIRS) $(CFLAGS) $< -o $@

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(EXECUTABLE)

re: fclean multi
