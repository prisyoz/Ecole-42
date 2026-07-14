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


def water_plant(plant_name: str) -> None:
	if plant_name == plant_name.capitalize():
		print(f"Watering {plant_name}: [OK]")
	else:
		raise PlantError(f"Invalid plant name to water: '{plant_name}'")

def test_watering_system(name1: str, name2: str, name3: str) -> None:
	print("Opening watering system")
	try:
		water_plant(name1)
		water_plant(name2)
		water_plant(name3)
	except PlantError as e:
		print(f"Caught PlantError: {e}")
		print("... ending tests and returning to main")
	finally:
		print("Closing watering systems")



if __name__ == "__main__":
	print("=== Garden Watering System ===")
	
	print("Testing valid plants")
	test_watering_system("Tomato", "Lettuce", "Carrots")
	print("")
	
	print("Testing invalid plants")
	test_watering_system("Tomato", "lettuce", "CARROTS")
	print("")
	print("Cleanup always happens, even with errors!")