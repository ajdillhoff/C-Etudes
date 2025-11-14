# Quadratic Probing

In this exercise, you will modify the collision resolution strategy of a hash map to use quadratic probing instead of linear probing. Quadratic probing reduces clustering by using a quadratic function to determine the next index to probe when a collision occurs.

## Instructions
1. Open the `hash_map_utils.c` file.
2. Locate the `insert` function where collisions are detected. Look for the `TODO` comment indicating where to implement quadratic probing.
3. Implement quadratic probing based on the following the formula:
   ```
   index = (original_index + i^2) % map_size
   ```
   where `i` starts at 1 and increments by 1 for each collision encountered.
4. Save your changes and run the provided tests to ensure that your implementation works correctly.