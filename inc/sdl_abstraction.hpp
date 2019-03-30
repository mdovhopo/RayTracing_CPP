/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_abstraction.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:18:17 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/03/30 17:50:45 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_ABSTRACTION
# define SDL_ABSTRACTION

#include <SDL2/SDL.h>

namespace rt {

    class SDL {
        private:
            SDL_Window  *window;
            SDL_Surface *surface;
            uint32_t    width;
            uint32_t    height;
            float       aspect_ratio;
        public:
            SDL(const char * name, const uint32_t w_, const uint32_t h_);
            ~SDL();
            void        color_pixel(uint32_t color, uint32_t x, uint32_t y);
            uint32_t    getWidth(void);
            uint32_t    getHeight(void);
            float       getAspectRatio(void);
            void        update_window(void);
            bool        if_exit_event(SDL_Event e);
            // void    color_pixel(uint8_t r, uint8_t g, uint8_t b);
    };

}

#endif