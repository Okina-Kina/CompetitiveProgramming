package main

import(
    "fmt"
)

var(
    n int64
    h, m, s int64
)

func main(){
    fmt.Scanf("%d", &n)

    h = n/3600
    m = (n/60) % 60
    s = n% 60

    fmt.Print(h, ":", m, ":", s, "\n")
}