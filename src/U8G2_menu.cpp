/*
  u8g2_menu.cpp - extension for u8g2 library with.
  Created by Csermendy Bendeguz, April 26, 2025.
  MIT license
*/

#include "Arduino.h"
#include "U8G2_menu.h"

u8g2_menu::u8g2_menu() {
  
}

void u8g2_menu::begin() {
  
}

void u8g2_menu::menu(int NUM_ITEMS, char MENU_ITEMS, int position) {
  _NUM_ITEMS = NUM_ITEMS;
  _position = position;
  u8g2.setFontMode(1);
  u8g2.setBitmapMode(1);
  
  //calculate next and previous items if the selected item goes behind the threshold
  if (_position < 0) {
    _item_selected = _NUM_ITEMS - 1;
    _position = item_selected;
  } else if (_position >= _NUM_ITEMS) {
    _item_selected = 0;
    _position = item_selected;
  } else {
    _item_selected = _position;
  }

  //calculate the previous item
  _item_sel_prev = _item_selected - 1;
  if (_item_selected == 0) {
    _item_sel_prev = _NUM_ITEMS - 1;
  }
  //calculate the next item
  _item_sel_next = _item_selected + 1;
  if (_item_selected == _NUM_ITEMS - 1) {
    _item_sel_next = 0;
  }

  //draw the selector in the middle of the screen
  u8g2.drawXBM(1, 22, 123, 21, image_Selector_bits);

  //draw the scroll bar
  u8g2.drawXBM(126, 1, 1, 61, image_Scroll_bar_bits);
  //draw the scroll bar handle
  u8g2.drawBox(125, map(_item_selected, 0, _NUM_ITEMS - 1, 0, 58), 3, 6);
  
  //set the font
  u8g2.setFont(u8g2_font_6x13_tr);

  //print selected item
  u8g2.drawStr(24, 36, menu_items[_item_selected]);
  //u8g2.drawXBM(6, 25, 11, 14, icons[_item_selected]);

  //print previous item
  u8g2.drawStr(24, 14, menu_items[_item_sel_prev]);

  //print next item
  u8g2.drawStr(24, 58, menu_items[_item_sel_next]);
}
