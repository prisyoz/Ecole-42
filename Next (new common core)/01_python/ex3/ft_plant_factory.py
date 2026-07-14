#!/usr/bin/env python3

class Plant:
	def __init__(self, name: str, height: float, old: int) -> None:
		self.name = name
		self.height = height
		self.old = old

	def show(self) -> None:
		print(f"Created: {self.name}: {self.height:.1f}cm, {self.old} days old")
	
	def grow(self, growth: float) -> None:
		self.height += growth

	def age(self, day: int, growth: float) -> None:
		for i in range(1, day + 1):
			self.grow(growth)
			self.old += 1
			print(f"=== Day {i} ===")
			print(f"{self.name}: {self.height}cm, {self.old} days old")


		



if __name__ == "__main__":
	rose = Plant(name="Rose", height=25.5, old=30)
	sunflower = Plant(name="Sunflower", height=80, old=45)
	catcus = Plant(name="Catcus", height=15, old=120)
	oak = Plant(name="Oak", height=200, old=365)
	fern = Plant(name="Fern", height=15, old=120)

	print("=== Plant Factory Output ===")
	rose.show()
	sunflower.show()
	catcus.show()
	oak.show()
	fern.show()

