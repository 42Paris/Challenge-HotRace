if __name__ == "__main__":
	master_dict = {}
	while True:
		try:
			line = input()
		except:
			break
		if "=" in line:
			master_dict[line.split("=")[0]] = "".join(line.split("=")[1:])
		elif line.startswith("!"):
			try:
				master_dict.pop(line[1:])
			except:
				pass
		else:
			try:
				print(master_dict[line])
			except:
				print(line + ": Not found")
	