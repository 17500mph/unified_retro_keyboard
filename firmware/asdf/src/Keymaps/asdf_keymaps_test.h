// -*- mode: C; tab-width: 4 ; indent-tabs-mode: nil -*-
//
//  Unfified Keyboard Project
//  ASDF keyboard firmware
//
//  asdf_keymaps.h
//
// Copyright 2019 David Fenyes
//
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free Software
// Foundation, either version 3 of the License, or (at your option) any later
// version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
// details.
//
// You should have received a copy of the GNU General Public License along with
// this program. If not, see <https://www.gnu.org/licenses/>.

// While there is nothing preventing a standard keyboard from having both a
// "Shift Lock" key and a "Caps Lock" key, usually only one will be present. For
// testing, both must be present to test their functionality.

#if !defined(ASDF_KEYMAPS_H)
#define ASDF_KEYMAPS_H

#include "asdf.h"
#include "asdf_ascii.h"
#include "asdf_modifiers.h"

#define ASCII_PLAIN_MAP                                                                            \
  {                                                                                                \
    { ACTION_CAPS, ACTION_SHIFT, ACTION_SHIFT, ACTION_NOTHING,                                  \
      ACTION_NOTHING, ASCII_ESC,    ACTION_CTRL,  ASCII_BACKSLASH },                               \
      { ACTION_NOTHING, 'p', ';', '/', ASCII_SPACE, 'z', 'a', 'q' },                               \
      { ACTION_BREAK, ASCII_COMMA, 'm', 'n', 'b', 'v', 'c', 'x' },                                 \
      { ACTION_NOTHING, 'k', 'j', 'h', 'g', 'f', 'd', 's' },                                       \
      { ACTION_CLEAR, 'i', 'u', 'y', 't', 'r', 'e', 'w' }, { ACTION_REPEAT,                        \
                                                             ACTION_HERE_IS,                       \
                                                             ACTION_SHIFT_LOCK,                    \
                                                             ASCII_CR,                             \
                                                             ASCII_LF,                             \
                                                             'o',                                  \
                                                             'l',                                  \
                                                             ASCII_PERIOD },                       \
      { ASCII_TILDE, ASCII_RT_SQUARE_BRACE, ASCII_LT_SQUARE_BRACE, '-', ':', '0', '9', '8' },      \
    {                                                                                              \
      ACTION_NOTHING, '7', '6', '5', '4', '3', '2', '1'                                            \
    }                                                                                              \
  }

#define ASCII_CAPS_MAP                                                                             \
  {                                                                                                \
    { ACTION_NOTHING, ACTION_SHIFT, ACTION_SHIFT, ACTION_NOTHING,                                  \
      ACTION_NOTHING, ASCII_ESC,    ACTION_CTRL,  ASCII_BACKSLASH },                               \
      { ACTION_NOTHING, 'P', ';', '/', ASCII_SPACE, 'Z', 'A', 'Q' },                               \
      { ACTION_BREAK, ASCII_COMMA, 'M', 'N', 'B', 'V', 'C', 'X' },                                 \
      { ACTION_NOTHING, 'K', 'J', 'H', 'G', 'F', 'D', 'S' },                                       \
      { ACTION_CLEAR, 'I', 'U', 'Y', 'T', 'R', 'E', 'W' }, { ACTION_REPEAT,                        \
                                                             ACTION_HERE_IS,                       \
                                                             ACTION_SHIFT_LOCK,                    \
                                                             ASCII_CR,                             \
                                                             ASCII_LF,                             \
                                                             'O',                                  \
                                                             'L',                                  \
                                                             ASCII_PERIOD },                       \
      { ASCII_TILDE, ASCII_RT_SQUARE_BRACE, ASCII_LT_SQUARE_BRACE, '-', ':', '0', '9', '8' },      \
    {                                                                                              \
      ACTION_NOTHING, '7', '6', '5', '4', '3', '2', '1'                                            \
    }                                                                                              \
  }

