// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// Mapping for the beekeeb Toucan 36 (3x5 + 3 thumbs per hand = 36 keys).
//
// beekeeb ships one firmware for the Toucan line; its matrix-transform scans a
// 6-columns-per-hand (42-key) superset whose binding order is identical to the
// Corne: row0 12, row1 12, row2 12, thumbs 6. On the Toucan 36 the outer pinky
// column (matrix columns 0 and 11) carries no switches -- it is the Piantor->Cantor
// column that the 36-key variant removes. Those positions are therefore &none,
// which is exactly the orthodox 36-key Miryoku layout: all alphas land on the
// inner 5 columns per hand and the 3 thumbs per hand.

#if !defined (MIRYOKU_LAYOUTMAPPING_TOUCAN)

#define XXX &none

#define MIRYOKU_LAYOUTMAPPING_TOUCAN( \
     K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,      K35, K36, K37, N38, N39 \
) \
XXX  K00  K01  K02  K03  K04       K05  K06  K07  K08  K09  XXX \
XXX  K10  K11  K12  K13  K14       K15  K16  K17  K18  K19  XXX \
XXX  K20  K21  K22  K23  K24       K25  K26  K27  K28  K29  XXX \
               K32  K33  K34       K35  K36  K37

#define MIRYOKU_KLUDGE_TOPROWCOMBOS_LEFTPINKIE 2 3
#define MIRYOKU_KLUDGE_TOPROWCOMBOS_LEFTINNERINDEX 3 4
#define MIRYOKU_KLUDGE_TOPROWCOMBOS_RIGHTINNERINDEX 7 8
#define MIRYOKU_KLUDGE_TOPROWCOMBOS_RIGHTPINKIE 8 9

#define MIRYOKU_KLUDGE_BOTTOMROWCOMBOS_LEFTPINKIE 26 27
#define MIRYOKU_KLUDGE_BOTTOMROWCOMBOS_LEFTINNERINDEX 27 28
#define MIRYOKU_KLUDGE_BOTTOMROWCOMBOS_RIGHTINNERINDEX 31 32
#define MIRYOKU_KLUDGE_BOTTOMROWCOMBOS_RIGHTPINKIE 32 33

#define MIRYOKU_KLUDGE_THUMBCOMBOS_LEFT 37 38
#define MIRYOKU_KLUDGE_THUMBCOMBOS_RIGHT 39 40


#endif

#define MIRYOKU_MAPPING MIRYOKU_LAYOUTMAPPING_TOUCAN
