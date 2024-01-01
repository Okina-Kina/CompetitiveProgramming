package main

import (
    "fmt"
)

func main() {
    var x   []int
    var tmp   int

    // input
    for {
        fmt.Scan(&tmp)
        if (tmp == 0) {
            break
        }

        x = append(x, tmp)
    }

    for i := 0; i < len(x); i++ {
        fmt.Print("Case ", i + 1, ": ", x[i], "\n")
    }
}