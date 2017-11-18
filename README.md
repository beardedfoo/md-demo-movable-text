# md-demo-movable-text
A movable text tech demo for the Sega Genesis/Megadrive

The tricky part of developing this was dealing with the gamepad input handler firing during the VDP drawing. I initially had some screen clearing code within the gamepad input handler, but it didn't work. Moving the screen clearing code into the main loop, which executes it during the V-blanking period, resolved the issue and moved the character around on the screen as expected.

It seems to me that problems such as this could become common if one does not pay careful attention not only to the order in which code executes but also the timing of the execution of code. The VDP is a co-processor and therefore is executing code to draw the screen in parallel with the 68k main processor. Certain changes to vram may not have the desired effect if the vram changes are written outside of the V-blanking period.

![demo-pic](images/demo.gif?raw=true)
