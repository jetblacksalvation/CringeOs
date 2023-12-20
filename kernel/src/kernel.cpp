#include <./Common/common.hpp>
#include <Console/Console.hpp>
#ifndef _LIMINE_H
#include <limine.h>
#endif

// The Limine requests can be placed anywhere, but it is important that
// the compiler does not optimise them away, so, usually, they should
// be made volatile or equivalent.


// static const uint8_t asciiMap[255][MAX_ASCII_LEN]{
//     {
//         0b000000,
//         0b001100,
//         0b010010,
//         0b011110,
//         0b010010,
//         0b010010,
//         0b000000
//     }
// };
extern "C" void _start(void) {
    // Ensure we got a framebuffer.
    if (Console::framebufferRequest.response == NULL
     || Console::framebufferRequest.response->framebuffer_count < 1) {
    }
    // hcf();
    Console::p_char((uint8_t*)Console::asciiMap[0]);
    // Fetch the first framebuffer.

    // Note: we assume the framebuffer model is RGB with 32-bit pixels.
    // for (size_t i = 0; i < 100; i++) {
    //     volatile uint32_t *fb_ptr = (volatile uint32_t *)framebuffer->address;
    //     fb_ptr[i * (framebuffer->pitch / 4) + i] = 0xffffff;
    // }

    // We're done, just hang...
}
