#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"

const int RIGHT = 3;
const int LEFT = 1;
const int UP = 2;
const int DOWN = 4;

const int PACSIZE = 30;


using namespace std;
int wallCollide(int Pacman_x, int Pacman_y, int dir, int map[20][20]);

class ghosts {
public:
	ghosts();
	void initGhost(int x, int y, char color, int direction, bool dead, int speed);
	bool isdead();
	//void draw();
	void drawGhost();
	void printInfo();
	void chase(int x, int y, int map[20][20]); //need 4 eventually
	bool getPacman(int xpos, int ypos);

private:
	int hitwall;
	int xpos;
	int ypos;
	char color;
	int direction;
	bool dead;
	int speed;

};
int main() {
	ALLEGRO_DISPLAY*display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP*Pacman = NULL;
	ALLEGRO_BITMAP*wall = NULL;
	ALLEGRO_BITMAP*dot = NULL;
	ALLEGRO_BITMAP*cherry = NULL;
	ALLEGRO_FONT * font = NULL;
	ALLEGRO_SAMPLE *sample = NULL;

	int Pacman_x = 385;
	int Pacman_y = 565;

	const int maxFrame = 5;

	int curFrame = 0;

	int frameCount = 0;

	int frameDelay = 5;

	int frameWidth = 38;
	int frameHeight = 30;

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
		1,1,1,1,0,1,0,0,0,2,0,0,0,0,1,0,1,1,1,1,
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

	event_queue = al_create_event_queue();

	timer = al_create_timer(1.0 / 60);

	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_start_timer(timer);

	ghosts blinky;
	blinky.initGhost(160, 160,'F', 10, false, 10);
		//initGhost(int xpos, int ypos, char color, int direction, bool dead, int speed);

	//    al_rest(3);
	//cout << "flag" << endl;
	Pacman = al_create_bitmap(PACSIZE, PACSIZE);

	//cherry = al_create_bitmap(30,30);
	//al_set_target_bitmap(cherry);
	//al_clear_to_color(al_map_rgb(255, 0, 0));
	cherry = al_load_bitmap("cherry_40x40.png");

	//Pacman = al_load_bitmap("pacman_30x30.png");
	Pacman = al_load_bitmap("pacman-spritesheet_190x30.png");


	wall = al_create_bitmap(40, 40);
	al_set_target_bitmap(wall);
	al_clear_to_color(al_map_rgb(0, 37, 115));

	dot = al_create_bitmap(8, 8);
	al_set_target_bitmap(dot);
	al_clear_to_color(al_map_rgb(255, 255, 255));

	//pinky = al_create_bitmap(15, 15);
	//al_set_target_bitmap(pinky);
	//al_clear_to_color(al_map_rgb(253, 194, 212));

	//blinky = al_create_bitmap(15, 15);
	//al_set_target_bitmap(blinky);
	//al_clear_to_color(al_map_rgb(252, 59, 16));

	//inky = al_create_bitmap(15, 15);
	//al_set_target_bitmap(inky);
	//al_clear_to_color(al_map_rgb(74, 223, 203));

	//clyde = al_create_bitmap(15, 15);
	//al_set_target_bitmap(clyde);
	//al_clear_to_color(al_map_rgb(255, 190, 86));


	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);
	//cout << "flag" << endl;
	while (!doexit && score < 200)
	{
		cout << Pacman_x << " , " << Pacman_y << endl;
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			if (key[0] && wallCollide(Pacman_x, Pacman_y, UP, map) == 0) {
				Pacman_y -= 4.0;
			}

			if (key[1] && wallCollide(Pacman_x, Pacman_y, DOWN, map) == 0) {
				Pacman_y += 4.0;
			}

			if (key[2] && wallCollide(Pacman_x, Pacman_y, LEFT, map) == 0) {
				Pacman_x -= 4.0;
			}
			cout << "flag porter" << endl;
			//pacman move right
			if (key[3] && wallCollide(Pacman_x, Pacman_y, RIGHT, map) == 0) {
				cout << "flag elias" << endl;
				Pacman_x += 4.0;
			}

			if (Pacman_x > -7 && Pacman_x < 1 && Pacman_y > 333 && Pacman_y < 377) {
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
																	                                                //sound effect here

				score++;                                                    //up score here
			}
			else if (map[(Pacman_y + 20) / 40][(Pacman_x + 20) / 40] == 2) {
				map[(Pacman_y + 20) / 40][(Pacman_x + 20) / 40] = 4;
				score = score + 13;
			}


			blinky.chase(Pacman_x, Pacman_y, map);

			redraw = true;

			if (++frameCount >= frameDelay) {
				if (++curFrame >= maxFrame)
					curFrame = 0;

				frameCount = 0;
			}
			//Pacman_x -= 5;

			if (Pacman_x <= 0 - frameWidth)
				Pacman_x = 30;

			sample = al_load_sample("wakka.wav"); 


			
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


			for (int x = 0; x < 20; x++)  // loop 3 times for three lines
			{
				for (int y = 0; y < 20; y++)  // loop for the three elements on the line
				{
					//check if matrix holds a "1"
					if (map[x][y] == 1)
						al_draw_bitmap(wall, y * 40, x * 40, NULL);
					if (map[x][y] == 0)
						al_draw_bitmap(dot, y * 40 + 20, x * 40 + 20, NULL);
					if (map[x][y] == 2)
						al_draw_bitmap(cherry, y * 40 , x * 40, NULL);

					//    if ((map[x][y] == 0) && ()
					//if holds a 2, draw a dot
				}
			}


			blinky.drawGhost();

			if (char color = 'F')
				al_map_rgb(252, 59, 16);

			al_draw_textf(font, al_map_rgb(20, 20, 255), 450, 1, ALLEGRO_ALIGN_CENTRE, "score = %i", score);

			al_draw_bitmap_region(Pacman,curFrame*frameWidth, 0, frameWidth, frameHeight, Pacman_x, Pacman_y, 0);
			al_flip_display();
		}
	}//end game loop
	

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(font, al_map_rgb(20, 20, 255), 640 / 2, (480 / 4), ALLEGRO_ALIGN_CENTRE, "You Win!");
	al_rest(2);


	al_destroy_bitmap(Pacman);
	al_destroy_display(display);
	al_destroy_bitmap(wall);
	al_destroy_bitmap(dot);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);

	return 0;
}
int wallCollide(int Pacman_x, int Pacman_y, int dir, int map[20][20]) {
	cout << "flag1" << endl;
	int new_x1;
	int new_x2;
	int new_x3;
	int new_y1;
	int new_y2;
	int new_y3;
	if (dir == RIGHT) {         // Moving Right
								// Check along the far right side of the sprite, plus 3 (the amount we�re moving)
		new_x1 = Pacman_x + 3 + PACSIZE;
		new_x2 = Pacman_x + 3 + PACSIZE;
		new_x3 = Pacman_x + 3 + PACSIZE;
		//Check at three point along that edge
		new_y1 = Pacman_y;
		new_y2 = Pacman_y + PACSIZE / 2;
		new_y3 = Pacman_y + PACSIZE;
		cout << "flag2" << endl;
		if (map[new_y1 / 40][new_x1 / 40] == 1 || map[new_y2 / 40][new_x2 / 40] == 1 || map[new_y3 / 40][new_x3 / 40] == 1)//don't forget x3
			return 1; //collision!
	}
	if (dir == LEFT) {
		new_x1 = Pacman_x - 3;
		new_x2 = Pacman_x + 3 / 2;
		new_x3 = Pacman_x;

		new_y1 = Pacman_y;
		new_y2 = Pacman_y + 3 / 2;
		new_y3 = Pacman_y + PACSIZE;
		cout << "flag3" << endl;
		if (map[new_y1 / 40][new_x1 / 40] == 1 || map[new_y2 / 40][new_x2 / 40] == 1 || map[new_y3 / 40][new_x3 / 40] == 1)//don't forget x3
			return 1;
	}
	if (dir == UP) {
		new_x1 = Pacman_x;
		new_x2 = Pacman_x + PACSIZE / 2;
		new_x3 = Pacman_x + PACSIZE;

		new_y1 = Pacman_y -3;
		new_y2 = Pacman_y -3;
		new_y3 = Pacman_y -3;

		if (map[new_y1 / 40][new_x1 / 40] == 1 || map[new_y2 / 40][new_x2 / 40] == 1 || map[new_y3 / 40][new_x3 / 40] == 1)//don't forget x3
			return 1;
	}
	if (dir == DOWN) {
		new_x1 = Pacman_x;
		new_x2 = Pacman_x + PACSIZE;
		new_x3 = Pacman_x + PACSIZE / 2;

		new_y1 = Pacman_y + PACSIZE + 3;
		new_y2 = Pacman_y + PACSIZE + 3;
		new_y3 = Pacman_y + PACSIZE + 3;

		if (map[new_y1 / 40][new_x1 / 40] == 1 || map[new_y2 / 40][new_x2 / 40] == 1 || map[new_y3 / 40][new_x3 / 40] == 1)//don't forget x3
			return 1;
	}
	return 0;
}

