package main

import(
    "fmt"
)

var(
    a, b int64
)

func main(){
    fmt.Scanf("%d %d", &a, &b)

    if b < a {
        fmt.Println("a > b")
    } else if a < b {
        fmt.Println("a < b")
    } else {
        fmt.Println("a == b")
    }
}