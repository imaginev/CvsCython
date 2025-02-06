package main

import (
	"fmt"
	"math"
	"time"
)

func normalDistribution(x, nx, o float64) float64 {
	denominator := o * math.Sqrt(2*math.Pi)
	z := (x - nx) / o
	return (1.0 / denominator) * math.Exp(-0.5*math.Pow(z, 2))
}

func F(b float64, n int) float64 {
	a := 0.0
	dx := (b - a) / float64(n)
	sum := 0.0

	for i := 0; i < n; i++ {
		xi := a + float64(i)*dx
		sum += normalDistribution(xi, 0.0, 1.0) * dx
	}
	return sum
}

func calculate(ei, es, nx, o float64, n int) {
	t2 := (es - nx) / o
	t1 := (ei - nx) / o
	pSuitable := (F(t2, n) - F(t1, n)) * 100.0
	_ = pSuitable

	t2 = (ei - nx) / o
	t1 = -3.0
	pIncorrigible := (F(t2, n) - F(t1, n)) * 100.0
	_ = pIncorrigible

	t2 = 3.0
	t1 = (es - nx) / o
	pFixable := (F(t2, n) - F(t1, n)) * 100.0
	_ = pFixable
}

func testNormalDist(cycles int) float64 {
	start := time.Now()

	for i := 0; i < cycles; i++ {
		increment := float64(i / 10000)
		calculate(
			0.006+increment,
			0.055+increment,
			0.026+increment,
			0.012+increment,
			10000,
		)
	}

	elapsed := time.Since(start).Seconds()
	fmt.Printf("Time: %.9f seconds\n", elapsed)
	return elapsed
}

func main() {
	const cycles = 1000
	const tests = 10
	var totalTime float64

	for i := 0; i < tests; i++ {
		totalTime += testNormalDist(cycles)
	}

	fmt.Printf("Average time: %.9f seconds\n", totalTime/float64(tests))
}
