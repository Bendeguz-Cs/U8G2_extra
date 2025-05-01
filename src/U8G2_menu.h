/*
  u8g2_menu.h - //short description\\.
  Created by Csermendy Bendeguz, //MONTH DAY, YEAR\\.
  MIT license
*/

#ifndef u8g2_menu_h
#define u8g2_menu_h

#include "Arduino.h"

class u8g2_menu
{
  public:
    u8g2_menu();
    void begin();
    void menu(int NUM_ITEMS, char MENU_ITEMS, int position);
  private:
    _item_selected = 0;
    _item_sel_next = 0;
    _item_sel_prev = 0;
    _position = 0;
    _NUM_ITEMS = 0;
};

#endif

