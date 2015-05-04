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
	bool keys[4] = { false, false, false, false };



	//object variables
	Dave man;
	Level lvl; // text on top and bottom of screen 



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
	al_register_event_source(event_queue, al_get_display_event_source(display));
	
	
	
	//Pointers
	
	

	
	al_clear_to_color(al_map_rgb(0, 0, 0)); //Clear screen to a black




	lvl.displayFont(WIDTH, HEIGHT);
	lvl.walls(WIDTH, HEIGHT);




	man.InitDave(man);



	while (!done)
	{

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) //checks to see if a key is pressed
		{

			switch (ev.keyboard.keycode)
			{

			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;
			}

		}

		else if (ev.type == ALLEGRO_EVENT_KEY_UP) //checks to see if a key is released
		{

			switch (ev.keyboard.keycode)
			{
			
			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}

		if (keys[UP] == true) man.MoveDave(10, 0, 0, 0, man); //UP
		if (keys[DOWN] == true) man.MoveDave(0, 10, 0, 0, man); //DOWN
		if (keys[LEFT] == true) man.MoveDave(0, 0, 10, 0, man); //LEFT
		if (keys[RIGHT] == true) man.MoveDave(0, 0, 0, 10, man); //RIGHT

		man.DrawDave(man);
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}



	//Destroying
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);						//destroy our display object

	return 0;
}

