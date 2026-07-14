def ft_count_harvest_recursive(day=1, harvest=None):
	if harvest is None:
		harvest = int(input("Days until harvest: "))

	if (day > harvest):
		print("Harvest time!")
		return
	print(f"Day {day}")
	ft_count_harvest_recursive(day + 1, harvest)


