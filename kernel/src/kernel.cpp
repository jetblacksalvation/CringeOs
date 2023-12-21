#include <./Common/common.hpp>
#ifndef _CONSOLE_INC_
#include <Console/Console.hpp>
#endif
#ifndef _LIMINE_H
#include <limine.h>
#endif

// The Limine requests can be placed anywhere, but it is important that
// the compiler does not optimise them away, so, usually, they should
// be made volatile or equivalent.


extern "C" void _start(void) {
    // Ensure we got a framebuffer.
    if (Console::framebufferRequest.response == NULL
     || Console::framebufferRequest.response->framebuffer_count < 1) {
    }   
    volatile uint32_t PCI_ADDR = *(volatile uint32_t* )(0xCF8);
    
    // hcf();
    Console::p_str("kernel loaded\n");

}
