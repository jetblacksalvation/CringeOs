#ifndef _COMMON_INC_
#include "./Common/common.hpp"
#endif
#ifndef _CONSOLE_INC_

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



    
    inline static const volatile void p_char(const uint8_t* keyMap){
    //     fb_ptr[i * (framebuffer->pitch / 4) + i] = 0xffffff;
        struct limine_framebuffer *framebuffer = Console::framebufferRequest.response->framebuffers[0];
        volatile uint32_t *fb_ptr = (volatile uint32_t *)framebuffer->address;

        for(uint64_t y = 0; y < MAX_ASCII_LEN; y++){
            for(uint8_t x =0; x<__CHAR_BIT__; x++){
                uint8_t isbit = (keyMap[y] >> x)&1;
                
                //draw 
                if(isbit)
                {

                    fb_ptr[(y+_y) * (framebuffer->pitch / 4) + (x+_x)] = 0xffffff;

                    


                    

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
    inline static const volatile void p_str(const char * str){
        char * s_copy = (char*)str;
        while(*s_copy != '\0'){
            if(*s_copy == '\n'){
                _y += MAX_ASCII_LEN;
                _x = 0;
                s_copy++;
                continue;
            }
            uint64_t mapKey = *(s_copy) - 'a';
            p_char(asciiMap[mapKey]);
            _x+=MAX_ASCII_LEN;
            //only '\n' incs y
            s_copy++;
        }
    }
inline static const uint8_t asciiMap[255][MAX_ASCII_LEN]{
    {},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},
    {}
    ,
    {
        // A
        0b111100,
        0b100010,
        0b100010,
        0b111110,
        0b100010,
        0b100010,
        0b100010
    },
    {
        // B
        0b011110,
        0b010100,
        0b010100,
        0b011100,
        0b010100,
        0b010100,
        0b011110
    },
    {
        // C
        0b011100,
        0b100010,
        0b000010,
        0b000010,
        0b000010,
        0b100010,
        0b011100
    },
    {
        // D
        0b001110,
        0b010100,
        0b100010,
        0b100010,
        0b100010,
        0b010100,
        0b001110
    },
    {
        // E
        0b111110,
        0b000010,
        0b000010,
        0b001110,
        0b000010,
        0b000010,
        0b111110
    },
    // Add more entries as needed
    {
        // F
        0b111110,
        0b000010,
        0b000010,
        0b001110,
        0b000010,
        0b000010,
        0b000010
    },
    {
        // G
        0b011100,
        0b100010,
        0b000010,
        0b110010,
        0b100010,
        0b100010,
        0b011100
    },
    {
        // H
        0b100010,
        0b100010,
        0b100010,
        0b111110,
        0b100010,
        0b100010,
        0b100010
    },
    {
        // I
        0b011100,
        0b001000,
        0b001000,
        0b001000,
        0b001000,
        0b001000,
        0b011100
    },
    {
        // J
        0b111100,
        0b010000,
        0b010000,
        0b010000,
        0b010000,
        0b010010,
        0b001100
    },
    {
        // K
        0b100010,
        0b100100,
        0b101000,
        0b110000,
        0b101000,
        0b100100,
        0b100010
    },
    {
        // L
        0b000010,
        0b000010,
        0b000010,
        0b000010,
        0b000010,
        0b000010,
        0b111110
    },
    {
        // M
        0b100010,
        0b110110,
        0b101010,
        0b100010,
        0b100010,
        0b100010,
        0b100010
    },
    {
        // N
        0b100010,
        0b110010,
        0b101010,
        0b100110,
        0b100010,
        0b100010,
        0b100010
    },
    {
        // O
        0b011100,
        0b100010,
        0b100010,
        0b100010,
        0b100010,
        0b100010,
        0b011100
    },
    {
        // P
        0b001110,
        0b010010,
        0b010010,
        0b001110,
        0b000010,
        0b000010,
        0b000010
    },
    {
        // Q
        0b011100,
        0b100010,
        0b100010,
        0b100010,
        0b101010,
        0b100100,
        0b011010
    },
    {
        // R
        0b001110,
        0b010010,
        0b010010,
        0b001110,
        0b010010,
        0b010010,
        0b010010
    },
    {
        // S
        0b011100,
        0b100010,
        0b000010,
        0b011100,
        0b100000,
        0b100010,
        0b011100
    },
    {
        // T
        0b111110,
        0b001000,
        0b001000,
        0b001000,
        0b001000,
        0b001000,
        0b001000
    },
    {
        // U
        0b100010,
        0b100010,
        0b100010,
        0b100010,
        0b100010,
        0b100010,
        0b011100
    },
    {
        // V
        0b100010,
        0b100010,
        0b100010,
        0b100010,
        0b100010,
        0b010100,
        0b001000
    },
    {
        // W
        0b100010,
        0b100010,
        0b100010,
        0b100010,
        0b101010,
        0b110110,
        0b100010
    },
    {
        // X
        0b100010,
        0b100010,
        0b010100,
        0b001000,
        0b010100,
        0b100010,
        0b100010
    },
    {
        // Y
        0b100010,
        0b100010,
        0b010100,
        0b001000,
        0b001000,
        0b001000,
        0b001000
    },
    {
        // Z
        0b111110,
        0b100000,
        0b010000,
        0b001000,
        0b000100,
        0b000010,
        0b111110
    }
    // Add more entries as needed
};

private:

    inline static uint64_t _x =0, _y =0;
    inline static uint64_t _fontInc = 2;

};


inline static volatile void pciConfigReadWord(uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset) {
    Console::p_str("getting pci info");


}


#define CONSOLE_INC_
#endif
