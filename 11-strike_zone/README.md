Create a function that prints out a bar whose length is determined by two parameters `size` and `progress`. An additional parameter `strike_zone` determines the size of a strike zone. The strike zone is a bar that is centered in the middle of the bar.

```sh
$ ./a.out 10 .5 1
|=====[ ]    |

$ ./a.out 10 .5 2
|====[= ]    |

$ ./a.out 10 .5 4
|===[==  ]   |
```

## Tips
- When calculating the start and end of the strike zone, try `round`ing the values to the nearest integer.