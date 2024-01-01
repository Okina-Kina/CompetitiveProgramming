package main

import (
  "fmt"
  "math"
)

func main()  {
  var x int64
  fmt.Scanf("%d", &x)

  var ans int64 = int64(math.Pow(float64(x), 3))

  fmt.Println(ans)
}