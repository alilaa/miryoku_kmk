U_HASH Copyright 2022 Manna Harbour
U_HASH github.com/manna-harbour/miryoku
U_HASH generated

#include "miryoku.h"

#if defined (KMK_KEYBOARD_COWBELL)
print("Starting")

import board

from kmk.kmk_keyboard import KMKKeyboard, UnicodeMode
from kmk.scanners import DiodeOrientation
from kmk.modules.split import Split, SplitSide, SplitType

keyboard = KMKKeyboard()
keyboard.debug_enabled = True

split = Split(
    split_flip=False,  # If both halves are the same, but flipped, set this True
    split_side=None,  # Sets if this is to SplitSide.LEFT or SplitSide.RIGHT, or use EE hands
    split_type=SplitType.UART,  # Defaults to UART
    split_target_left=True,  # Assumes that left will be the one on USB. Set to False if it will be the right
    uart_interval=20,  # Sets the uarts delay. Lower numbers draw more power
    data_pin=board.GP17,  # The primary data pin to talk to the secondary device with
    data_pin2=board.GP16,  # Second uart pin to allow 2 way communication
    uart_flip=False,  # Reverses the RX and TX pins if both are provided
    use_pio=False,  # Use RP2040 PIO implementation of UART. Required if you want to use other pins than RX/TX
)
keyboard.modules.append(split)

keyboard.col_pins = (board.GP5, board.GP4, board.GP3, board.GP2, board.GP1, board.GP0)
keyboard.row_pins = (board.GP11, board.GP10, board.GP9, board.GP8, board.GP7, board.GP6)
keyboard.diode_orientation = DiodeOrientation.COL2ROW
#else
from kb import KMKKeyboard; keyboard = KMKKeyboard(KMK_KCP)
#endif
from kmk.keys import KC
from kmk.modules.layers import Layers; keyboard.modules.append(Layers())
from kmk.modules.modtap import ModTap; keyboard.modules.append(ModTap())
from kmk.modules.mouse_keys import MouseKeys; keyboard.modules.append(MouseKeys())
from kmk.modules.power import Power; keyboard.modules.append(Power())
from kmk.modules.tapdance import TapDance; keyboard.modules.append(TapDance())
from kmk.extensions.media_keys import MediaKeys; keyboard.extensions.append(MediaKeys())
from kmk.modules.capsword import CapsWord; keyboard.modules.append(CapsWord()) // must come after modtap

#if defined (KMK_RGB_RGB)
U_HASH from kmk.extensions.RGB import RGB; keyboard.extensions.append(RGB(pixel_pin=EDIT, num_pixels=EDIT))
#elif defined (KMK_RGB_PEG)
U_HASH from kmk.extensions.peg_rgb_matrix import Rgb_matrix,Rgb_matrix_data,Color; keyboard.extensions.append(Rgb_matrix(EDIT))
#elif defined (KMK_RGB_LED)
U_HASH from kmk.extensions.LED import LED; keyboard.extensions.append(LED(EDIT))
#endif

U_LF

keyboard.keymap = [
#define MIRYOKU_X(LAYER, STRING) \
U_HASH LAYER U_LF \
[ U_LF \
U_MACRO_VA_ARGS(U_MACRO_EXPAND(MIRYOKU_LAYERMAPPING_##LAYER), MIRYOKU_LAYER_##LAYER)\
], U_LF
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
] U_LF

layer_names_list = [
#define MIRYOKU_X(LAYER, STRING) \
STRING,
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
] U_LF

if __name__ == '__main__':
     print('starting Miryoku KMK')
     keyboard.go()
