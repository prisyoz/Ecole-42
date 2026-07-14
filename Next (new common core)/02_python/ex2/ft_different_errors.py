#!/usr/env python3

def garden_operations(operation_number: int) -> None:
	match operation_number:
		case 0:
			int("abc")
		case 1:
			1 / 0
		case 2:
			open("/non/existent/file", "r")
		case 3:
			"string" + 42
		case _:
			pass
		
def test_error_types() -> None:
	print("=== Garden Error Types Demo ===")
	for i in range(5):
		print(f"Testing operation {i}...")
		try:
			garden_operations(i)
		except ValueError as e:
			print(f"Caught ValueError: {e}")
		except ZeroDivisionError as e:
			print(f"Caught ZeroDivisionError: {e}")
		except FileNotFoundError as e:
			print(f"Caught FileNotFoundError: {e}")
		except TypeError as e:
			print(f"Caught TypeError: {e}")
		else:
			print("Operator completed successfully")
	print("")
	print("All error types tested successfully!")

if __name__ == "__main__":
	test_error_types()

# Example:
# $> python3 ft_different_errors.py
# === Garden Error Types Demo ===
# Testing operation 0...
# Caught ValueError: invalid literal for int() with base 10: 'abc'
# Testing operation 1...
# Caught ZeroDivisionError: division by zero
# Testing operation 2...
# Caught FileNotFoundError: [Errno 2] No such file or directory: '/non/existent/file'
# Testing operation 3...
# Caught TypeError: can only concatenate str (not "int") to str
# Testing operation 4...
# Operation completed successfully
# All error types tested successfully!