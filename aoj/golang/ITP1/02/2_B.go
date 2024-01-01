package main

import(
    "fmt"
)

var(
    a, b, c int64
)

func main(){
    fmt.Scanf("%d %d %d", &a, &b, &c)

    if a < b && b < c {
        fmt.Println("Yes")
    } else{
        fmt.Println("No")
    }
}