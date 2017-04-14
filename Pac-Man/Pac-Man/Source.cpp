#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"

using namespace std;
int wallCollide(int x, int y, int dir, int map[20][20]);
int main() {
	ALLEGRO_DISPLAY*display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP*Pacman = NULL;
	ALLEGRO_BITMAP*wall = NULL;
	ALLEGRO_BITMAP*dot = NULL;
	ALLEGRO_FONT * font = NULL;
	ALLEGRO_SAMPLE *sample = NULL;

	int Pacman_x = 385;
	int Pacman_y = 565;

	int score = 0;

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
		0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,
		1,1,1,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1,1,1,
		1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1,1,1,1,
		1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,
		1,0,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,0,1,
		1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,
		1,1,0,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0,1,1,
		1,0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0,0,0,1,
		1,0,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, };

	bool key[4] = { false, false, false, false };

	bool redraw = true;

	bool doexit = false;

	al_init();
	al_init_image_addon();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_acodec_addon();
	al_install_audio();

	al_install_keyboard();

	font = al_load_ttf_font("robustA.ttf", 50, NULL);

	timer = al_create_timer(.02);

	display = al_create_display(800, 800);




	//    al_rest(3);
	//cout << "flag" << endl;
	//Pacman = al_create_bitmap(30, 30);
	//al_set_target_bitmap(Pacman);
	//al_clear_to_color(al_map_rgb(255, 255, 0));
	Pacman = al_load_bitmap("pacman_30x30.png");

	wall = al_create_bitmap(40, 40);
	al_set_target_bitmap(wall);
	al_clear_to_color(al_map_rgb(120, 0, 120));

	dot = al_create_bitmap(8, 8);
	al_set_target_bitmap(dot);
	al_clear_to_color(al_map_rgb(255, 255, 255));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);
	//cout << "flag" << endl;
	while (!doexit)
	{
		cout << Pacman_x << " , " << Pacman_y << endl;
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			if (key[0] && Pacman_y >= 0 + 1) {
				Pacman_y -= 4.0;
			}

			if (key[1] && Pacman_y <= 800 - 32) {
				Pacman_y += 4.0;
			}

			if (key[2] && Pacman_x >= 0 + 1) {
				Pacman_x -= 4.0;
			}

			if (key[3] && Pacman_x <= 800 - 32) {
				Pacman_x += 4.0;
			}

	    if(Pacman_x > -7 && Pacman_x < 1 && Pacman_y > 333 && Pacman_y < 377){
			Pacman_x = 769;
		  Pacman_y = 365;
		}
		else if (Pacman_x > 765 && Pacman_x < 773 && Pacman_y > 333 && Pacman_y < 377) {
			Pacman_x = 1;
			Pacman_y = 365;
		}
			//eating dots!
			if (map[(Pacman_y + 20) / 40][(Pacman_x + 20) / 40] == 0) {
				map[(Pacman_y + 20) / 40][(Pacman_x + 20) / 40] = 4; //4s are blank spots
				sample = al_load_sample("wakka.wav");												 //sound effect here
				score++;													 //up score here
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
						al_draw_bitmap(wall, y * 40, x * 40, NULL);
					if (map[x][y] == 0)
						al_draw_bitmap(dot, y * 40 + 20, x * 40 + 20, NULL);


					//    if ((map[x][y] == 0) && ()
					//if holds a 2, draw a dot
				}
			}
			al_draw_textf(font, al_map_rgb(20, 20, 255), 450, 1, ALLEGRO_ALIGN_CENTRE, "score = %i", score);

			al_draw_bitmap(Pacman, Pacman_x, Pacman_y, 0);
			al_flip_display();
		}
	}


	al_destroy_bitmap(Pacman);
	al_destroy_display(display);
	al_destroy_bitmap(wall);
	al_destroy_bitmap(dot);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);

	return 0;
}
//int wallCollide(int x, int y, int dir, int level[20][20]) {

//}
