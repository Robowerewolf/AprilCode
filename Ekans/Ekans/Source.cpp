#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "allegro5/allegro_audio.h"
#include <Windows.h>
#include "allegro5/allegro_acodec.h"
#include <vector>

using namespace std;

int main() {
	ALLEGRO_DISPLAY*display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP*Ekans = NULL;
	ALLEGRO_BITMAP*food = NULL;
	ALLEGRO_SAMPLE*sample = NULL;
	ALLEGRO_SAMPLE_INSTANCE*instance1 = NULL;
	ALLEGRO_FONT*font = NULL;

	int Ekans_x = 5;
	int Ekans_y = 5;

	int goal_x = 4;
	int goal_y = 4;

	float CLOCK = .05;

	int SNEKSIZE = 40;

	int score = 0;

	int snekLength = 0;

	bool gotGoal = false;

	bool key[4] = { false, false, false, false };

	bool redraw = true;

	bool doexit = false;
	/////////////////////////////////////////////////////////////////////////////

	//vector
	vector<int>nodes;
	vector<int>::const_iterator iter;

	al_init();
	al_init_image_addon();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_acodec_addon();
	al_install_audio();
	al_install_keyboard();

	al_reserve_samples(2);
	sample = al_load_sample("music.wav");
	al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);

	timer = al_create_timer(CLOCK);

	display = al_create_display(800, 800);

	 int map[20][20];
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			map[i][j] = 0;

	map[goal_x][goal_y] = 2;

	srand(time(NULL));

	food = al_load_bitmap("mouse_40x40.png");

	Ekans = al_load_bitmap("eye_40x40.png");
	//al_set_target_bitmap(Ekans);
	//al_clear_to_color(al_map_rgb(255, 0, 0));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();

	al_reserve_samples(10);

	font = al_load_ttf_font("Snake.ttf", 80, 0);
	if (font == NULL)
		cout << "ooops" << endl;

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);

	al_draw_text(font, al_map_rgb(20, 20, 255), 700 /2 , 280, ALLEGRO_ALIGN_CENTRE, "Snake");

	al_flip_display();
	al_rest(1);

	while (true)
	{
		cout << Ekans_x << " , " << Ekans_y << endl;
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		
		////prints to console screen
		//for (int i = 0; i < 20; i++) {
		//	for (int j = 0; j < 20; j++)
		//		cout << map[i][j];
		//	cout << endl;
		//}
		if (ev.type == ALLEGRO_EVENT_TIMER) {

			for(int i = 0; i < 20; i++)
				for (int j = 0; j < 20; j++) {
					if (map[i][j] == 1)
						map[i][j] = 0;
				}
			//snek tail
			for (int i = 0; i < snekLength; i = i + 2) {
				map[nodes[i]][nodes[i + 1]] = 1;
			}
			if (gotGoal == true) {
				goal_x = rand() % 20;
				goal_y = rand() % 20;
				score++;
				CLOCK = CLOCK = .01;
				map[goal_x][goal_y] = 2;
				gotGoal = false;
			}
		//	cout << "flag1" << endl;
			if (key[0] && Ekans_y > -1) {
				Ekans_y -= 1;
			}
			if (key[1] && Ekans_y > -1) {
				Ekans_y += 1;
			}
			if (key[2] && Ekans_x > -1) {
				Ekans_x -= 1;
			}
			if (key[3] && Ekans_x > -1) {
				Ekans_x += 1;
			}
			if (map[goal_x] == map[Ekans_x] && map[goal_y] == map[Ekans_y]) {
				gotGoal = true;
				snekLength += 2;
			}
			//cout << "flag1.2" << endl;
			if (Ekans_x >= 0 &&
				Ekans_y >= 0 &&
				Ekans_x < 20 &&
				Ekans_y < 20)
				map[Ekans_x][Ekans_y] = 1;

			nodes.insert(nodes.begin(), Ekans_y);
			nodes.insert(nodes.begin(), Ekans_x);
			//cout << "flag1.3" << endl;

			if (Ekans_x < 0 || Ekans_y < 0)
				cout << "MATRIX ERROR" << endl;
			cout << "flag 1.4" << endl;
			//kill ekans if it hits the wall
			if (Ekans_x < 0 || Ekans_x >= 21 || Ekans_y < -1 || Ekans_y >= 21) {
				cout << "snek is dead, hit wall" << endl;
				cout << Ekans_x <<" , "<< Ekans_y << endl;
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_textf(font, al_map_rgb(251, 0, 0), 300, 300, NULL, "Ekans is ded.");
				al_flip_display();
				al_rest(2);
			}
		//	cout << "flag2" << endl;
			for (iter = nodes.begin() + 2; iter < nodes.end(); iter += 2) {
				cout << "head is" << Ekans_x << " ' " << Ekans_y << endl;
				cout << "node values are " << *iter << " , " << *(iter + 1) << endl;

				if ((Ekans_x == *iter && Ekans_y == *(iter + 1))) {
					cout << "you bumped into snek's tail, he is ded!" << endl;
					al_clear_to_color(al_map_rgb(0, 0, 0));
					al_draw_textf(font, al_map_rgb(250, 0, 0), 300, 300, NULL, "Ekans is ded.");
					al_flip_display();
					al_rest(2);

					return 0;
				}
			}
			nodes.erase(nodes.begin() + snekLength, nodes.end());

			redraw = true;
		}//end timer section
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {

			switch (ev.keyboard.keycode) {

			case ALLEGRO_KEY_UP:
				key[0] = true;
				key[1] = false;
				key[2] = false;
				key[3] = false;
				break;

			case ALLEGRO_KEY_DOWN:
				key[1] = true;
				key[2] = false;
				key[0] = false;
				key[3] = false;
				break;

			case ALLEGRO_KEY_LEFT:
				key[2] = true;
				key[1] = false;
				key[0] = false;
				key[3] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[3] = true;
				key[1] = false;
				key[2] = false;
				key[0] = false;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				//key[0] = false;
				break;

			case ALLEGRO_KEY_DOWN:
				//key[1] = false;
				break;

			case ALLEGRO_KEY_LEFT:
				//key[2] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				//key[3] = false;
				break;

			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}
		}
		//RENDER SECTION

		if (redraw && al_is_event_queue_empty(event_queue)) {
			cout << "flag3" << endl;
			redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));

			if (gotGoal == false)
				map[goal_x][goal_y] = 2;

			for(int i = 0; i < 20; i++)
				for (int j = 0; j < 20; j++) {

					if (map[i][j] == 1) {
						//al_draw_filled_rectangle(i*SNEKSIZE, j*SNEKSIZE, i*SNEKSIZE + SNEKSIZE, j*SNEKSIZE + SNEKSIZE, al_map_rgb(100, 250, 50));//snek
						al_draw_bitmap(Ekans, i*SNEKSIZE, j*SNEKSIZE, 0);
					}
					//if (map[i][j] == 0)
						//al_draw_rectangle(i*SNEKSIZE, j*SNEKSIZE, i*SNEKSIZE + SNEKSIZE, j*SNEKSIZE + SNEKSIZE, al_map_rgb(150, 0, 0), 4);//grid lines
					if (map[i][j] == 2) {
						al_draw_bitmap(food, i*SNEKSIZE, j*SNEKSIZE, 0);
						CLOCK = CLOCK - .1;
						//al_draw_filled_rectangle(i*SNEKSIZE, j*SNEKSIZE, i*SNEKSIZE + SNEKSIZE, j*SNEKSIZE + SNEKSIZE, al_map_rgb(150, 50, 150));//food
					}
				}

			al_draw_textf(font, al_map_rgb(20, 20, 255), 375, 9, ALLEGRO_ALIGN_CENTRE, "score = %i", score);

					if (gotGoal == true)
						map[goal_x][goal_y] = 0;
				

			//al_draw_bitmap(Ekans, Ekans_x, Ekans_y, 0);

			al_flip_display();
		}
	}
	al_destroy_sample(sample);
	al_destroy_sample_instance(instance1);
	al_destroy_bitmap(Ekans);
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);

	return 0;
}