package main

import (
    "fmt"
)

func main() {
    var a, b, c int
    fmt.Scan(&a, &b, &c)

    var ans int

    for i := a; i <= b; i++ {
        if (c % i == 0){
            ans++
        }
    }

    fmt.Println(ans)
}