# Conway's Game of Life

A C++ implementation of Conway's Game of Life using [raylib](https://www.raylib.com/).

## Dependencies

- C++ compiler (g++ recommended)
- [raylib](https://github.com/raysan5/raylib) (included in `raylib/`)

## Build & Run

```bash
g++ -o game game.cpp grid.cpp simulation.cpp -Iraylib/build/raylib/include -Lraylib/build/raylib -lraylib -lm
./game
```

## Controls

| Key | Action |
|---|---|
| `Space` | Pause / Resume |
| `↑` | Increase speed (+3 FPS) |
| `↓` | Decrease speed (-3 FPS) |

## Rules

1. Any live cell with fewer than 2 live neighbors dies (underpopulation).
2. Any live cell with 2 or 3 live neighbors lives on.
3. Any live cell with more than 3 live neighbors dies (overpopulation).
4. Any dead cell with exactly 3 live neighbors becomes alive (reproduction).

## Project Structure

| File | Purpose |
|---|---|
| `game.cpp` | Entry point, window loop, input handling |
| `grid.hpp` / `grid.cpp` | Grid data structure and rendering |
| `simulation.hpp` / `simulation.cpp` | Game logic, rules, neighbor counting |
