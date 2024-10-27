import numpy as np

sizes = [100, 250,500,750,1000,2000,4000]
for size in sizes:
    array = np.random.randint(1, 10000, size)  # Generate random numbers
    np.savetxt(f"array_{size}.txt", array, fmt='%d')  # Save to file with given format
