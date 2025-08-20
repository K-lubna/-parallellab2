# Execution Time Measurement in C

This repository contains two C programs that demonstrate how to measure the execution time of a sorting algorithm using:

- Standard C timing (`clock()` from `<time.h>`)
- OpenMP high-resolution timing (`omp_get_wtime()`)

---

📌 Programs Included

 🔸 `cie1.c` — Without OpenMP

- Uses `clock()` from `<time.h>` to measure execution time.
- Performs a simple bubble sort on user-provided or randomly generated data.
- Suitable for standard C environments without OpenMP support.

🔸 `cie1a.c` — With OpenMP

- Uses `omp_get_wtime()` for more accurate time measurement.
- Requires compilation with `-fopenmp` flag.
- Can take advantage of OpenMP for future parallel enhancements.

---

 🛠️ How to Compile and Run

 🔹 Without OpenMP (cie1.c)

gcc cie1.c -o cie1
./cie1

 With OpenMP (cie1a.c)

gcc -fopenmp cie1a.c -o cie1a
./cie1a
