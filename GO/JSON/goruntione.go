package main

import "fmt"

func sum(numbers []int, resultChan chan int) {
	sum := 0
	for _, number := range numbers {
		sum += number
		// fmt.Println(index)
	}
	resultChan <- sum // 将 sum 发送到结果通道 resultChan
}

func main() {
	numbers := []int{7, 2, 8, -9, 4, 0}

	resultChan := make(chan int)
	go sum(numbers[:len(numbers)/2], resultChan)
	fmt.Println("numbers half is ", numbers[:len(numbers)/2])
	go sum(numbers[len(numbers)/2:], resultChan)
	fmt.Println("numbers half is ", numbers[len(numbers)/2:])
	firstHalfSum, secondHalfSum := <-resultChan, <-resultChan // 从结果通道 resultChan 中接收

	totalSum := firstHalfSum + secondHalfSum
	fmt.Println(firstHalfSum, secondHalfSum, totalSum)
	fmt.Scanln()
}
