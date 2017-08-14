# RaytraCer
Basic raytracing engine written in C for educational purpose. It does not use any functions from the standard library except malloc and free.

![raytracing workflow](https://www.ice.rwth-aachen.de/fileadmin/user_upload/forschungsprojekte/tools/GRACE/raytracing.gif)

## Features

* Camera
* Colored lights
* Object primitives (plan, sphere, cylinder, cone, blob)
* Negative objects
* Reflection
* Refraction
* Bump mapping
* Cellshading
* Perlin noise
* Graphical tool
* JPEG export

## Scenes

![Scene 1](./screenshots/RTScreen1.png)

![Scene 2](./screenshots/RTScreen2.png)

![Scene 3](./screenshots/RTScreen3.png)

![Scene 4](./screenshots/RTScreen4.png)

![Scene 5](./screenshots/RTScreen5.png)

## Installation

1. Install [minilibx](https://github.com/dannywillems/minilibx) inside /usr/X11/lib
2. Install [libjpeg](http://libjpeg.sourceforge.net/) inside /usr/X11/lib
3. `make`
4. `./rt scenes/*`
