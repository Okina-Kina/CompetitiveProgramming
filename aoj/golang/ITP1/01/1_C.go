package main

import(
    "fmt"
)

var (
    a, b int64
    area, length int64
)

func main(){
    fmt.Scanf("%d %d", &a, &b)

    area = a * b
    length = a * 2 + b * 2

    fmt.Println(area, length)
}