// Copyright 2021 Manna Harbour
// https://github.com/manna-harbour/miryoku

// Base alphas: Colemak-DH (firmware-level -- keep the OS on a plain US/QWERTY
// layout so this isn't double-remapped). The Extra layer stays QWERTY for games.
#define MIRYOKU_ALPHAS_COLEMAKDH

// Clipboard left at the default ("common": Shift+Ins / Ctrl+Ins / Shift+Del),
// which works in both terminals and GUI apps on Linux (i3 / Sway).

// Mouse layer override: move the mouse buttons to the LEFT thumb cluster.
// The trackpad is on the right half, so clicking with the right thumb while the
// right hand drives the pad is cramped -- the free left thumb clicks instead.
// Only the thumb row differs from the stock Miryoku Mouse layer; it mirrors the
// right-hand original (left-click in the middle, right-click inner, middle outer).
// Keep excluded-positions in toucan.dtsi pointed at the left thumbs (36 37 38).
#define MIRYOKU_LAYER_MOUSE \
U_BOOT,    &u_to_U_TAP,  &u_to_U_EXTRA, &u_to_U_BASE,  U_NA,    U_RDO,  U_PST,  U_CPY,  U_CUT,  U_UND,  \
&kp LGUI,  &kp LALT,     &kp LCTRL,     &kp LSHFT,     U_NA,    U_NU,   U_MS_L, U_MS_D, U_MS_U, U_MS_R, \
U_NA,      &kp RALT,     &u_to_U_SYM,   &u_to_U_MOUSE, U_NA,    U_NU,   U_WH_L, U_WH_D, U_WH_U, U_WH_R, \
U_NP,      U_NP,         U_BTN3,        U_BTN1,        U_BTN2,  U_NA,   U_NA,   U_NA,   U_NP,   U_NP
