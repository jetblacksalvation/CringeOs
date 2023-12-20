#ifndef COMMON_INC_
#include "./Common/common.hpp"
#endif
#ifndef CONSOLE_INC_

#ifndef _LIMINE_H
#include <limine.h>
#endif
#define MAX_ASCII_LEN 8
class Console{
public:
    inline static volatile struct limine_framebuffer_request framebufferRequest = {
        .id = LIMINE_FRAMEBUFFER_REQUEST,
        .revision = 0,
        .response = 0
    };
    inline static const uint8_t asciiMap[255][MAX_ASCII_LEN]{
        {
            0b000000,
            0b001100,
            0b010010,
            0b011110,
            0b010010,
            0b010010,
            0b000000
        }
    };
    inline static const volatile void p_char(uint8_t* keyMap){
    //     fb_ptr[i * (framebuffer->pitch / 4) + i] = 0xffffff;
        struct limine_framebuffer *framebuffer = Console::framebufferRequest.response->framebuffers[0];
        volatile uint32_t *fb_ptr = (volatile uint32_t *)framebuffer->address;

        for(uint64_t y = 0; y < MAX_ASCII_LEN; y++){
            for(uint8_t x =0; x<__CHAR_BIT__; x++){
                uint8_t isbit = (keyMap[y] >> x)&1;
                
                //draw 
                if(isbit)
                    {
                        for(int z = 1; z < _fontInc; z++)
                        {
                            for(int o = 1; o < _fontInc; o++){
                            fb_ptr[(y+z) * (framebuffer->pitch / 4) + (x+o)] = 0xffffff;

                            }


                        }

                    }
                // else{
                // for(int z = 1; z < _fontInc; z++)
                //         {
                //             for(int o = 1; o < _fontInc; o++){
                //             fb_ptr[(y+z) * (framebuffer->pitch / 4) + (x+o)] = 0x000;

                //             }


                //         }
                // }

            }
            
        }
    }

private:
    inline static const uint64_t _x =0, _y =0;
    inline static const uint64_t _fontInc = 1000;

};

#define CONSOLE_INC_
#endif
