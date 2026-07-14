#!/usr/env python3

def input_temperature(temp_str: str) -> int:
	return int(temp_str)


def test_temperature(temp_str: str) -> None:
	print(f"Input data is '{temp_str}'")
	try:
		value = input_temperature(temp_str)
		print(f"Temperature is now {value}\N{DEGREE SIGN}C\n")
	except ValueError as e:
		print(f"{e}\n")


if __name__ == "__main__":
	print("=== Garden Temperatur ===")
	test_temperature("123")
	test_temperature("abc")
	test_temperature("123a")
	test_temperature("1234#")
	test_temperature("-1")
	test_temperature("0")
	test_temperature("-54")
	print("All tests completed - program didn't crash")
