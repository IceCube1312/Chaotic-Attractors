# Chaotic-Attractors

Two cool chaotic attractors made using C and raylib.

---

To run just use the make file then ./[insert attractor name here]
`make
./lorenz
./halvorsen`

### Lorenz attractor
Made using the following differential equations->

- dx/dt = σ(y - x)
- dy/dt = x(ρ - z) - y
- dz/dt = xy - βz

Here σ is the σ is the `PRANDTL` number, ρ is the `RAYLEIGH` number, and β is just `BETA` and their macros can be changed in the header file for other patterns.

---

### Halvorsen attractor
Made using the following differnetial equatins->

- dx/dt = -ax - 4y - 4z - y²
- dy/dt = -ay - 4z - 4x - z²
- dz/dt = -az - 4x - 4y - x²

Where the parameter a can be changed in the header file as `HAL_A`.

---

The rendering was pretty straight forward , I used simple euler integration. The only somewhat challenging thing was the trails which was done using a ring buffer or a circular queue.
