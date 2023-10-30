package main

import "fmt"

func main() {
	fmt.Print("请输入您的姓名和年龄，以空格分隔：")
	var name string
	var age int
	fmt.Scanln(&name, &age)
	fmt.Printf("您输入的姓名是：%s，年龄是：%d\n", name, age)
	fmt.Scanln()
}
