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


		



if __name__ == "__main__":
	rose = Plant(name="Rose", height=25.5, old=30)
	sunflower = Plant(name="Sunflower", height=80, old=45)
	catcus = Plant(name="Catcus", height=15, old=120)
	oak = Plant(name="Oak", height=200, old=365)
	fern = Plant(name="Fern", height=15, old=120)

	print("=== Plant Security System ===")
	rose.show()
	print("")
	rose.set_height(45)
	rose.set_age(3)
	print("")
	rose.set_height(-5)
	rose.set_age(-3)
	print("")
	print(f"Current status: {rose.name}: {rose.get_height():.1f}cm, {rose.get_age()} days old")



