# My_world

For this project you will have to create your own terraformer program. You can pick up some ideas from Tycoon Terrain for Unity3D.
Your main challenge will be to display a map and edit it at runtime.

- The map is a wireframed map whose tiles are parcels.
- Parcels are squares with all the same size.
- The terrain will be changed by raising or lowering entire tiles or only one of their corners.


Tools will be provided to apply different effects and modifications upon the map.
Having a pleasant user interface and intuitive interactions is the key of a good editing tool. This project is the occasion for you to try your best on that topic.

![enter image description here](https://lh3.googleusercontent.com/Xw0V1K_IZRYEd-V8dm21_rC37muTbDqTn-hAy-U2iSOvRxWVTl-kAvfGBzVK6TJcl6g65yj0Awhu "Result")

# Projects requirements (achieved)
**Mandatory**
The following features are mandatory, if your project is missing one of them it will not be evaluated further:

- The window can be closed using events.
- The game manage the input from the mouse click and keyboard.
- Animations in your program are frame rate independent.

**Must**

- The map must be displayed using a 3D projection (e.g. isometric or parallel).
- The tiles and their corners must be selected using the mouse.
- At least 3 effects (including the modification of altitude) must be implemented and selectable with a tool- bar in the window (e.g. reinitialization of the tiles’ altitudes, modification of the size of the area of effect, switching between “tiles selectable” and “corners selectable”).

**Should**

- Your window should stick between 800x600 pixels and 1920x1080 pixels.
- The size of the map should be selected using editable textboxes in the window.
- Help Text boxes should appear as the mouse hovers elements in the toolbar(s).
- The buttons should have at least 3 visual states : idle, hover, and clicked.
- Tiles should have a texture.
- The format of saved maps should be in a .legend file.
- Moving around on the map should be done with arrow keys and/or by positionning the mouse cursor at the edges of the window.
- Zooming up and down should be done with keyboard and/or the scrolling button of the mouse.

**Could**

- The program could save the map in a file at the end of the program in the terminal.
- The program could save the map in a file at runtime using buttons and tools .
- The program could load a map at the beginning of the program in the terminal (argument or stdin).
- The program could load a map at runtime using buttons and tools.
- The name of the saved files could be chosen at runtime.
- Tools can be selected using keyboard shortcuts.
- Sounds could be played on user actions.
- Textures of the tiles could change depending on the direction of their slope.
- Elements (e.g. buildings, roads) could be added on the map in compliance with the landforms.
- Water areas could be added.

# Usage and unit tests (Criterion)

To compile the program :

    make
    make fclean

To compile and run unit tests :

    make tests run

Check assets bash script :

    cd tests/ ; ./check_ressources.sh

