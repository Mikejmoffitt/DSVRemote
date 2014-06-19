// Provides some simple Win32 functions to set the state of a key. A function
// also exists to 

#ifndef KEYPRESS_H
#define KEYPRESS_H

#define KEYPRESS_KEYUP 1
#define KEYPRESS_KEYDOWN 0

void set_key_state(char code, int state);
void send_key_down(char code);
void send_key_up(char code);

#endif KEYPRESS_H