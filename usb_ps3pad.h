/* Teensyduino Core Library
 * http://www.pjrc.com/teensy/
 * Copyright (c) 2013 PJRC.COM, LLC.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * 1. The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * 2. If the Software is incorporated into a build system that allows
 * selection among a list of target devices, then similar target
 * devices manufactured by PJRC.COM must be included in the list of
 * target devices and selectable in the same manner.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef USBps3pad_h_
#define USBps3pad_h_

#if defined(USB_PS3HIDSERIAL) || defined(USB_PS3HID)

#include <inttypes.h>

#define DIR_CENTER 8
#define DIR_UP 0
#define DIR_UPRIGHT 1
#define DIR_RIGHT 2
#define DIR_DOWNRIGHT 3
#define DIR_DOWN 4
#define DIR_DOWNLEFT 5
#define DIR_LEFT 6
#define DIR_UPLEFT 7

// C language implementation
#ifdef __cplusplus
extern "C" {
#endif
typedef struct {
	// digital buttons, 0 = off, 1 = on
	uint8_t square_btn : 1;
	uint8_t cross_btn : 1;
	uint8_t circle_btn : 1;
	uint8_t triangle_btn : 1;

	uint8_t l1_btn : 1;
	uint8_t r1_btn : 1;
	uint8_t l2_btn : 1;
	uint8_t r2_btn : 1;

	uint8_t select_btn : 1;
	uint8_t start_btn : 1;
	uint8_t l3_btn : 1; // L3?
	uint8_t r3_btn : 1; // R3?
	uint8_t ps_btn : 1;
	uint8_t : 3; // Tilt Sensor?

	// digital direction, use the DIR_* defines
	uint8_t direction;

	// left and right analog sticks, 0x00 left/up, 0x80 middle, 0xff right/down
	uint8_t l_x_axis;
	uint8_t l_y_axis;
	uint8_t r_x_axis;
	uint8_t r_y_axis;

	// Unknown bytes, d-pad axes?
	uint8_t unknown[4];

	// button axis, 0x00 = unpressed, 0xff = fully pressed
	uint8_t triangle_axis;
	uint8_t circle_axis;
	uint8_t cross_axis;
	uint8_t square_axis;

	uint8_t l1_axis;
	uint8_t r1_axis;
	uint8_t l2_axis;
	uint8_t r2_axis;
} ps3pad_state_t;

void usb_ps3pad_reset_state(void);
uint8_t usb_ps3pad_send(void);

extern ps3pad_state_t ps3pad_state;
#ifdef __cplusplus
}
#endif

// C++ interface
#ifdef __cplusplus
class usb_ps3pad_class
{
    public:
		void LX(uint8_t val) {
			ps3pad_state.l_x_axis = val;
			send_auto();
		}
		void LY(uint8_t val) {
			ps3pad_state.l_y_axis = val;
			send_auto();
		}
		
		void RX(uint8_t val) {
			ps3pad_state.r_x_axis = val;
			send_auto();
		}
		void RY(uint8_t val) {
			ps3pad_state.r_y_axis = val;
			send_auto();
		}
		
		void DPad(uint8_t dir) {
			if( dir < 0 || dir > 8 ) dir = 8;
			ps3pad_state.direction = dir;
			send_auto();
		}
		
		void SquareButton(bool val) {
			if(val) ps3pad_state.square_btn = 1;
			else ps3pad_state.square_btn = 0;
			send_auto();
		}
		void CrossButton(bool val) {
			if(val) ps3pad_state.cross_btn = 1;
			else ps3pad_state.cross_btn = 0;
			send_auto();
		}
		void CircleButton(bool val) {
			if(val) ps3pad_state.circle_btn = 1;
			else ps3pad_state.circle_btn = 0;
			send_auto();
		}
		void TriangleButton(bool val) {
			if(val) ps3pad_state.triangle_btn = 1;
			else ps3pad_state.triangle_btn = 0;
			send_auto();
		}
		
		void L1Button(bool val) {
			if(val) ps3pad_state.l1_btn = 1;
			else ps3pad_state.l1_btn = 0;
			send_auto();
		}
		void R1Button(bool val) {
			if(val) ps3pad_state.r1_btn = 1;
			else ps3pad_state.r1_btn = 0;
			send_auto();
		}
		void L2Button(bool val) {
			if(val) ps3pad_state.l2_btn = 1;
			else ps3pad_state.l2_btn = 0;
			send_auto();
		}
		void R2Button(bool val) {
			if(val) ps3pad_state.r2_btn = 1;
			else ps3pad_state.r2_btn = 0;
			send_auto();
		}
		
		void SelectButton(bool val) {
			if(val) ps3pad_state.select_btn = 1;
			else ps3pad_state.select_btn = 0;
			send_auto();
		}
		void StartButton(bool val) {
			if(val) ps3pad_state.start_btn = 1;
			else ps3pad_state.start_btn = 0;
			send_auto();
		}
		void L3Button(bool val) {
			if(val) ps3pad_state.l3_btn = 1;
			else ps3pad_state.l3_btn = 0;
			send_auto();
		}
		void R3Button(bool val) {
			if(val) ps3pad_state.r3_btn = 1;
			else ps3pad_state.r3_btn = 0;
			send_auto();
		}
		void PSButton(bool val) {
			if(val) ps3pad_state.ps_btn = 1;
			else ps3pad_state.ps_btn = 0;
			send_auto();
		}
		
		void SquareAxis(uint8_t val) {
			ps3pad_state.square_axis = val;
			send_auto();
		}
		void CrossAxis(uint8_t val) {
			ps3pad_state.cross_axis = val;
			send_auto();
		}
		void CircleAxis(uint8_t val) {
			ps3pad_state.circle_axis = val;
			send_auto();
		}
		void TriangleAxis(uint8_t val) {
			ps3pad_state.triangle_axis = val;
			send_auto();
		}
		
		void L1Axis(uint8_t val) {
			ps3pad_state.l1_axis = val;
			send_auto();
		}
		void R1Axis(uint8_t val) {
			ps3pad_state.r1_axis = val;
			send_auto();
		}
		void L2Axis(uint8_t val) {
			ps3pad_state.l2_axis = val;
			send_auto();
		}
		void R2Axis(uint8_t val) {
			ps3pad_state.r2_axis = val;
			send_auto();
		}
		
		void useManualSend(bool mode) {
			manual_mode = mode;
		}
		void reset_state(void) {
			usb_ps3pad_reset_state();
		}
		uint8_t send_now(void) {
			return usb_ps3pad_send();
		}
	private:
		uint8_t send_auto() {
			if (!manual_mode) return usb_ps3pad_send();
			return -1;
		}
		
		static uint8_t manual_mode;
};
extern usb_ps3pad_class PS3Pad;

#endif // __cplusplus

#endif // USB_PS3HID
#endif // USBps3pad_h_

