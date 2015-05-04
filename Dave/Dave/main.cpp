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
	TextAppearance topbottomfont;
	Walls wall;

	//Allegro variables
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;

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
	al_install_keyboard();

	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	
	//Pointers
	
	
	//Clear screen to a black
	al_clear_to_color(al_map_rgb(0, 0, 0));

	topbottomfont.displayFont(WIDTH, HEIGHT);
	wall.topBottom(WIDTH, HEIGHT);

	man.InitDave(man);

	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
				man.MoveDave(10, 0, 0, 0, man); //UP, DOWN, LEFT, RIGHT
				break;
			case ALLEGRO_KEY_DOWN:
				man.MoveDave(0, 10, 0, 0, man); //UP, DOWN, LEFT, RIGHT
				break;
			case ALLEGRO_KEY_LEFT:
				man.MoveDave(0, 0, 10, 0, man); //UP, DOWN, LEFT, RIGHT
				break;
			case ALLEGRO_KEY_RIGHT:
				man.MoveDave(0, 0, 0, 10, man); //UP, DOWN, LEFT, RIGHT
				break;
			}

		}

		man.DrawDave(man);
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));

	}


	//Destroying

	al_destroy_display(display);						//destroy our display object

	return 0;
}

