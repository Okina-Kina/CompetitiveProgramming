package main

import (
    "fmt"
)

func main() {
    var x, y    []int
    var tmpX, tmpY int = 1, 1

    for {
        fmt.Scanf("%d %d", &tmpX, &tmpY)

        if tmpX == 0 && tmpY == 0 {
            break
        }

        x = append(x, tmpX)
        y = append(y, tmpY)
    }

    for i := 0; i < len(x); i++ {
        if (x[i] < y[i]) {
            fmt.Println(x[i], y[i])
        } else {
            fmt.Println(y[i], x[i])
        }
    }
}