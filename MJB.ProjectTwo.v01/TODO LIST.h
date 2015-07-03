//TODO: Make the background stretch to fit the scrren no matter the screen size
//TODO: Make a colour class, where colours can be idenified by words, making a transcolour, background colour. Maybe add to the graphics class??


/*Sprite Blitting

Traditional games using 2D graphics have to rapidly display numerous bitmaps on screen to give the illusion of movement and animation. 
A full screen background layer may be represented by tiles, which are stored as an indexed array of small repeatable bitmaps. 
The objects displayed in front are sprites and are also stored as small bitmaps. 
Some platforms provide direct hardware support for these components, freeing the game code from the need to construct the raster image. 
However, it is important to understand (and sometimes necessary to implement in software) how the graphical display of a game can be constructed 
from these smaller components.

A software implementation of sprites typically requires a framebuffer that is a bitmap representing the entire screen. 
It is a two dimensional array in memory, given a width and height in pixels, with each element defined by a pixel format. 
This format is usually governed by hardware constraints, but typically contains at least the three red, green and blue colour channels to some bit depth. 
For example, a 16 bit framebuffer may use a pixel format that gives 5 bits (32 levels) per channel, or an 8 bit indexed colour buffer may reference a 
256 entry palette of 24 bit colours. The sprites themselves refer to bitmaps, which may have a different pixel format and are to be copied to the 
framebuffer at a certain coordinate.

This operation is known as a blit, which basically copies the contents of one memory location to another, with regard to the relative pixel format, 
stride and compression. This assignment aims to develop a complete software sprite implementation within the framework of a simple game. 
Emphasis must be placed on the techniques used to render the sprites to the screen, rather than the game itself. 
Existing APIs can be used for loading image data and for the display and update of a window. 
The sprite blitting should be platform agnostic as far as possible and capable of handling at least truecolour and indexed colour pixel formats.

A common technique for smooth animation is to use a double buffer, where two framebuffers exist to prevent tearing artifacts. 
While the front buffer is being displayed to the player, the game is blitting into the back buffer ready for the next frame. 
During the vertical black interval, the back buffer then becomes displayed to the player and the process continues to the next frame. 
A hardware implementation may require both pages in video RAM and then flip between them each frame. In software, it is possible to have the back 
buffer in main memory which is then itself blitted to the front buffer during the vertical blank.

Transparency may also be a requirement of some pixel formats, requiring the blitting function to either ignore or blend certain pixels based on 
their colour value, using techniques such as colour keying or alpha blending. Animation can be achieved by moving the foreground sprites over the 
background tiles, but it is usually expected that each sprite also displays different frames of animation over time. These can sometimes be stored 
efficiently in the same bitmap, with coordinates used to locate the offset of each frame. Image compression techniques, such as palettisation and run 
length encoding can be employed to not only decrease the memory requirements but also increase the blitting speed in some cases.
*/

//Make mouse a target, and shoot the sparites on screen. Every sprite clicked is then deleted from memory.
		