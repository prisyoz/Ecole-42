def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
	if unit == "packets":
		print(f"{seed_type}: {quantity} packets available")
	elif unit == "grams":
		print(f"{seed_type}: {quantity} grams total")
	elif unit == "area":
		print(f"{seed_type}: covers {quantity} square meters")
	else:
		print("Unknown unit type")
