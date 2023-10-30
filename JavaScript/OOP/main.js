class Person {
	name;

	constructor(name) {
		this.name = name;
	}

	introduceSelf() {
		console.log(`Hi! I'm ${this.name}`);
	}
}
const giles = new Person("Giles");

giles.introduceSelf(); // Hi! I'm Giles

class Professor extends Person {
	teaches;

	constructor(name, teaches) {
		super(name); //super(name); = this.name = name;调用父类的构造函数
		//super()必须在使用this之前调用
		//否则会报错:ReferenceError: Must call super constructor in derived class before accessing 'this' or returning from derived constructor
		this.teaches = teaches;
	}

	introduceSelf() {
		console.log(
			`My name is ${this.name}, and I will be your ${this.teaches} professor.`
		);
	}

	grade(paper) {
		const grade = Math.floor(Math.random() * (5 - 1) + 1);
		console.log(grade);
	}
}
const walsh = new Professor("Walsh", "Psychology");
walsh.introduceSelf(); // 'My name is Walsh, and I will be your Psychology professor'

walsh.grade("my paper"); // some random grade

class Student extends Person {
	#year; //相当于private,只能在class内部使用,私有属性

	constructor(name, year) {
		super(name);
		this.#year = year;
	}

	introduceSelf() {
		console.log(`Hi! I'm ${this.name}, and I'm in year ${this.#year}.`);
	}

	canStudyArchery() {
		return this.#year > 1;
	}
}

const summers = new Student("Summers", 2);

summers.introduceSelf(); // Hi! I'm Summers, and I'm in year 2.
summers.canStudyArchery(); // true
console.log("summers.canStudyArchery();::: ", summers.canStudyArchery());
