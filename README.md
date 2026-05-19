*This project has been created as part of the 42 curriculum by etessoer and ymoumene.*

# MiniRT

## Description

MiniRT is a ray tracing project written in C for Linux.

The program reads a scene file, builds the scene, and renders it in a MiniLibX window using ray/object intersections, shading, shadows, textures, bump maps, and several rendering options. The codebase is organized around parsing, BVH acceleration, intersection handling, normals, UV mapping, rendering, threading, and an in-app interface for scene/control management.

This repository also includes a small set of sample scenes in maps/rt and maps/json.

## Instructions

### Requirements

- Linux
- clang
- MiniLibX
- X11 / Xext development libraries

### Build

```bash
make
```

Useful targets:

- `make clean` removes object files
- `make fclean` removes object files and the binary
- `make re` rebuilds everything from scratch

### Run

```bash
./miniRT maps/rt/test.rt
./miniRT maps/json/test.json
```

You can also use any other valid scene file from maps/rt or maps/json.

## Scene Format

The parser supports the following .rt identifiers:

| Identifier | Meaning | Main data |
| --- | --- | --- |
| `A` | Ambient light | brightness, color |
| `C` | Camera | position, direction, FOV |
| `L` | Light | position, brightness, color, optional texture data |
| `sp` | Sphere | position, diameter, color |
| `pl` | Plane | position, normal, color |
| `cy` | Cylinder | position, normal, diameter, height, color |
| `rb` | Rounded box | position, normal, size, color |
| `bo` | Box | position, normal, size, color |
| `co` | Cone | position, normal, angle/height data, color |
| `tr` | Triangle | three vertices, color |

Objects can also include optional material values after the color:

- reflection
- transparency
- refraction
- randomless

Textures and bump maps can also be attached through the scene description.

### .rt Example

```txt
A 0.1 255,255,255
C 0,40,-80 0,0,1 110
L 0,40,-10 1 255,255,255

sp 0,0,20 10 255,255,255 0.4 0.6 1.6 0.1 1 0
pl 0,-80,-100 0,1,0 255,0,255
cy 50,0,20 0,1,0 14.2 21.42 10,0,255
```

In this project, the extra values are used for reflective, transparent, and refractive materials, plus an additional randomness factor used by the renderer.

## JSON Format

The project also accepts .json scenes.

Supported JSON top-level keys include:

- `camera`
- `ambient`
- `light`
- `sphere`
- `plane`
- `cylinder`
- `cone`
- `rounded_box`
- `box`
- `triangle`

### JSON Example

```json
{
	"camera" :
	{
		"coordinates" : [0, 40, -80],
		"normal" : [0, 0, 1],
		"fov" : 110
	},
	"ambient" :
	{
		"brightness" : 0.1,
		"color" : [255, 255, 255]
	},
	"light" :
	{
		"coordinates" : [0, 40, -10],
		"brightness" : 1,
		"color" : [255, 255, 255],
		"radius" : 0
	},
	"sphere" :
	{
		"coordinates" : [0, 0, 20],
		"diameter" : 10,
		"color" : [0, 255, 255],
		"reflection" : 0.4,
		"transparency" : 0.6,
		"refraction" : 0.6,
		"randomless" : 0.1
	}
}
```

## Controls

Default controls are configurable in the project and can be changed in the control menu.

Common actions:

- `W`, `A`, `S`, `D` to move the camera
- `Space` to move up
- Left Ctrl to move down
- `M` to open/close the menu
- `U` to toggle camera rotation
- `R` to toggle object rotation
- `X` to toggle blur
- Mouse wheel to change the camera field of view in the main scene
- Mouse movement to rotate the camera when rotation is enabled
- `Esc` to quit

## Resources

- Ray tracing and rendering
	- https://raytracing.github.io/books/RayTracingInOneWeekend.html#outputanimage/theppmimageformat
	- https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-rendering-a-triangle/moller-trumbore-ray-triangle-intersection.html
	- https://www.youtube.com/watch?v=UTz7ytMJ2yk&t=5s

- Intersections and geometry
	- https://iquilezles.org/articles/intersectors/
	- https://zestedesavoir.com/tutoriels/2835/theorie-des-collisions/collisions-en-3d/formes-simples/#1-aabb-3d
	- https://fr.wikipedia.org/wiki/Matrice_de_rotation

- BVH and acceleration structures
	- https://jacco.ompf2.com/2022/04/18/how-to-build-a-bvh-part-2-faster-rays/

- Scene formats and data
	- https://www.json.org/json-en.html

- General learning material
	- https://www.youtube.com/watch?v=Qz0KTGYJtUk&list=PLFt_AvWsXl0dlgwe4JQ0oZuleqOTjmox3
