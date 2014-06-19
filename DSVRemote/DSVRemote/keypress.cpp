#include "keypress.h"
#include <windows.h> // Needed for SendInput

// Hits key [code] up or down. 
// 
void set_key_state(char code, int state)
{
	// Structure used for the keyboard event
	INPUT ip;

	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = code; // Set scancode
	ip.ki.time = 0; // We don't actually care about the timestamp
	ip.ki.dwExtraInfo = 0; // 
	ip.ki.dwFlags = (state == KEYPRESS_KEYDOWN) ? (0) : (KEYEVENTF_KEYUP);

	// Trigger the event
	SendInput(1, &ip, sizeof(INPUT));
}

void send_key_down(char code)
{
	set_key_state(code, KEYPRESS_KEYDOWN);
}

void send_key_up(char code)
{
	set_key_state(code, KEYPRESS_KEYUP);
}