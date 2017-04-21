#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>

int main(void)
{
	int width = 640;
	int height = 480;
	bool done = false;

	//these are the x and y coordinates of our image. It starts off in the middle of the screen.
	int x = width / 2;
	int y = height / 2;

	//we've got 10 images that make our animation
	const int maxFrame = 10;

	//set the starting point to be the first image
	int curFrame = 0;
	//this is a counter that ticks with the event timer
	int frameCount = 0;
	//let's set the image to flip to the next one after 5 "ticks" of the timer. Make smaller to speed up the animation, bigger to slow.
	int frameDelay = 5;
	//how big is each image in your sprite sheet?
	int frameWidth = 32;
	int frameHeight = 50;

	//allegro variable
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer;
	ALLEGRO_BITMAP *image;


	al_init();
	display = al_create_display(width, height);
	al_install_keyboard();
	al_init_image_addon();

	//load the sprite sheet
	image = al_load_bitmap("tetra2.png");

	//function that makes a given color transparent
	al_convert_mask_to_alpha(image, al_map_rgb(159, 202, 215));

	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);

	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_start_timer(timer);

	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_LEFT:

				break;
			case ALLEGRO_KEY_RIGHT:

				break;
			case ALLEGRO_KEY_UP:

				break;
			case ALLEGRO_KEY_DOWN:

				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			//algorithm for moving the picture across the sprite sheet and across the allegro window

			//here's the counter going from 0-5 over and over
			if (++frameCount >= frameDelay)
			{
				//these two lines reset the image to the first after you cycle through all 10
				if (++curFrame >= maxFrame)
					curFrame = 0;

				//as soon as you enter this branch and do the code, reset the "timer"
				frameCount = 0;
			}

			//move the sprite to the left across the screen
			x -= 5;

			//if zelda walks off the window, reset her to the other side of the screen.
			if (x <= 0 - frameWidth)
				x = width;
		}

		//draws a given *section* of a bitmap
		//parameters: image to draw, x and y coords on that image, width and height of the image, the x and y coordinate on the screen
		al_draw_bitmap_region(image, curFrame*frameWidth, 0, frameWidth, frameHeight, x, y, 0);

		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}


	al_destroy_event_queue(event_queue);
	al_destroy_display(display);						//destroy our display object

	return 0;
}