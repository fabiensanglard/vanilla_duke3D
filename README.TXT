 // "Build Engine & Tools" Copyright (c) 1993-1997 Ken Silverman
 // Ken Silverman's official web site: "http://www.advsys.net/ken"
 // See the included license file "BUILDLIC.TXT" for license info.

These notes first written on: 01/05/2000, Revised on: 05/24/2000, 06/07/2000

--------------------------------  GAME.EXE  --------------------------------
NOTE!  By default, I have the VESA modes and SOUND disabled! I did this to
ensure that GAME.EXE works the first time you run it. Please run the SETUP
program to enable better SOUND and GRAPHICS options (if they're supported)

Command line:
   >game [mapname]
   If no map name is specified, then "NUKELAND.MAP" is used.

Keys:
       ESC = Quit
     Mouse = Movement (if enabled, but don't bother)
    Arrows = Movement
     Enter = Single player: Play back game, Multiplayer: Other players' views
  KP Enter = Switch between 3D / 2D modes
       +/- = Zoom in and out (2D mode)
       A/Z = Move up and down
     LCtrl = Shoot
       1-5 = Select weapon (Always have 1&2. You must pick up weapons 3-5)
    LShift = Run
    KP 0/. = Adjust camera angle for 3rd person camera mode
       [/] = Screen tilt
         ' = Hold screen sideways
ALT KP +/- = Change visibility.
         M = Become master (for multiplayer games)
         P = Change parallaxing sky mode. (0, 1, and 2 (Default = 2)
         T = Typing mode
         V = Toggle 3rd person camera mode
        F2 = Toggle 3D stereo modes (normal, Simuleyes, Nuvision)
        F4 = Cycle through all available 8-bit VESA modes
        F5 = Toggle lo/hi detail modes (a waste of programming time)
       F11 = Change brightness
       F12 = Screen capture to CAPT0000.BMP, CAPT0001.BMP, etc.
   Sh+Sh+R = Playback game
   Ct+Ct+L = Load game
   Ct+Ct+S = Save game
       Ins = Increase number of fake players (single player game)
       Del = Decrease number of fake players (single player game)
  Scr.Lock = Swap players (single player game)
       9/0 = Adjust stereo 3D position separation (for 3D glasses)
       (/) = Adjust stereo pixel separation (for 3D glasses)
 PrintScrn = Call interrupt 5

-------------------------------  SETUP.EXE  --------------------------------
   This is sort of a general purpose setup program that I've been upgrading
   since Ken's Labyrinth. You'll probably notice some similarities. Many of
   the options you see here either no longer apply or were never implemented
   in the my KenBuild demo. Please read the following to see what is currently
   supported in my GAME.EXE.

Graphics Mode:
   Select any mode except for the chain modes or the 3 specially-optimized
   graphics modes. When I added VESA 2.0 support in 1995, I removed these old
   modes from the engine. The VESA mode list in the setup program is not
   auto-detected, but you can cycle through to any VESA mode in the game if
   you press F4 a few times. Red-blue glasses mode works only in 320*200 mode.
   Any alternate palettes in red-blue glasses will be messed up. The stereo
   shutter glasses (Simuleyes / Nuvision) modes work only if you are in a
   VESA graphics mode with >= 4 pages. To activate these modes, press F2
   inside the game.

Digitized Sound:
   My sound engine supports Sound Blaster, Pro Audio Spectrum (I think it
   still works, but haven't tested it in a long time), and PC Speaker. The
   PC Speaker support is really nice, but it will only work in pure DOS mode.
   All other sound sources have not been implemented!

Music:
   If you really like my music then you can turn this feature on. I usually
   play with it off. It's fun to try it once though.

Input Devices:
   Spaceplayer support was removed a long time ago - don't select it. Mouse
   support is really bad because I didn't play games with the mouse when I
   originally programmed this. All of the keys are used in my game.

Communications:
   I wrote my own built-in communications routines (before support for
   COMMIT was added) All the options under this menu should work pretty
   well in most cases. My game should run at 4800bps. I recommend 9600bps,
   but nothing higher since it won't do much except increase the chances of
   getting communications errors. It is very important that you get the
   IRQ right when selecting a COM port. COM1 is usually IRQ4 and COM2 is
   usually IRQ3 (but not always).

-------------------------------  SETUP.DAT  --------------------------------
I store the settings you choose in SETUP.EXE in this tiny file.
   (GAME.EXE and BUILD.EXE read the settings in here)

---------------------------------  *.MAP  ----------------------------------
NUKELAND.MAP: My test map - with examples of lots of moving objects like doors
  BOARDS.MAP: My first test map in the sector engine (with revisions of course)
  NSNOAL.MAP: A lot of small maps combined into one huge one
  EVILAL.MAP: Objective: Try to kill off all of the "evil Al's"
ASCBOARD.MAP: A map by Andy Cotter with a network of warp zones and all weapons
  KENSIG.MAP: When I added slopes, I just couldn't help myself!

-------------------------------  STUFF.DAT  --------------------------------
TILES000.ART: My lovely artwork :)
NEATSONG.KDM: A digital song in my own KDM format (see KDMSONGS.ZIP on my site)
   WAVES.KWV: A collection of instruments for my music file (NEATSONG.KDM)
 PALETTE.DAT: Palette tables (A format description can be found on my web site)
  TABLES.DAT: Math tables (A format description can be found on my web site)
VOXEL000.KVX: A Duke Nukem 3D voxel sprite edited heavily in my SLAB6D editor
VOXEL001.KVX: Worm 3D voxel sprite (inspired from the game "Worms2" by Team17)

----------------------------------------------------------------------------
 -Ken S. (web page: http://www.advsys.net/ken)
