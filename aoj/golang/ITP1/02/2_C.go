package main

import(
    "fmt"
    "sort"
)

var(
    n []int64
    tmp int64
)

func main(){
    for i := 0; i < 3; i++ {
        fmt.Scan(&tmp)
        n = append(n, tmp)
    }

    sort.Slice(n, func(i,j int64) bool {
        return n[i] < n[j]
    })

    for i, num := range n {
        fmt.Print(num)
        if i != 2 {
            fmt.Print(" ")
        } else {
            fmt.Println()
        }
    }
}

