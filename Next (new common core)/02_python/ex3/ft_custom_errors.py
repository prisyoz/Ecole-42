#!/usr/env python3

class GardenError(Exception):
	""" Basic error for garden problems """
	pass

class PlantError(GardenError):
	""" For problems with plants """
	pass

class WaterError(GardenError):
	""" For problems with watering """
	pass


def test_error_types() -> None:
	print("=== Custom Garden Errors Demo ===")

	print("Testing PlantError...")
	try:
		raise PlantError(f"The tomato plant is wilting!")
	except PlantError as e:
		print(f"Caught PlantError: {e}")

	print()

	print("Testing WaterError...")
	try:
		raise WaterError(f"Not enough water in the tank!")
	except WaterError as e:
		print(f"Caught WaterError: {e}")

	print()

	print("Testing catching all garden errors...")
	try:
		raise PlantError(f"The tomato plant is wilting!")
	except GardenError as e:
		print(f"Caught GardenError: {e}")


	print("Testing WaterError...")
	try:
		raise WaterError(f"Not enough water in the tank!")
	except GardenError as e:
		print(f"Caught GardenError: {e}")



if __name__ == "__main__":
	test_error_types()