#define ASCII_SHIFT_MAP                                                                            \
  {                                                                                                \
    { ACTION_NOTHING, ACTION_SHIFT, ACTION_SHIFT, ACTION_NOTHING,                                  \
      ACTION_NOTHING, ASCII_ESC,    ACTION_CTRL,  ASCII_VERT_BAR },                                \
      { ACTION_NOTHING, 'P', '+', '?', ASCII_SPACE, 'Z', 'A', 'Q' },                               \
      { ACTION_BREAK, '>', 'M', 'N', 'B', 'V', 'C', 'X' },                                         \
      { ACTION_NOTHING, 'K', 'J', 'H', 'G', 'F', 'D', 'S' },                                       \
      { ACTION_CLEAR, 'I', 'U', 'Y', 'T', 'R', 'E', 'W' },                                         \
      { ACTION_REPEAT, ACTION_HERE_IS, ACTION_SHIFT_LOCK, ASCII_CR, ASCII_LF, 'O', 'L', '<' },     \
      { ASCII_TILDE, ASCII_RT_CURLY_BRACE, ASCII_LT_CURLY_BRACE, '=', '*',                         \
        '0',         ASCII_RT_PAREN,       ASCII_LT_PAREN },                                       \
    {                                                                                              \
      ACTION_NOTHING, ASCII_SINGLE_QUOTE, '&', '%', '$', '#', ASCII_DOUBLE_QUOTE, '!'              \
    }                                                                                              \
  }

#define ASCII_CTRL_MAP                                                                             \
  {                                                                                                \
    { ACTION_NOTHING, ACTION_SHIFT, ACTION_SHIFT, ACTION_NOTHING,                                  \
      ACTION_NOTHING, ASCII_ESC,    ACTION_CTRL,  0x1c },                                          \
      { ACTION_NOTHING, ASCII_CTRL_P, ACTION_NOTHING, ACTION_NOTHING,                              \
        ASCII_SPACE,    ASCII_CTRL_Z, ASCII_CTRL_A,   ASCII_CTRL_Q },                              \
      { ACTION_BREAK, ASCII_COMMA,  ASCII_CTRL_M, ASCII_CTRL_N,                                    \
        ASCII_CTRL_B, ASCII_CTRL_V, ASCII_CTRL_C, ASCII_CTRL_X },                                  \
      { ACTION_CLEAR, ASCII_CTRL_I, ASCII_CTRL_U, ASCII_CTRL_Y,                                    \
        ASCII_CTRL_T, ASCII_CTRL_R, ASCII_CTRL_E, ASCII_CTRL_W },                                  \
      { ACTION_REPEAT, ACTION_HERE_IS, ACTION_SHIFT_LOCK, ASCII_CR,                                \
        ASCII_LF,      ASCII_CTRL_O,   ASCII_CTRL_L,      ACTION_NOTHING },                        \
      { ACTION_NOTHING, 0x1d,        ASCII_ESC,   ACTION_NOTHING,                                  \
        ACTION_NOTHING, ACTION_FN_1, ACTION_FN_9, ACTION_FN_8 },                                   \
    {                                                                                              \
      ACTION_NOTHING, ACTION_FN_7, ACTION_FN_6, ACTION_FN_5, ACTION_FN_4, ACTION_FN_3,             \
        ACTION_FN_2, ACTION_FN_2                                                                   \
    }                                                                                              \
  }

// PROCEDURE: asdf_keymaps_init
// INPUTS: none
// OUTPUTS: none
// DESCRIPTION: Assigns the keymaps to the indices specified by the modifier
// index, to avoid hard-coding constant index values.
void asdf_keymaps_init(void);

// PROCEDURE: asdf_keymaps_get_code
// INPUTS: row, col: row and column of key that has been pressed
//         modifiers_index: index into the keymap array, based on modifier state
// OUTPUTS: returns a key code.
// DESCRIPTION: Given a key row and column, and an index based on modifier
// state, return the appropriate keycode.
asdf_keycode_t asdf_keymaps_get_code(uint8_t row, uint8_t col, uint8_t modifier_index);


#endif /* !defined (ASDF_KEYMAPS_H) */

//-------|---------|---------+---------+---------+---------+---------+---------+
// Above line is 80 columns, and should display completely in the editor.