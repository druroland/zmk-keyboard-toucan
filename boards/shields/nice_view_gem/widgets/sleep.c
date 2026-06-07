#include <zephyr/kernel.h>
#include <stdio.h>
#include <string.h>

#include "sleep.h"
#include "../assets/custom_fonts.h"

// Sleep image lives in assets/sleep_logo.c so the art can be swapped without
// touching this logic. Regenerate that file from any image with:
//   python3 assets/img2lvgl.py YOURIMG.png sleep_logo -W 96 -H 96 > assets/sleep_logo.c
// Any size works -- it is centered horizontally below.
LV_IMG_DECLARE(sleep_logo);

static bool show_sleep_screen = false;

bool is_sleep_screen_active(void) {
    return show_sleep_screen;
}

void set_sleep_screen_active(bool active) {
    show_sleep_screen = active;
}

void draw_sleep_screen(lv_obj_t *canvas) {
    // Center the image horizontally on the SCREEN_WIDTH-wide canvas, near the top.
    lv_draw_img_dsc_t img_dsc;
    lv_draw_img_dsc_init(&img_dsc);
    lv_coord_t x = (SCREEN_WIDTH - sleep_logo.header.w) / 2;
    if (x < 0) {
        x = 0;
    }
    lv_canvas_draw_img(canvas, x, 32, &sleep_logo, &img_dsc);

    // Show "SLEEP" in small text below the icon
    lv_draw_label_dsc_t label_dsc;
    init_label_dsc(&label_dsc, LVGL_FOREGROUND, &quinquefive_8, LV_TEXT_ALIGN_LEFT);
    lv_canvas_draw_text(canvas, 12, 140, SCREEN_WIDTH - 8, &label_dsc, "SLEEP");
}
