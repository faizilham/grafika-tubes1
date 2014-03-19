// dummy conio.h
#ifndef CONIO_H_DUMMY
#define CONIO_H_DUMMY

#ifndef __BGI_GRAPHICS_H__
#include <graphics.h>
#endif


static inline int getch(){
	return readkey();
}

static inline int kbhit(){
	return anykeypressed();
}

#endif