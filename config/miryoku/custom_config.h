// Copyright 2021 Manna Harbour
// https://github.com/manna-harbour/miryoku

// Base alphas: Colemak-DH (firmware-level -- keep the OS on a plain US/QWERTY
// layout so this isn't double-remapped). The Extra layer stays QWERTY for games.
#define MIRYOKU_ALPHAS_COLEMAKDH

// --- Positional home-row mods (opposite-hands rule) ------------------------
// ZMK equivalent of QMK's Chordal Hold. A home-row mod only resolves as a hold
// when chorded with a key on the OPPOSITE hand (or a thumb); same-hand rolls
// resolve as taps. The hml/hmr behaviors live in custom_behaviors.dtsi.
//
// Positions use the 42-key Corne/Toucan binding order (identical for both
// boards): outer pinky columns are &none, so the live keys are
//   left alphas 1-5 13-17 25-29, right alphas 6-10 18-22 30-34,
//   thumbs 36 37 38 (left) 39 40 41 (right).
// Left mods (hml) trigger on the RIGHT hand + all thumbs; right mods (hmr) on
// the LEFT hand + all thumbs (thumbs in both, mirroring QMK's thumb exclusion).
#define U_HML_TRIGGERS 6 7 8 9 10 18 19 20 21 22 30 31 32 33 34 36 37 38 39 40 41
#define U_HMR_TRIGGERS 1 2 3 4 5 13 14 15 16 17 25 26 27 28 29 36 37 38 39 40 41

// Base layer = stock COLEMAKDH base, with every alpha mod-tap rebound from the
// global &u_mt to per-hand &hml/&hmr (home row A/R/S/T + N/E/I/O, plus the
// bottom-row AltGr mod-taps X and . ). Layer-taps (thumbs, Z, /) stay on u_lt
// for instant layer access. Keep in sync with the engine's COLEMAKDH base in
// miryoku_babel/miryoku_layer_alternatives.h if the engine is ever updated.
#define MIRYOKU_LAYER_BASE \
&kp Q,             &kp W,             &kp F,             &kp P,             &kp B,             &kp J,             &kp L,             &kp U,             &kp Y,             &kp SQT,           \
&hml LGUI A,       &hml LALT R,       &hml LCTRL S,      &hml LSHFT T,      &kp G,             &kp M,             &hmr LSHFT N,      &hmr LCTRL E,      &hmr LALT I,       &hmr LGUI O,       \
U_LT(U_BUTTON, Z), &hml RALT X,       &kp C,             &kp D,             &kp V,             &kp K,             &kp H,             &kp COMMA,         &hmr RALT DOT,     U_LT(U_BUTTON, SLASH),\
U_NP,              U_NP,              U_LT(U_MEDIA, ESC),U_LT(U_NAV, SPACE),U_LT(U_MOUSE, TAB),U_LT(U_SYM, RET),  U_LT(U_NUM, BSPC), U_LT(U_FUN, DEL),  U_NP,              U_NP

// Clipboard left at the default ("common": Shift+Ins / Ctrl+Ins / Shift+Del),
// which works in both terminals and GUI apps on Linux (i3 / Sway).

// Mouse layer override: move the mouse buttons to the LEFT thumb cluster.
// The trackpad is on the right half, so clicking with the right thumb while the
// right hand drives the pad is cramped -- the free left thumb clicks instead.
// Only the thumb row differs from the stock Miryoku Mouse layer; it mirrors the
// right-hand original (left-click in the middle, right-click inner, middle outer).
// Keep excluded-positions in toucan.dtsi pointed at the left thumbs (36 37 38).
// Guarded to the Toucan only (U_TOUCAN, set in toucan.keymap): the PocketCorne
// has no trackpad, so it falls back to the stock Miryoku Mouse layer.
#if defined(U_TOUCAN)
#define MIRYOKU_LAYER_MOUSE \
U_BOOT,    &u_to_U_TAP,  &u_to_U_EXTRA, &u_to_U_BASE,  U_NA,    U_RDO,  U_PST,  U_CPY,  U_CUT,  U_UND,  \
&kp LGUI,  &kp LALT,     &kp LCTRL,     &kp LSHFT,     U_NA,    U_NU,   U_MS_L, U_MS_D, U_MS_U, U_MS_R, \
U_NA,      &kp RALT,     &u_to_U_SYM,   &u_to_U_MOUSE, U_NA,    U_NU,   U_WH_L, U_WH_D, U_WH_U, U_WH_R, \
U_NP,      U_NP,         U_BTN3,        U_BTN1,        U_BTN2,  U_NA,   U_NA,   U_NA,   U_NP,   U_NP
#endif
