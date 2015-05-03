#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include "object.h"
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>

//GLOBAL VARIABLES
const int WIDTH = 1200;
const int HEIGHT = 700;



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
	//Initialization
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	
	//Pointers
	ALLEGRO_FONT *font24 = al_load_font("BAUHS93.TTF", 24, 0);
	
	//Clear screen to a black
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_draw_text(font24, al_map_rgb(0, 255, 0), 10, 5, 0, "Score:" );
	al_flip_display();

	al_rest(5.0);

	man.InitDave(man);

	while (!done)
	{
		man.DrawDave(man);

		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}





	//Destroying

	al_destroy_display(display);						//destroy our display object

	return 0;
}

