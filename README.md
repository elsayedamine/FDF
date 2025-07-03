# 🌄 FDF — Wireframe 3D Viewer

> _“Turning simple coordinates into mountains of meaning.”_

## 📌 Project Overview

**FDF** is a wireframe model renderer written in pure C using the **MiniLibX** graphics library. It takes a 3D map (represented as a grid of heights) and transforms it into a 2D isometric or parallel projection. This project is part of the **42 Network curriculum** and focuses on low-level graphics rendering, mathematical projections, and event-driven architecture — all from scratch.

What starts as a matrix of numbers becomes a living, breathing terrain in motion.

---

## 🚀 Features

✅ Isometric & parallel projection switching  
✅ Smooth zoom in/out using keyboard keys  
✅ Mouse-based navigation  
✅ Dynamic color gradients based on map values or user preferences  
✅ Real-time refresh on user interaction  
✅ Clean pixel-perfect rendering  
✅ Robust handling of malformed map files  
✅ **Interactive mini-menu** on the showing:
  - Current `x-offset`, `y-offset`, `z-height`
  - Zoom level, scale factor, rotation angle
  - User guide menu with instructions for keyboard and mouse controls for :
  - Rotation,
  - Scaling,
  - Height adjustment;

---

## 🛠️ Technologies & Concepts

- **C (ISO C90)** — all logic implemented from scratch
- **MiniLibX** — lightweight X11-based graphics library
- **parametric representation's Line Algorithm** — crisp line drawing between 2D points
- **Matrix Transformations** — rotation, scaling, projection
- **Manual memory management** — malloc/free with zero leaks
- **Event hooks** — capturing user input via keyboard & mouse
- **Color interpolation** — dynamic color gradient rendering by height

---

## 🧠 What I Learned

Working on FDF taught me to think like the machine: to break down visual perception into raw math and rebuild it line by line. I learned:

- How 3D transforms work behind every game and simulation
- Why graphics programming is both beautiful and brutal
- How to optimize for rendering performance in C
- How to structure code in an event-driven paradigm
- How passion turns math into art
- But above all — how to turn low-level tools into something beautiful.
---

## 🎮 Controls

| Action              | Key(s)               |
|---------------------|----------------------|
| Move Map            | Mouse (`Drag`)       |
| Zoom In / Out       | `+` `-`              |
| Rotate              | `L` / `R`            |
| Change Projection   | `P` (Parallel) / `I` (Isometric) |
| Reset View          | `Space`              |
| Exit Program        | `ESC`                |

---

## 📦 Installation

> **Requirements:** `cc`, `make`, and a working X11 environment (Linux/macOS)
```bash
git clone https://github.com/elsayedamine/FDF.git
cd FDF
make
./fdf test_maps/42.fdf
```
---

## ❤️ Dedication

> _This project is precious to me. It was the first time I felt like I wasn’t just coding — I was creating._

To every line of code that frustrated me, and every pixel that finally landed where I wanted: thank you for teaching me patience, persistence, and precision.

To anyone building something meaningful from scratch — keep going. It’s worth it.

_— Amine Elsayed._

---

## 🤝 Acknowledgements

- 1337 Coding School for pushing us beyond our limits  
- MiniLibX — tiny, but mighty  
- Everyone who ever told me to “just draw it myself”  
- @a-hakki — for his help, support, and unwavering dedication to my wor
---

> _“The only difference between art and code is the compile step.”_
