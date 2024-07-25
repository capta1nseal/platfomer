# platformer

This is a hobby project, aiming to build a 2D platformer from the figurative ground up.

## technical specs

Built upon:
- Modern c++
- SDL2 (potentially switching to dearimgui later, since it seems more suited to a ground-up approach)
- Vulkan (first rendering will probably be done in software with SDL2, later in vulkan with SPIR-V shaders)

Components to build:
- Separate simulation and rendering loops with good precision in delta time and stable frame rates.
- Some encapsulated timing component to get stable tick rates without busy waiting, and keep track of delta times.
- Moving objects with collision and rendered textures/shaders.
- Vulkan pipeline for rendering 2D moving objects efficiently.
- Physics simulation(s) for 2D objects.
- Some framework for animations. (spritesheets, procedurally generated and/or multi-component objects, etc.)

Goals to keep in mind:
- It would be great to have perfect or near-perfect sub-pixel precision in rendering.
- Timing stability beyond human perception would be awesome.
- Never create a situation where lag/lockups could be unavoidable.

### project status

Nothing has been built yet. It should be populated with a general structure and some demos of component functionality very soon.
