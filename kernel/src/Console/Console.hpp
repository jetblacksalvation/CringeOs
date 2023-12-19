#ifndef COMMON_INC_
#include "./Common/common.hpp"
#endif
#ifndef CONSOLE_INC_

#ifndef _LIMINE_H
#include <limine.h>
#endif

class Console{
public:
    inline static volatile struct limine_framebuffer_request framebuffer_request = {
        .id = LIMINE_FRAMEBUFFER_REQUEST,
        .revision = 0,
        .response = 0
    };
private:
};

#define CONSOLE_INC_
#endif
