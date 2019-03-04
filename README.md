# Fract'Ol

This project was completed in February 2019 as part of the 42 school cursus. The aim was to vizualize 3 fractals using the minilibx graphics library. The complete instruction can be found [here](https://github.com/miniponps/42-Fractol/blob/master/fract_ol.pdf).

## Getting Started

Clone the repository. The project uses the minilibx library which can be found in the `resources/` folder. To install the minilibx library, follow the instructions [here](https://github.com/pbondoer/MinilibX).
Compile the project using `make`.

### Controls

```
change mode: C
zoom: scroll up/down (in zoom mode)
color: SPACE / scroll up/down (in color mode)
move fractal: up/down/left/right arrows
change julia parameters: move mouse (if active)
activate/deactivate mouse control of julia parameters: M
exit: ESC / red cross
```

## Examples

![Mandelbrot](https://github.com/anaiel/fractol/blob/master/fractals/Mandelbrot.png?raw=true "Mandelbrot")
```
./fractol mandelbrot
```
![Julia](https://github.com/anaiel/fractol/blob/master/fractals/Julia.png?raw=true "Julia")
```
./fractol julia
```
![Burning ship](https://raw.githubusercontent.com/anaiel/fractol/master/fractals/Burning%20ship.png "Burning ship")
```
./fractol "burning ship"
```

## Authors

* **Anaëlle Leclabart** - [anaiel](https://github.com/anaiel)