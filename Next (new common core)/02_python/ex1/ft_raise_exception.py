#!/usr/env python3

def input_temperature(temp_str: str) -> int:
	try:
		value = int(temp_str)
	except ValueError:
		raise ValueError(f"Caught input_temperature error: invalid literal for int() with base 10: {temp_str}\n")
	
	if 0 > value:
		raise ValueError(f"Caught input_temperature error: {value}\N{DEGREE SIGN}C is too cold for plants (min 0\N{DEGREE SIGN})")
	elif value > 40:
		raise ValueError(f"Caught input_temperature error: {value}\N{DEGREE SIGN}C is too hot for plants (max 40\N{DEGREE SIGN})")
	return value


def test_temperature(temp_str: str) -> None:
	print(f"Input data is '{temp_str}'")
	try:
		value = input_temperature(temp_str)
		print(f"Temperature is now {value}\N{DEGREE SIGN}C\n")
	except ValueError as e:
		print(f"{e}\n")
		# print(f"Caught input_temperature error: invalid literal for int() with base 10: {temp_str}\n")


if __name__ == "__main__":
	print("=== Garden Temperatur ===")
	test_temperature("21")
	test_temperature("40")
	test_temperature("123")
	test_temperature("abc")
	test_temperature("123a")
	test_temperature("1234#")
	test_temperature("-1")
	test_temperature("0")
	test_temperature("-54")
	print("All tests completed - program didn't crash")
