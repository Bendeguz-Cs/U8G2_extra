/*
  u8g2_extra.cpp - extension for u8g2 library with.
  Created by Csermendy Bendeguz, April 26, 2025.
  MIT license
*/

#include "Arduino.h"
#include "u8g2_extra.h"

u8g2_extra::u8g2_extra() {
  
}

void u8g2_extra::begin() {
  
}

void u8g2_extra::menu(int ) {
  u8g2.clearBuffer();
  u8g2.setFontMode(1);
  u8g2.setBitmapMode(1);
  
  //calculate next and previous items if the selected item goes behind the threshold
  if (encoderval < 0) {
    item_selected = NUM_ITEMS - 1;
    encoder.setPosition(item_selected);
  } else if (encoderval >= NUM_ITEMS) {
    item_selected = 0;
    encoder.setPosition(item_selected);
  } else {
    item_selected = encoderval;
  }

  //calculate the previous item
  item_sel_prev = item_selected - 1;
  if (item_selected == 0) {
    item_sel_prev = NUM_ITEMS - 1;
  }
  //calculate the next item
  item_sel_next = item_selected + 1;
  if (item_selected == NUM_ITEMS - 1) {
    item_sel_next = 0;
  }

  //draw the selector in the middle of the screen
  u8g2.drawXBM(1, 22, 123, 21, image_Selector_bits);

  //draw the scroll bar
  u8g2.drawXBM(126, 1, 1, 61, image_Scroll_bar_bits);
  //draw the scroll bar handle
  u8g2.drawBox(125, map(item_selected, 0, NUM_ITEMS - 1, 0, 58), 3, 6);
  
  //set the font
  u8g2.setFont(u8g2_font_6x13_tr);

  //print selected item
  u8g2.drawStr(24, 36, menu_items[item_selected]);
  //u8g2.drawXBM(6, 25, 11, 14, icons[item_selected]);

  //print previous item
  u8g2.drawStr(24, 14, menu_items[item_sel_prev]);

  //print next item
  u8g2.drawStr(24, 58, menu_items[item_sel_next]);

  u8g2.sendBuffer();
}
