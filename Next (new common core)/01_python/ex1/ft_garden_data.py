#!/usr/bin/env python3

class Plant:
	def __init__(self, name: str, height: float, age: int) -> None:
		self.name = name
		self.height = height
		self.age = age

	def show(self) -> None:
		print(f"{self.name}: {self.height}cm, {self.age} days old")

if __name__ == "__main__":
	rose = Plant(name="Rose", height=25.5, age=30)
	sunflower = Plant(name="Sunflower", height=80, age=45)
	catcus = Plant(name="Catcus", height=15, age=120)

	print("=== Garden Plant Registry ===")
	rose.show()
	sunflower.show()
	catcus.show()
