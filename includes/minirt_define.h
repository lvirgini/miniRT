/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_define.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 18:34:22 by lvirgini          #+#    #+#             */
/*   Updated: 2020/08/18 11:37:30 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DEFINE_H
# define MINIRT_DEFINE_H

/*
** Divers utils
*/

# define PI  		3.14159265359
# define SUCCESS 	0 // a voir pour utilisation
# define FAILURE 	1
# define RES_X_MAX 	2000 //
# define RES_Y_MAX 	2000 //
# define uchar	unsigned char

/*
** RAY_T_MIN : pour eviter que le rayon s'intersecte lui-même
** RAY_T_MAX : pour donner une limite de l'infini
** MAX_REBOUND : rebond maximum de rayon  récursif (find mirroir color)
*/

# define RAY_T_MIN		0.001f
# define RAY_T_MAX		1.0e30f //1e99
# define MAX_REBOUND	10

/*
** EVENT MLX 
*/

# define KEYPRESS 2
# define KEYRELEASE 3
# define BUTTONPRESS 4
# define BUTTONRELEASE 5
# define MOTIONNOTIFY 6
# define ENTERNOTIFY 7
# define LEAVENOTIFY 8
# define FOCUSIN 9
# define FOCUSOUT 10
# define KEYMAPNOTIFY 11
# define EXPOSE 12
# define GRAPHICSEXPOSE 13
# define NOEXPOSE 14
# define VISIBILITYNOTIFY 15
# define CREATENOTIFY 16
# define DESTROYNOTIFY 17
# define UNMAPNOTIFY 18
# define MAPNOTIFY 19
# define MAPREQUEST 20
# define REPARENTNOTIFY 21
# define CONFIGURENOTIFY 22
# define CONFIGUREREQUEST 23
# define GRAVITYNOTIFY 24

/*
** KEYCODE LINUX
*/

/*
** keycodes numbers HIGHT
*/

# define KEY_1				2
# define KEY_2				3
# define KEY_3				4
# define KEY_4				5
# define KEY_5				6
# define KEY_6				7
# define KEY_7				8
# define KEY_8				9
# define KEY_9				10
# define KEY_0				11

/*
** keycodes numbers pad numbers

# define KEY_1				79
# define KEY_2				80
# define KEY_3				81
# define KEY_4				75
# define KEY_5				76
# define KEY_6				77
# define KEY_7				71
# define KEY_8				72
# define KEY_9				73
# define KEY_0				82
*/

/*
** keycodes lettres				 AZERTY /!\
*/

# define KEY_A				16
# define KEY_B				98		//48
# define KEY_C				46
# define KEY_D				32
# define KEY_E				18
# define KEY_F				33
# define KEY_G				103		//34
# define KEY_H				35
# define KEY_I				23
# define KEY_J				36
# define KEY_K				37
# define KEY_L				38
# define KEY_M				39
# define KEY_N				49
# define KEY_O				24
# define KEY_P				25
# define KEY_Q				30
# define KEY_R				114		//19
# define KEY_S				31
# define KEY_T				20
# define KEY_U				22
# define KEY_V				47
# define KEY_W				44
# define KEY_X				45
# define KEY_Y				21
# define KEY_Z				17


# define KEY_ESC			65307 	//1
# define KEY_SPACE			32		//57
# define KEY_ENTER			65293  // 28

//
/* NOT USED //
#define KEY_RESERVED		0
#define KEY_MINUS			12
#define KEY_EQUAL			13
#define KEY_BACKSPACE		14
#define KEY_TAB				15

#define KEY_LEFTBRACE		26
#define KEY_RIGHTBRACE		27
#define KEY_LEFTCTRL		29

#define KEY_APOSTROPHE		40
#define KEY_GRAVE			41
#define KEY_LEFTSHIFT		42
#define KEY_BACKSLASH		43

#define KEY_COMMA			51
#define KEY_DOT				52
#define KEY_SLASH			53
#define KEY_RIGHTSHIFT		54
#define KEY_KPASTERISK		55
#define KEY_LEFTALT			56

#define KEY_CAPSLOCK		58
#define KEY_F1				59
#define KEY_F2				60
#define KEY_F3				61
#define KEY_F4				62
#define KEY_F5				63
#define KEY_F6				64
#define KEY_F7				65
#define KEY_F8				66
#define KEY_F9				67
#define KEY_F10				68
#define KEY_NUMLOCK			69
#define KEY_SCROLLLOCK		70
#define KEY_KP7				71
#define KEY_KP8				72
#define KEY_KP9				73
#define KEY_KPMINUS			74
#define KEY_KP4				75
#define KEY_KP5				76
#define KEY_KP6				77
#define KEY_KPPLUS			78
#define KEY_KP1				79
#define KEY_KP2				80
#define KEY_KP3				81
#define KEY_KP0				82
#define KEY_KPDOT			83

#define KEY_ZENKAKUHANKAKU	85
#define KEY_102ND			86
#define KEY_F11				87
#define KEY_F12				88
#define KEY_RO				89
#define KEY_KATAKANA		90
#define KEY_HIRAGANA		91
#define KEY_HENKAN			92
#define KEY_KATAKANAHIRAGANA	93
#define KEY_MUHENKAN		94
#define KEY_KPJPCOMMA		95
#define KEY_KPENTER			96
#define KEY_RIGHTCTRL		97
#define KEY_KPSLASH			98
#define KEY_SYSRQ			99
#define KEY_RIGHTALT		100
#define KEY_LINEFEED		101
#define KEY_HOME			102
#define KEY_UP				103
#define KEY_PAGEUP			104
#define KEY_LEFT			105
#define KEY_RIGHT			106
#define KEY_END				107
#define KEY_DOWN			108
#define KEY_PAGEDOWN		109
#define KEY_INSERT			110
#define KEY_DELETE			111
#define KEY_MACRO			112
#define KEY_MUTE			113
#define KEY_VOLUMEDOWN		114
#define KEY_VOLUMEUP		115
#define KEY_POWER			116	*//* SC System Power Down */

/*
#define KEY_F13				183
#define KEY_F14				184
#define KEY_F15				185
#define KEY_F16				186
#define KEY_F17				187
#define KEY_F18				188
#define KEY_F19				189
#define KEY_F20				190
#define KEY_F21				191
#define KEY_F22				192
#define KEY_F23				193
#define KEY_F24				194

#define KEY_FN				0x1d0
#define KEY_FN_ESC			0x1d1
#define KEY_FN_F1			0x1d2
#define KEY_FN_F2			0x1d3
#define KEY_FN_F3			0x1d4
#define KEY_FN_F4			0x1d5
#define KEY_FN_F5			0x1d6
#define KEY_FN_F6			0x1d7
#define KEY_FN_F7			0x1d8
#define KEY_FN_F8			0x1d9
#define KEY_FN_F9			0x1da
#define KEY_FN_F10			0x1db
#define KEY_FN_F11			0x1dc
#define KEY_FN_F12			0x1dd
*/

#endif
