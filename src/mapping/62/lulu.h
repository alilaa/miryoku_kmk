// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

#if !defined (MIRYOKU_LAYOUTMAPPING_COWBELL)

#define XXX KC.NO

#define MIRYOKU_LAYOUTMAPPING_COWBELL( \
     K00, K01, K02, K03, K04,                          K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,                          K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,                          K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,                          K35, K36, K37, N38, N39 \
) \
KC.ESC, KC.N1, KC.N2, KC.N3, KC.N4, KC.N5,        KC.N6, KC.N7, KC.N8, KC.N9, KC.N0, KC.BSPC, \
KC.TAB, K00, K01, K02, K03, K04,                  K05, K06, K07, K08, K09, KC.LBRC, \
KC.LSFT, K10, K11, K12, K13, K14,                 K15, K16, K17, K18, K19, KC.QUOT, \
KC.LCTL, K20, K21, K22, K23, K24,                 K25, K26, K27, K28, K29, KC.MINS, \
XXX, XXX, XXX, XXX, K32, XXX,                     XXX, K37, XXX, XXX, XXX, XXX, \
XXX, XXX, XXX, XXX, K33, K34,                     K35, K36, XXX, XXX, XXX, XXX

#endif

#define MIRYOKU_MAPPING MIRYOKU_LAYOUTMAPPING_COWBELL
