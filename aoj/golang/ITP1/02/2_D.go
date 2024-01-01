package main

import (
    "fmt"
)

var (
    w, h int
    x, y int
    r    int
)

func main() {
    fmt.Scanf("%d %d %d %d %d", &w, &h, &x, &y, &r)

    if (x - r < 0) ||
       (w < x + r) ||
       (y - r < 0) ||
       (h < y + r) {
        fmt.Println("No")
    } else {
        fmt.Println("Yes")
    }
}
