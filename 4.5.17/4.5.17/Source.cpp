#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
int main() {
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP *pic = NULL;
	al_init();
	al_init_image_addon();
	pic = al_load_bitmap("Mario.png");
	display = al_create_display(640, 480);
	al_set_window_title(display,"Welcome to my game!");
	al_set_display_icon(display, pic);
	al_flip_display();
	al_rest(5);
	al_destroy_display(display);
}