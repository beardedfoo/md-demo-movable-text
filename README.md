# md-demo-movable-text
A movable text tech demo for the Sega Genesis/Megadrive

The tricky part of developing this was dealing with the gamepad input handler firing during the VDP drawing. I initially had some screen clearing code within the gamepad input handler, but it didn't work. Moving the screen clearing code into the main loop, which executes it during the V-blanking period, resolved the issue and moved the character around on the screen as expected.
