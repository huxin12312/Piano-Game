

///*
// *	wiiuse
// *
// *	Written By:
// *		Michael Laforest	< para >
// *		Email: < thepara (--AT--) g m a i l [--DOT--] com >
// *
// *	Copyright 2006-2007
// *
// *	This file is part of wiiuse.
// *
// *	This program is free software; you can redistribute it and/or modify
// *	it under the terms of the GNU General Public License as published by
// *	the Free Software Foundation; either version 3 of the License, or
// *	(at your option) any later version.
// *
// *	This program is distributed in the hope that it will be useful,
// *	but WITHOUT ANY WARRANTY; without even the implied warranty of
// *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// *	GNU General Public License for more details.
// *
// *	You should have received a copy of the GNU General Public License
// *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
// *
// *	$Header$
// *
// */
//
///**
// *	@file
// *
// *	@brief Example using the wiiuse API.
// *
// *	This file is an example of how to use the wiiuse library.
// */
//
////#include <stdio.h>
////#include <stdlib.h>
//
//#include "wiiuse.h"
//
//
//#define MAX_WIIMOTES				4
//
//
///**
// *	@brief Callback that handles an event.
// *
// *	@param wm		Pointer to a wiimote_t structure.
// *
// *	This function is called automatically by the wiiuse library when an
// *	event occurs on the specified wiimote.
// */
//void handle_event(struct wiimote_t* wm) {
//	int counter=0;
//	//;//printf("\n\n--- EVENT [id %i] ---\n", wm->unid);
//
//	/* if a button is pressed, report it */
//	if (IS_PRESSED(wm, WIIMOTE_BUTTON_A))		;//;//printf("A button pressed\n");
//	if (IS_PRESSED(wm, WIIMOTE_BUTTON_B))		;//;//printf("B button pressed\n");
//	if (IS_PRESSED(wm, WIIMOTE_BUTTON_UP))		;//;//printf("UP button pressed\n");
//	if (IS_PRESSED(wm, WIIMOTE_BUTTON_DOWN))	;//;//printf("DOWN button pressed\n");
//	if (IS_PRESSED(wm, WIIMOTE_BUTTON_LEFT))	;//;//printf("LEFT button pressed\n");
//	if (IS_PRESSED(wm, WIIMOTE_BUTTON_RIGHT))	;//;//printf("RIGHT button pressed\n");
//	if (IS_PRESSED(wm, WIIMOTE_BUTTON_MINUS))
//    {
//       counter=counter--;
//   	   ;//;//printf("MINUS button pressed. Counter = %d\n", counter);
//    }
//	if (IS_PRESSED(wm, WIIMOTE_BUTTON_PLUS))
//    {
//       counter = counter++;
//   	   ;//;//printf("PLUS button pressed. Counter = %d\n", counter);
//    }
//	if (IS_PRESSED(wm, WIIMOTE_BUTTON_ONE))
//    {
//    ;//printf("ONE button pressed\n");
//    }
//	if (IS_PRESSED(wm, WIIMOTE_BUTTON_TWO))		;//printf("TWO button pressed\n");
//	if (IS_PRESSED(wm, WIIMOTE_BUTTON_HOME))	
//    {
//      ;//printf("HOME button pressed\n");
//      exit(1);
//    }
//	/*
//	 *	Pressing minus will tell the wiimote we are no longer interested in movement.
//	 *	This is useful because it saves battery power.
//	 */
//	if (IS_JUST_PRESSED(wm, WIIMOTE_BUTTON_MINUS))
//		wiiuse_motion_sensing(wm, 0);
//
//	/*
//	 *	Pressing plus will tell the wiimote we are interested in movement.
//	 */
//	if (IS_JUST_PRESSED(wm, WIIMOTE_BUTTON_PLUS))
//		wiiuse_motion_sensing(wm, 1);
//
//	/*
//	 *	Pressing B will toggle the rumble
//	 *
//	 *	if B is pressed but is not held, toggle the rumble
//	 */
//	if (IS_JUST_PRESSED(wm, WIIMOTE_BUTTON_A))
//		wiiuse_toggle_rumble(wm);
//
//	if (IS_JUST_PRESSED(wm, WIIMOTE_BUTTON_UP))
//		wiiuse_set_ir(wm, 1);
//	if (IS_JUST_PRESSED(wm, WIIMOTE_BUTTON_DOWN))
//		wiiuse_set_ir(wm, 0);
//
//	/* if the accelerometer is turned on then print angles */
//	if (WIIUSE_USING_ACC(wm)) {
//		;//printf("wiimote roll  = %f [%f]\n", wm->orient.roll, wm->orient.a_roll);
//		;//printf("wiimote pitch = %f [%f]\n", wm->orient.pitch, wm->orient.a_pitch);
//		;//printf("wiimote yaw   = %f\n", wm->orient.yaw);
//	}
//
//	/*
//	 *	If IR tracking is enabled then print the coordinates
//	 *	on the virtual screen that the wiimote is pointing to.
//	 *
//	 *	Also make sure that we see at least 1 dot.
//	 */
//	if (WIIUSE_USING_IR(wm)) {
//		int i = 0;
//
//		/* go through each of the 4 possible IR sources */
//		for (; i < 4; ++i) {
//			/* check if the source is visible */
//			if (wm->ir.dot[i].visible)
//				;//printf("IR source %i: (%u, %u)\n", i, wm->ir.dot[i].x, wm->ir.dot[i].y);
//		}
//
//		;//printf("IR cursor: (%u, %u)\n", wm->ir.x, wm->ir.y);
//		;//printf("IR z distance: %f\n", wm->ir.z);
//	}
//
//	/* show events specific to supported expansions */
//	if (wm->exp.type == EXP_NUNCHUK) {
//		/* nunchuk */
//		struct nunchuk_t* nc = (nunchuk_t*)&wm->exp.nunchuk;
//
//		if (IS_PRESSED(nc, NUNCHUK_BUTTON_C))		;//printf("Nunchuk: C pressed\n");
//		if (IS_PRESSED(nc, NUNCHUK_BUTTON_Z))		;//printf("Nunchuk: Z pressed\n");
//
//		;//printf("nunchuk roll  = %f\n", nc->orient.roll);
//		;//printf("nunchuk pitch = %f\n", nc->orient.pitch);
//		;//printf("nunchuk yaw   = %f\n", nc->orient.yaw);
//
//		;//printf("nunchuk joystick angle:     %f\n", nc->js.ang);
//		;//printf("nunchuk joystick magnitude: %f\n", nc->js.mag);
//	} else if (wm->exp.type == EXP_CLASSIC) {
//		/* classic controller */
//		struct classic_ctrl_t* cc = (classic_ctrl_t*)&wm->exp.classic;
//
//		if (IS_PRESSED(cc, CLASSIC_CTRL_BUTTON_ZL))			;//printf("Classic: ZL pressed\n");
//		if (IS_PRESSED(cc, CLASSIC_CTRL_BUTTON_B))			;//printf("Classic: B pressed\n");
//		if (IS_PRESSED(cc, CLASSIC_CTRL_BUTTON_Y))			;//printf("Classic: Y pressed\n");
//		if (IS_PRESSED(cc, CLASSIC_CTRL_BUTTON_A))			;//printf("Classic: A pressed\n");
//		if (IS_PRESSED(cc, CLASSIC_CTRL_BUTTON_X))			;//printf("Classic: X pressed\n");
//		if (IS_PRESSED(cc, CLASSIC_CTRL_BUTTON_ZR))			;//printf("Classic: ZR pressed\n");
//		if (IS_PRESSED(cc, CLASSIC_CTRL_BUTTON_LEFT))		;//printf("Classic: LEFT pressed\n");
//		if (IS_PRESSED(cc, CLASSIC_CTRL_BUTTON_UP))			;//printf("Classic: UP pressed\n");
//		if (IS_PRESSED(cc, CLASSIC_CTRL_BUTTON_RIGHT))		;//printf("Classic: RIGHT pressed\n");
//		if (IS_PRESSED(cc, CLASSIC_CTRL_BUTTON_DOWN))		;//printf("Classic: DOWN pressed\n");
//		if (IS_PRESSED(cc, CLASSIC_CTRL_BUTTON_FULL_L))		;//printf("Classic: FULL L pressed\n");
//		if (IS_PRESSED(cc, CLASSIC_CTRL_BUTTON_MINUS))		;//printf("Classic: MINUS pressed\n");
//		if (IS_PRESSED(cc, CLASSIC_CTRL_BUTTON_HOME))		;//printf("Classic: HOME pressed\n");
//		if (IS_PRESSED(cc, CLASSIC_CTRL_BUTTON_PLUS))		;//printf("Classic: PLUS pressed\n");
//		if (IS_PRESSED(cc, CLASSIC_CTRL_BUTTON_FULL_R))		;//printf("Classic: FULL R pressed\n");
//
//		;//printf("classic L button pressed:         %f\n", cc->l_shoulder);
//		;//printf("classic R button pressed:         %f\n", cc->r_shoulder);
//		;//printf("classic left joystick angle:      %f\n", cc->ljs.ang);
//		;//printf("classic left joystick magnitude:  %f\n", cc->ljs.mag);
//		;//printf("classic right joystick angle:     %f\n", cc->rjs.ang);
//		;//printf("classic right joystick magnitude: %f\n", cc->rjs.mag);
//	} else if (wm->exp.type == EXP_GUITAR_HERO_3) {
//		/* guitar hero 3 guitar */
//		struct guitar_hero_3_t* gh3 = (guitar_hero_3_t*)&wm->exp.gh3;
//
//		if (IS_PRESSED(gh3, GUITAR_HERO_3_BUTTON_STRUM_UP))		;//printf("Guitar: Strum Up pressed\n");
//		if (IS_PRESSED(gh3, GUITAR_HERO_3_BUTTON_STRUM_DOWN))	;//printf("Guitar: Strum Down pressed\n");
//		if (IS_PRESSED(gh3, GUITAR_HERO_3_BUTTON_YELLOW))		;//printf("Guitar: Yellow pressed\n");
//		if (IS_PRESSED(gh3, GUITAR_HERO_3_BUTTON_GREEN))		;//printf("Guitar: Green pressed\n");
//		if (IS_PRESSED(gh3, GUITAR_HERO_3_BUTTON_BLUE))			;//printf("Guitar: Blue pressed\n");
//		if (IS_PRESSED(gh3, GUITAR_HERO_3_BUTTON_RED))			;//printf("Guitar: Red pressed\n");
//		if (IS_PRESSED(gh3, GUITAR_HERO_3_BUTTON_ORANGE))		;//printf("Guitar: Orange pressed\n");
//		if (IS_PRESSED(gh3, GUITAR_HERO_3_BUTTON_PLUS))			;//printf("Guitar: Plus pressed\n");
//		if (IS_PRESSED(gh3, GUITAR_HERO_3_BUTTON_MINUS))		;//printf("Guitar: Minus pressed\n");
//
//		;//printf("Guitar whammy bar:          %f\n", gh3->whammy_bar);
//		;//printf("Guitar joystick angle:      %f\n", gh3->js.ang);
//		;//printf("Guitar joystick magnitude:  %f\n", gh3->js.mag);
//	}
//}
//
//
///**
// *	@brief Callback that handles a read event.
// *
// *	@param wm		Pointer to a wiimote_t structure.
// *	@param data		Pointer to the filled data block.
// *	@param len		Length in bytes of the data block.
// *
// *	This function is called automatically by the wiiuse library when
// *	the wiimote has returned the full data requested by a previous
// *	call to wiiuse_read_data().
// *
// *	You can read data on the wiimote, such as Mii data, if
// *	you know the offset address and the length.
// *
// *	The \a data pointer was specified on the call to wiiuse_read_data().
// *	At the time of this function being called, it is not safe to deallocate
// *	this buffer.
// */
//void handle_read(struct wiimote_t* wm, byte* data, unsigned short len) {
//	int i = 0;
//
//	;//printf("\n\n--- DATA READ [wiimote id %i] ---\n", wm->unid);
//	;//printf("finished read of size %i\n", len);
//	for (; i < len; ++i) {
//		if (!(i%16))
//			;//printf("\n");
//		;//printf("%x ", data[i]);
//	}
//	;//printf("\n\n");
//}
//
//
///**
// *	@brief Callback that handles a controller status event.
// *
// *	@param wm				Pointer to a wiimote_t structure.
// *	@param attachment		Is there an attachment? (1 for yes, 0 for no)
// *	@param speaker			Is the speaker enabled? (1 for yes, 0 for no)
// *	@param ir				Is the IR support enabled? (1 for yes, 0 for no)
// *	@param led				What LEDs are lit.
// *	@param battery_level	Battery level, between 0.0 (0%) and 1.0 (100%).
// *
// *	This occurs when either the controller status changed
// *	or the controller status was requested explicitly by
// *	wiiuse_status().
// *
// *	One reason the status can change is if the nunchuk was
// *	inserted or removed from the expansion port.
// */
//void handle_ctrl_status(struct wiimote_t* wm) {
//	;//printf("\n\n--- CONTROLLER STATUS [wiimote id %i] ---\n", wm->unid);
//
//	;//printf("attachment:      %i\n", wm->exp.type);
//	;//printf("speaker:         %i\n", WIIUSE_USING_SPEAKER(wm));
//	;//printf("ir:              %i\n", WIIUSE_USING_IR(wm));
//	;//printf("leds:            %i %i %i %i\n", WIIUSE_IS_LED_SET(wm, 1), WIIUSE_IS_LED_SET(wm, 2), WIIUSE_IS_LED_SET(wm, 3), WIIUSE_IS_LED_SET(wm, 4));
//	;//printf("battery:         %f %%\n", wm->battery_level);
//}
//
//
///**
// *	@brief Callback that handles a disconnection event.
// *
// *	@param wm				Pointer to a wiimote_t structure.
// *
// *	This can happen if the POWER button is pressed, or
// *	if the connection is interrupted.
// */
//void handle_disconnect(wiimote* wm) {
//	;//printf("\n\n--- DISCONNECTED [wiimote id %i] ---\n", wm->unid);
//}
//
//
//void test(struct wiimote_t* wm, byte* data, unsigned short len) {
//	;//printf("test: %i [%x %x %x %x]\n", len, data[0], data[1], data[2], data[3]);
//}
//
//
//
///**
// *	@brief main()
// *
// *	Connect to up to two wiimotes and print any events
// *	that occur on either device.
// */
//int wii_main(int wall) {
//	wiimote** wiimotes;
//	int found, connected;
//
//	/*
//	 *	Initialize an array of wiimote objects.
//	 *
//	 *	The parameter is the number of wiimotes I want to create.
//	 */
//	wiimotes =  wiiuse_init(MAX_WIIMOTES);
//
//	//Get wiimotes
//	found = wiiuse_find(wiimotes, MAX_WIIMOTES, 5);
//	if (!found) {
//		return 0;
//	}
//
//	/*
//	 *	Connect to the wiimotes
//	 *	This will return the number of established connections to the found wiimotes.
//	 */
//	connected = wiiuse_connect(wiimotes, MAX_WIIMOTES);
//	if (connected){
//		wiiuse_set_leds(wiimotes[0], WIIMOTE_LED_1);
//		wiiuse_set_leds(wiimotes[1], WIIMOTE_LED_2);
//		wiiuse_set_leds(wiimotes[2], WIIMOTE_LED_3);
//		wiiuse_set_leds(wiimotes[3], WIIMOTE_LED_4);
//		wiiuse_rumble(wiimotes[0], 1);
//		wiiuse_rumble(wiimotes[1], 1);
//		Sleep(200);
//		wiiuse_rumble(wiimotes[0], 0);
//		wiiuse_rumble(wiimotes[1], 0);
//	} else wall = 0;
//
//	if(wall){
//		wiiuse_toggle_rumble(wiimotes[0]);
//		Sleep(500);
//		wiiuse_toggle_rumble(wiimotes[0]);
//	}
//
//		if(connected) {
//			wiiuse_cleanup(wiimotes, MAX_WIIMOTES);
//		}
//
//	/*
//	 *	Maybe I'm interested in the battery power of the 0th
//	 *	wiimote.  This should be WIIMOTE_ID_1 but to be sure
//	 *	you can get the wiimote assoicated with WIIMOTE_ID_1
//	 *	using the wiiuse_get_by_id() function.
//	 *
//	 *	A status request will return other things too, like
//	 *	if any expansions are plugged into the wiimote or
//	 *	what LEDs are lit.
//	 */
//	//wiiuse_status(wiimotes[0]);
//
//	/*
//	 *	This is the main loop
//	 *
//	 *	wiiuse_poll() needs to be called with the wiimote array
//	 *	and the number of wiimote structures in that array
//	 *	(it doesn't matter if some of those wiimotes are not used
//	 *	or are not connected).
//	 *
//	 *	This function will set the event flag for each wiimote
//	 *	when the wiimote has things to report.
//	 */
//	//while (1) {
//	//	if (wiiuse_poll(wiimotes, MAX_WIIMOTES)) {
//	//		/*
//	//		 *	This happens if something happened on any wiimote.
//	//		 *	So go through each one and check if anything happened.
//	//		 */
//	//		int i = 0;
//	//		for (; i < MAX_WIIMOTES; ++i) {
//	//			switch (wiimotes[i]->event) {
//	//				case WIIUSE_EVENT:
//	//					/* a generic event occured */
//	//					//handle_event(wiimotes[i]);
//	//					//if (IS_JUST_PRESSED(wiimotes[i], WIIMOTE_BUTTON_A))
//	//					
//	//					
//
//	//				//case WIIUSE_STATUS:
//	//				//	/* a status event occured */
//	//				//	handle_ctrl_status(wiimotes[i]);
//	//				//	break;
//
//	//				case WIIUSE_DISCONNECT:
//	//				case WIIUSE_UNEXPECTED_DISCONNECT:
//	//					/* the wiimote disconnected */
//	//					handle_disconnect(wiimotes[i]);
//	//					break;
//
//	//				//case WIIUSE_READ_DATA:
//	//				//	/*
//	//				//	 *	Data we requested to read was returned.
//	//				//	 *	Take a look at wiimotes[i]->read_req
//	//				//	 *	for the data.
//	//				//	 */
//	//				//	break;
//
//	//				//case WIIUSE_NUNCHUK_INSERTED:
//	//				//	/*
//	//				//	 *	a nunchuk was inserted
//	//				//	 *	This is a good place to set any nunchuk specific
//	//				//	 *	threshold values.  By default they are the same
//	//				//	 *	as the wiimote.
//	//				//	 */
//	//				//	 //wiiuse_set_nunchuk_orient_threshold((struct nunchuk_t*)&wiimotes[i]->exp.nunchuk, 90.0f);
//	//				//	 //wiiuse_set_nunchuk_accel_threshold((struct nunchuk_t*)&wiimotes[i]->exp.nunchuk, 100);
//	//				//	;//printf("Nunchuk inserted.\n");
//	//				//	break;
//
//	//				//case WIIUSE_CLASSIC_CTRL_INSERTED:
//	//				//	;//printf("Classic controller inserted.\n");
//	//				//	break;
//
//	//				//case WIIUSE_GUITAR_HERO_3_CTRL_INSERTED:
//	//				//	/* some expansion was inserted */
//	//				//	handle_ctrl_status(wiimotes[i]);
//	//				//	;//printf("Guitar Hero 3 controller inserted.\n");
//	//				//	break;
//
//	//				//case WIIUSE_NUNCHUK_REMOVED:
//	//				//case WIIUSE_CLASSIC_CTRL_REMOVED:
//	//				//case WIIUSE_GUITAR_HERO_3_CTRL_REMOVED:
//	//				//	/* some expansion was removed */
//	//				//	handle_ctrl_status(wiimotes[i]);
//	//				//	;//printf("An expansion was removed.\n");
//	//				//	break;
//
//	//				default:
//	//					break;
//	//			}
//	//		}
//	//	}
//	//}
//
//
//	/*
//	 *	Disconnect the wiimotes
//	 */
//	wiiuse_cleanup(wiimotes, MAX_WIIMOTES);
//
//	return 0;
//}
