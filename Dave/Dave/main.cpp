#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include "object.h"
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>

//GLOBAL VARIABLES
const int WIDTH = 1200;
const int HEIGHT = 650;



int main(void)
{
	//primitive variable
	bool done = false;

	//object variables
	Dave man;
	TextAppearance topbottomfont;

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
	
	
	//Clear screen to a black
	al_clear_to_color(al_map_rgb(0, 0, 0));

	topbottomfont.displayFont(WIDTH);


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

