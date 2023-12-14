#include "constants.h"
#include <stdbool.h>


Image crash;
Image ps1;
Image guardianWalk;
Image guardian;

int x = 0;
int y = 0;
int speed = 2;

bool walking = false;

int main() {
	initialize();

	while(1) {
		update();
		clearDisplay();
		draw();
		display();
	}
}

void initialize() {
	initializeScreen();
	initializePad();
	setBackgroundColor(createColor(0, 0, 0));
	ps1 = createImage(img_ps1);
	crash = createImage(img_crash);
	guardianWalk = createImage(img_crash);
	guardianWalk = moveImage(guardianWalk, 128, 112);
	guardian = createImage(img_ps1);
	guardian = moveImage(guardian, 128, 112);
}

void update() {
	padUpdate();
	if(padCheck(Pad1Up)) {
		y += speed;
		crash = moveImage(crash, x, y);
		ps1 = moveImage(ps1, x, y);
	}

	if(padCheck(Pad1Down)) {
		y -= speed;
		crash = moveImage(crash, x, y);
		ps1 = moveImage(ps1, x, y);
	}

	if(padCheck(Pad1Left)) {
		x += speed;
		crash = moveImage(crash, x, y);
		ps1 = moveImage(ps1, x, y);
	}

	if(padCheck(Pad1Right)) {
		x -= speed;
		crash = moveImage(crash, x, y);
		ps1 = moveImage(ps1, x, y);
	}

	if (padCheck(Pad1Right) || padCheck(Pad1Left) || padCheck(Pad1Up) || padCheck(Pad1Down)) {
		walking = true;
	}
	else {
		walking = false;
	}
}

void draw() {
	if (walking) {
		drawImage(guardianWalk);
	}
	else {
		drawImage(guardian);
	}
	drawImage(crash);
	drawImage(ps1);
}