//ghost class functions
ghosts::ghosts() {
	xpos = 0;
	ypos = 0;
	dead = 0;
}

void ghosts::initGhost(int x, int y, char c, int dir, bool dead, int Gspeed) {
	xpos = x;
	ypos = y;
	dead = 0;

}
bool ghosts::isdead() {
	return dead;
}
void ghosts::drawGhost() {
	cout << "drawing ghost at " << xpos << " " << ypos << endl;
	al_draw_filled_rectangle(xpos, ypos, xpos + 30, ypos + 30, al_map_rgb(20, 20, 255));

}
void ghosts::printInfo() {
}
void ghosts::chase(int x, int y, int map[20][20]) {
	//if we're moving left and there's an opening above and pacman is above, move up
	if ((direction == LEFT) && !wallCollide(xpos, ypos, UP, map) && y<ypos)
		while (!wallCollide(xpos, ypos, 2, map)) {
			// cout << "trying to move through hole above!" << endl;
			direction = UP;
			ypos -= 4;
			return;
		}

	//if we're moving left and there's an opening below and pacman is below, move down
	if ((direction == LEFT) && !wallCollide(xpos, ypos, DOWN, map) && y>ypos)
		while (!wallCollide(xpos, ypos, 4, map)) {
			//  cout << "trying to move through hole below!" << endl;
			direction = DOWN;
			ypos += 4;
			return;
		}


	if (direction == LEFT)//left
		while (!wallCollide(xpos, ypos, LEFT, map)) {
			xpos -= 4;
			return;
		}

	////////////////////////////////UP STATE (2)///////////////////////////////////////////////////////////////

	//if we're moving up and there's an opening left and pacman is left, move left
	if ((direction == UP) && !wallCollide(xpos, ypos, LEFT, map) && x<xpos)
		while (!wallCollide(xpos, ypos, LEFT, map)) {
			//   cout << "trying to move through hole to left!" << endl;
			direction = LEFT;
			xpos -= 4;
			return;
		}
	//if we're moving up and there's an opening right and pacman is right, move right
	if ((direction == UP) && !wallCollide(xpos, ypos, RIGHT, map) && x>xpos)
		while (!wallCollide(xpos, ypos, 3, map)) {
			// cout << "trying to move through hole to right!" << endl;
			direction = RIGHT;
			xpos += 4;
			return;
		}
	if (direction == UP)//up
		while (!wallCollide(xpos, ypos, 2, map)) {
			ypos -= UP;
			return;
		}

	/////////RIGHT CASE (3)/////////////////////////////////////////////////////////////////////////////////////////////////////
	//if we're moving right and there's an opening above and pacman is above, move up
	if ((direction == RIGHT) && !wallCollide(xpos, ypos, UP, map) && y<ypos)
		while (!wallCollide(xpos, ypos, 2, map)) {
			//   cout << "trying to move through hole above!" << endl;
			direction = UP;
			ypos -= 2;
			return;
		}

	//if we're moving right and there's an opening below and pacman is below, move down
	if ((direction == RIGHT) && !wallCollide(xpos, ypos, DOWN, map) && y>ypos)
		while (!wallCollide(xpos, ypos, DOWN, map)) {
			//  cout << "trying to move through hole below!" << endl;
			direction = DOWN;
			ypos += 2;
			return;
		}


	if (direction == RIGHT)//right
		while (!wallCollide(xpos, ypos, RIGHT, map)) {
			xpos += 2;
			return;
		}


	//////////////DOWN CASE (4)/////////////////////////////////////////////////////////////////////////////////////
	//if we're moving up and there's an opening left and pacman is left, move left
	if ((direction == DOWN) && !wallCollide(xpos, ypos, LEFT, map) && x<xpos)
		while (!wallCollide(xpos, ypos, LEFT, map)) {
			// cout << "trying to move through hole to left!" << endl;
			direction = LEFT;
			xpos -= 2;
			return;
		}
	//if we're moving up and there's an opening right and pacman is right, move right
	if ((direction == UP) && !wallCollide(xpos, ypos, RIGHT, map) && x>xpos)
		while (!wallCollide(xpos, ypos, RIGHT, map)) {
			//   cout << "trying to move through hole to right!" << endl;
			direction = RIGHT;
			xpos += 2;
			return;
		}

	if (direction == DOWN)//down
		while (!wallCollide(xpos, ypos, DOWN, map)) {
			ypos += 2;
			return;
		}





	///////////////////////////////////////////////////////////////////////////////////////
	//if pacman is above and there's no wall there, move up
	if ((y<ypos) && !wallCollide(xpos, ypos, UP, map)) {
		//  cout << "direction is up" << endl;
		direction = UP;
		return;
	}


	//if pacman is below and there's no wall there, move down
	if ((y>ypos) && !wallCollide(xpos, ypos, DOWN, map)) {
		direction = DOWN;
		//   cout << "direction is down" << endl;
		return;
	}

	//if pacman is right and there's no wall there, move right
	if ((x>xpos) && !wallCollide(xpos, ypos, RIGHT, map)) {
		direction = RIGHT;
		//  cout << "direction is right" << endl;
		return;
	}

	//if pacman is left and there's no wall there, move left
	if ((x<xpos) && !wallCollide(xpos, ypos, LEFT, map)) {
		direction = LEFT;
		// cout << "direction is left" << endl;
		return;

	}

	//if pacman is above and there's no wall there, move up
	if (!wallCollide(xpos, ypos, UP, map)) {
		// cout << "direction is up" << endl;
		direction = UP;
		return;
	}


	//if pacman is below and there's no wall there, move down
	if (!wallCollide(xpos, ypos, DOWN, map)) {
		direction = DOWN;
		//cout << "direction is down" << endl;
		return;
	}

	//if pacman is right and there's no wall there, move right
	if (!wallCollide(xpos, ypos, RIGHT, map)) {
		direction = RIGHT;
		//  cout << "direction is right" << endl;
		return;
	}

	//if pacman is left and there's no wall there, move left
	if (!wallCollide(xpos, ypos, LEFT, map)) {
		direction = LEFT;
		// cout << "direction is left" << endl;
		return;

	}

}cout << "x pos " << xpos << "  ypos " << ypos << endl;


} //need 4 eventually
bool ghosts::getPacman(int xpos, int ypos) {
	dead = true;
	return 1;

}