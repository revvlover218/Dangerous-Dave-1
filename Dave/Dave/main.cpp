#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include "object.h"

//GLOBAL VARIABLES
const int WIDTH = 1200;
const int HEIGHT = 720;

//prototypes
void InitDave(Dave &man);
void DrawDave(Dave &man);

int main(void)
{
	//primitive variable
	bool done = false;

	//object variables
	Dave man;

	//Allegro variables
	ALLEGRO_DISPLAY *display = NULL;

	//Initialization Functions
	if (!al_init())										//initialize Allegro
		return -1;

	display = al_create_display(WIDTH, HEIGHT);			//create our display object

	if (!display)										//test display object
		return -1;

	al_init_primitives_addon();
	InitDave(man);

	while (!done)
	{
		DrawDave(man);

		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	al_destroy_display(display);						//destroy our display object

	return 0;
}

void InitDave(Dave &man)
{
	man.x = 50;
	man.y = 720;
	man.ID = PLAYER;
	man.boundy = 7;
	man.lives = 3;
	man.score = 0;
	man.boundx = 6;



}

void DrawDave(Dave &man)
{
	al_draw_filled_rectangle(man.x, man.y - 90, man.x + 20, man.y - 70, al_map_rgb(0, 0, 255));
	al_draw_filled_rectangle(man.x - 10, man.y - 70, man.x + 30, man.y - 50, al_map_rgb(0, 0, 255));
	al_draw_filled_rectangle(man.x, man.y - 50, man.x + 5, man.y - 20, al_map_rgb(0, 0, 255));
	al_draw_filled_rectangle(man.x + 20, man.y - 50, man.x + 15, man.y - 20, al_map_rgb(0, 0, 255));

}