#include "bsp_log.h"

#include "SEGGER_RTT.h"
#include "SEGGER_RTT_Conf.h"
#include "bsp_def.h"
#include "stdio.h"

void BSP_Log_Init() { SEGGER_RTT_Init(); }

int printf_log(const char* fmt, ...) {
    // char buffer[128];
    va_list args;
    va_start(args, fmt);
    // int n = vsnprintf(buffer,sizeof(buffer),fmt,args);
    // SEGGER_RTT_Write(BUFFER_INDEX,buffer,n);
    int n = SEGGER_RTT_vprintf(BUFFER_INDEX, fmt, &args);
    va_end(args);
    return n;
}

void Float2Str(char* str, float va) {
    int flag = va < 0;
    int head = (int)va;
    int point = (int)((va - head) * 1000);
    head = abs(head);
    point = abs(point);
    if (flag)
        sprintf(str, "-%d.%d", head, point);
    else
        sprintf(str, "%d.%d", head, point);
}