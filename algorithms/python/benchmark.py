import time

def readNumbersFromFile (numbers):
	file = open("../numbers/numbers%d.txt" % len(numbers), "r")
	text = file.read();

	i = 0
	for word in text.split():
		numbers[i] = int(word)
		i = i + 1

def selectionSort (numbers):
	for i in range (0, len(numbers) - 1):
		minInd = i
		for j in range (i + 1, len(numbers)):
			if numbers[j] < numbers[minInd]:
				minInd = j

		tempVal = numbers[minInd]
		numbers[minInd] = numbers[i]
		numbers[i] = tempVal


# Program for Selection Sort in python
def main():
	size = 100000

	numbers = [0] * size

	print "Size of array: %d" % size

	readNumbersFromFile(numbers)

	# Get init time
	timeStart = time.time()

	# Sort
	selectionSort(numbers)

	# Get final time
	timeEnd = time.time()

	print "The task has taken  %f seconds" % (timeEnd - timeStart)

	# print(numbers)


main()