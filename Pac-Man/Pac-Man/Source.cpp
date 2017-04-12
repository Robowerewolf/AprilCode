#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_primitives.h"
using namespace std;
int main() {
	ALLEGRO_DISPLAY*display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP*Pacman = NULL;
	ALLEGRO_BITMAP*wall = NULL;

	float Pacman_x = 385;
	float Pacman_y = 565;

	int map[20][20] = {
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,
		1,0,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,0,1,
		1,0,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,0,1,
	    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	    1,0,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1,1,0,1,
	    1,0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0,0,0,1,
	    1,1,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,1,1,
	    1,1,1,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1,1,1,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		1,1,1,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1,1,1,
		1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1,1,1,1,
		1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,
		1,0,1,1,0,1,1,0,0,1,1,0,0,1,1,0,1,1,0,1,
		1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,
		1,1,0,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0,1,1,
		1,0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0,0,0,1,
		1,0,1,1,1,1,1,0,0,1,1,0,0,1,1,1,1,1,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};

	bool key[4] = { false, false, false, false };

	bool redraw = true;

	bool doexit = false;

	al_init();
	al_init_image_addon();
	al_init_primitives_addon();

	al_install_keyboard();

	timer = al_create_timer(.02);

	display = al_create_display(800, 800);

	for (int x = 0; x<20; x++)
	{
		for (int y = 0; y<20; y++)
		{
			map[x][y] = map[x][y];
		}
	}
	for (int x = 0; x<20; x++)  // loop 3 times for three lines
	{
		for (int y = 0; y<20; y++)  // loop for the three elements on the line
		{
			cout << map[x][y];  // display the current element out of the array
		}
		cout << endl;  // when the inner loop is done, go to a new line
	}



//	al_rest(3);

	Pacman = al_create_bitmap(32,32);
	al_set_target_bitmap(Pacman);
	al_clear_to_color(al_map_rgb(255, 255, 0));
	
	wall = al_create_bitmap(40, 40);
	al_set_target_bitmap(wall);
	al_clear_to_color(al_map_rgb(120, 0, 120));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);

	while (!doexit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			if (key[0] && Pacman_y >= 0 + 1) {
				Pacman_y -= 4.0;
			}

			if (key[1] && Pacman_y <= 800 - 32) {
				Pacman_y += 4.0;
			}

			if (key[2] && Pacman_x >= 0 +1) {
				Pacman_x -= 4.0;
			}

			if (key[3] && Pacman_x <= 800 - 32) {
				Pacman_x += 4.0;
			}
			redraw = true;
		}

		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {

			switch (ev.keyboard.keycode) {

			case ALLEGRO_KEY_UP:
				key[0] = true;
				break;

			case ALLEGRO_KEY_DOWN:
				key[1] = true;
				break;

			case ALLEGRO_KEY_LEFT:
				key[2] = true;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[3] = true;
				break;
			}
		}

		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[0] = false;
				break;

			case ALLEGRO_KEY_DOWN:
				key[1] = false;
				break;

			case ALLEGRO_KEY_LEFT:
				key[2] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[3] = false;
				break;

			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}
		}
		//RENDER SECTION

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));

			for (int x = 0; x<20; x++)  // loop 3 times for three lines
			{
				for (int y = 0; y<20; y++)  // loop for the three elements on the line
				{
					//check if matrix holds a "1"
					if (map[x][y] == 1)
						al_draw_bitmap(wall,y * 40, x * 40, NULL);

					//if holds a 2, draw a dot
				}
				
			}

			al_draw_bitmap(Pacman, Pacman_x, Pacman_y, 0);

			al_flip_display();
		}
	}


	al_destroy_bitmap(Pacman);
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);

	return 0;
}