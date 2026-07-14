#!/usr/bin/env python3

class Plant:
	def __init__(self, name: str, height: float, old: int) -> None:
		self.name = name
		self._height = height
		self._old = old
	
	def set_height(self, height: float) -> None:
		if (height < 0):
			print(f"{self.name}: Error, height can't be negative\nHeight update rejected")
		else:
			self._height = height
			print(f"Height updated: {self.get_height():.1f}cm")

	def set_age(self, old: int) -> None:
		if (old < 0):
			print(f"{self.name}: Error, age can't be negative\nAge update rejected")
		else:
			self._old = old
			print(f"Age updated: {self.get_age()} days")

	def get_height(self) -> float:
		return self._height
	
	def get_age(self) -> int:
		return self._old

	def show(self) -> None:
		print(f"Plant created: {self.name}: {self.get_height():.1f}cm, {self.get_age()} days old")
	
	def grow(self, growth: float) -> None:
		self._height += growth

	def age(self, day: int, growth: float) -> None:
		for i in range(1, day + 1):
			self.grow(growth)
			self._old += 1
			print(f"=== Day {i} ===")
			print(f"{self.name}: {self._height}cm, {self._old} days old")


class Flower(Plant):
	def __init__(self, name: str, height: float, old: int, colour: str, blooming: bool) -> None:
		super().__init__(name, height, old)
		self.colour = colour
		self.blooming = blooming

	def bloom(self) -> None:
		self.blooming = True

	def show(self) -> None:
		print(f"{self.name}: {self.get_height():.1f}cm, {self.get_age()} days old")
		print(f"Colour: {self.colour}")
		if (self.blooming == False):
			print(f"{self.name} has not bloomed yet")
		else:
			print(f"{self.name} is blooming beautifully!")


class Tree(Plant):
	def __init__(self, name: str, height: float, old: int, trunk: float, shade: bool) -> None:
		super().__init__(name, height, old)
		self.trunk = trunk
		self.shade = shade

	def produce_shade(self, sh_height: float, sh_width: float) -> None:
		self.shade = True
		print(f"{self.name} now produces a shade of {sh_height:.1f}cm long and {sh_width:.1f}cm wide.")

	def show(self) -> None:
		print(f"{self.name}: {self.get_height():.1f}cm, {self.get_age()} days old")
		print(f"Trunk diameter: {self.trunk:.1f}cm")
		if (self.shade == False):
			print(f"{self.name} does not produce shade")


class Vegetable(Plant):
	def __init__(self, name: str, height: float, old: int, harvest: str, nutrition: int) -> None:
		super().__init__(name, height, old)
		self.harvest = harvest
		self.nutrition = nutrition
	
	def show(self) -> None:
		print(f"{self.name}: {self.get_height():.1f}cm, {self.get_age()} days old")
		print(f"Harvest Season: {self.harvest}")
		print(f"Nutritional value: {self.nutrition}")
	
	def age(self, day: int, growth: float) -> None:
		for i in range(1, day + 1):
			super().age(1, growth)
			self.nutrition += 1



if __name__ == "__main__":
	rose = Flower(name="Rose", height=25.5, old=30, colour="red", blooming=False)
	sunflower = Plant(name="Sunflower", height=80, old=45)
	catcus = Plant(name="Catcus", height=15, old=120)
	oak = Tree(name="Oak", height=200, old=365, trunk=5, shade=False)
	fern = Plant(name="Fern", height=15, old=120)
	tomato = Vegetable(name="Tomato", height=5, old=30, harvest="April", nutrition=0)

	print("=== Garden Plant Types ===")
	print("=== Flower")
	rose.show()
	print("[asking the rose to bloom]")
	rose.bloom()
	rose.show()

	print()
	print("=== Tree")
	oak.show()
	print("[asking the oak to produce shade]")
	oak.produce_shade(200, 5)
	
	print()
	print("=== Vegetable")
	tomato.show()
	tomato.age(20, 2.1)
	tomato.show()

