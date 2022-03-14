// Copyright 2022 antoniotrkdz (@antoniotrkdz)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define KEYMAP( \
	K00, K01, K02, K03, K04, K05, K06, K07,      \
	K10, K11, K12, K13, K14, K15, K16, K17,      \
	K20, K21, K22, K23, K24, K25, K26, K27,      \
	K30, K31, K32, K33, K34, K35, K36, K37,      \
	K40, K41, K42, K43, K44, K45, K46, K47,      \
	K50, K51, K52, K53, K54,      K56, K57  \
) { \
	{ K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07 }, \
	{ K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17 }, \
	{ K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27 }, \
	{ K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37 }, \
	{ K40,   K41,   K42,   K43,   K44,   K45,   K46,   K47 }, \
	{ K50,   K51,   K52,   K53,   K54,   KC_NO, K56,   K57 }  \
}
