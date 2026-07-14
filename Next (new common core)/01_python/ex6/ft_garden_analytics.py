#!/usr/bin/env python3

class Plant:
	def __init__(self, name: str, height: float, old: int, tgrow: int, told: int, tshow: int) -> None:
		self.name = name
		self._height = height
		self._old = old
		self.tgrow = tgrow
		self.told = told
		self.tshow = tshow
	
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
		self.tshow += 1
		print(f"{self.name}: {self.get_height():.1f}cm, {self.get_age()} days old")
		print(f"[statistics for {self.name}]\nStats: {self.tgrow} grow, {self.told} age, {self.tshow} show")
	
	def grow(self, growth: float) -> None:
		self._height += growth
		self.tgrow += 1

	def age(self, day: int, growth: float) -> None:
		for i in range(1, day + 1):
			self.grow(growth)
			self._old += 1
		self.told += 1

	@classmethod
	def unknown_plant(cls, name: str = "Unknown Plant", height: float = 0, old: int = 0, tgrow: int = 0, told: int = 0, tshow: int = 0) -> "Plant":
		return cls(name=name, height=height, old=old, tgrow=tgrow, told=told, tshow=tshow)

	@staticmethod
	def check_age(day: int) -> None:
		if day > 365:
			print(f"Is {day} days more than a year? -> True")
		else:
			print(f"Is {day} days more than a year? -> False")


class Flower(Plant):
	def __init__(self, name: str, height: float, old: int, colour: str, blooming: bool, tgrow: int, told: int, tshow: int) -> None:
		super().__init__(name, height, old, tgrow, told, tshow)
		self.colour = colour
		self.blooming = blooming

	def bloom(self) -> None:
		self.blooming = True

	def show(self) -> None:
		self.tshow += 1
		print(f"{self.name}: {self.get_height():.1f}cm, {self.get_age()} days old")
		print(f"Colour: {self.colour}")
		if (self.blooming == False):
			print(f"{self.name} has not bloomed yet")
		else:
			print(f"{self.name} is blooming beautifully!")
		print(f"[statistics for {self.name}]\nStats: {self.tgrow} grow, {self.told} age, {self.tshow} show")

class Seed(Flower):
	def __init__(self, name: str, height: float, old: int, colour: str, blooming: bool, seeding: int, tgrow: int, told: int, tshow: int) -> None:
		super().__init__(name, height, old, colour, blooming, tgrow, told, tshow)
		self.seed = seeding

	def age(self, day: int, growth: float) -> None:
		super().age(day, growth)
		self.seed += (day * 2)

	def show(self) -> None:
		self.tshow += 1
		print(f"{self.name}: {self.get_height():.1f}cm, {self.get_age()} days old")
		print(f"Colour: {self.colour}")
		if (self.blooming == False):
			print(f"{self.name} has not bloomed yet")
		else:
			print(f"{self.name} is blooming beautifully!")
		print(f"Seeds: {self.seed}")
		print(f"[statistics for {self.name}]\nStats: {self.tgrow} grow, {self.told} age, {self.tshow} show")


class Tree(Plant):
	def __init__(self, name: str, height: float, old: int, trunk: float, shade: bool, tgrow=0, told=0, tshow=0, shading=0) -> None:
		super().__init__(name, height, old, tgrow, told, tshow)
		self.trunk = trunk
		self.shade = shade
		self.shading = shading

	def produce_shade(self, sh_height: float, sh_width: float) -> None:
		self.shade = True
		self.shading += 1
		print(f"Tree {self.name} now produces a shade of {sh_height:.1f}cm long and {sh_width:.1f}cm wide.")

	def show(self) -> None:
		self.tshow += 1
		print(f"{self.name}: {self.get_height():.1f}cm, {self.get_age()} days old")
		print(f"Trunk diameter: {self.trunk:.1f}cm")
		# if (self.shade == False):
		# 	print(f"{self.name} does not produce shade")
		print(f"[statistics for {self.name}]\nStats: {self.tgrow} grow, {self.told} age, {self.tshow} show. {self.shading} shade")


class Vegetable(Plant):
	def __init__(self, name: str, height: float, old: int, harvest: str, nutrition: int, tgrow=0, told=0, tshow=0) -> None:
		super().__init__(name, height, old, tgrow, told, tshow)
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
	rose = Flower(name="Rose", height=25.5, old=30, colour="red", blooming=False, tgrow=0, told=0, tshow=0)
	sunflower = Seed(name="Sunflower", height=80, old=45, colour="yellow", blooming=False, seeding=0, tgrow=0, told=0, tshow=0)
	# catcus = Plant(name="Catcus", height=15, old=120, tgrow=0, told=0, tshow=0)
	oak = Tree(name="Oak", height=200, old=365, trunk=5, shade=False, tgrow=0, told=0, tshow=0)
	# fern = Plant(name="Fern", height=15, old=120, tgrow=0, told=0, tshow=0)
	# tomato = Vegetable(name="Tomato", height=5, old=30, harvest="April", nutrition=0, tgrow=0, told=0, tshow=0)
	unknown = Plant.unknown_plant("Unknown plant", height=0, old=0, tgrow=0, told=0, tshow=0)

	print("===  Garden statistics ===")
	print("=== Check year-old")
	Plant.check_age(day=30)
	Plant.check_age(day=400)

	print("\n=== Flower")
	rose.show()
	print("[asking the rose to grow and bloom]")
	rose.grow(23)
	rose.show()

	print("\n=== Tree")
	oak.show()
	print("[asking the oak to produce shade]")
	oak.produce_shade(200, 5)
	oak.show()

	print("\n=== Seed")
	sunflower.show()
	print("[make sunflower grow, age and bloom]")
	sunflower.bloom()
	sunflower.age(20, 1.5)
	sunflower.show()

	print("\n=== Anonymous")
	unknown.show()
	