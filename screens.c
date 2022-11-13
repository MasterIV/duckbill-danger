#include <gb/gb.h>
#include "game_over_tiles.tiles"
#include "game_over_screen.map"
#include "title_tiles.tiles"
#include "title_screen.map"
#include "win_tiles.tiles"
#include "win_screen.map"

void show_title() {
	HIDE_SPRITES;
    DISPLAY_OFF;
  	set_bkg_data(0, 200, title_tiles);
  	set_bkg_tiles(0, 0, 20, 18, title_screen);
    DISPLAY_ON;
}

void show_defeat() {
	HIDE_SPRITES;
    DISPLAY_OFF;
  	set_bkg_data(0, 200, game_over_tiles);
  	set_bkg_tiles(0, 0, 20, 18, game_over_screen);
    DISPLAY_ON;
}

void show_win() {
	HIDE_SPRITES;
    DISPLAY_OFF;
  	set_bkg_data(0, 200, win_tiles);
  	set_bkg_tiles(0, 0, 20, 18, win_screen);
    DISPLAY_ON;
}