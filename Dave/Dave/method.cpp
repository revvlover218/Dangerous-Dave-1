#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include "object.h"
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>

void Dave::InitDave(Dave &man)
{
	man.x = 50;
	man.y = 600;
	man.ID = PLAYER;
	man.boundy = 7;
	man.lives = 3;
	man.score = 0;
	man.boundx = 6;



}

void Dave::DrawDave(Dave &man)
{
	al_draw_filled_rectangle(man.x, man.y - 90, man.x + 20, man.y - 70, al_map_rgb(0, 0, 255));
	al_draw_filled_rectangle(man.x - 10, man.y - 70, man.x + 30, man.y - 50, al_map_rgb(0, 0, 255));
	al_draw_filled_rectangle(man.x, man.y - 50, man.x + 5, man.y - 20, al_map_rgb(0, 0, 255));
	al_draw_filled_rectangle(man.x + 20, man.y - 50, man.x + 15, man.y - 20, al_map_rgb(0, 0, 255));

}

void TextAppearance::displayFont(const int &WIDTH)
{
	ALLEGRO_FONT *font24 = al_load_font("BAUHS93.TTF", 24, 0);
	al_draw_text(font24, al_map_rgb(0, 255, 0), 10, 5, 0, "Score:");
	al_draw_text(font24, al_map_rgb(0, 255, 0), 410, 5, 0, "Level ");
	al_draw_text(font24, al_map_rgb(0, 255, 0), 810, 5, 0, "Daves:");
	al_draw_text(font24, al_map_rgb(0, 255, 0), 10, 550, 0, "JetPack");
	al_draw_text(font24, al_map_rgb(0, 255, 0), 810, 550, 0, "Gun");
	al_draw_text(font24, al_map_rgb(0, 255, 0), WIDTH / 2, 600, ALLEGRO_ALIGN_CENTER, "!!Go Thru The Door!!");
	al_flip_display();
	al_rest(5.0);
}