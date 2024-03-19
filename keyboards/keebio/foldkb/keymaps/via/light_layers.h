/*
Copyright 2023 John Stegeman

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

const rgblight_segment_t PROGMEM FN_LIGHT_LAYER[] = RGBLIGHT_LAYER_SEGMENTS(
    // left side
    {0, 4, HSV_RED},
    {12, 4, HSV_RED},
    // right side
    {4, 8, HSV_RED}
);

const rgblight_segment_t* const PROGMEM MY_LIGHT_LAYERS[] = RGBLIGHT_LAYERS_LIST(
    FN_LIGHT_LAYER
);