#include <genesis.h> // gendev 0.3.0

// Define the limits of the screen
#define MIN_X 0
#define MAX_X 39
#define MIN_Y 0
#define MAX_Y 27

// Define the starting position of the character on the screen
#define START_X 10;
#define START_Y 13;

// Show a static character for the life of this program
const char * msg = "!";

// Define the coordinates of the character as seen on the screen
u16 x = START_X;
u16 y = START_Y;

// These variables are modified by gamepad handling
u16 new_x = START_X;
u16 new_y = START_Y;

// This function is called when any gamepad input changes
void joyHandler(u16 joy, u16 changed, u16 state) {
  // Ignore input from anything except player one
  if (joy != JOY_1) {
    return;
  }

  // Move the string around on the screen with gamepad input while ensuring
  // the current position is always visible.
  if (state & BUTTON_LEFT) {
    if (x > MIN_X) {
      new_x -= 1;
    }
  } else if (state & BUTTON_RIGHT) {
    if (x < MAX_X) {
      new_x += 1;
    }
  } else if (state & BUTTON_UP) {
    if (y > MIN_Y) {
      new_y -= 1;
    }
  } else if (state & BUTTON_DOWN) {
    if (y < MAX_Y) {
      new_y += 1;
    }
  }
}

int main() {
  // Prepare the video chip for use
  VDP_init();

  // Prepare to read gamepad input
  JOY_init();

  // Register a function to respond to gamepad input
  JOY_setEventHandler(&joyHandler);

  // Run a loop of game logic
  while(1)
  {
    // Wait for a time when the CRT is not drawing on the screen
    VDP_waitVSync();

    // Clear the text from its previous position
    VDP_clearTextLine(y);

    // Draw the text at the new position
    x = new_x;
    y = new_y;
    VDP_drawText(msg, x, y);
  }
}
