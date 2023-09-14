AlgorithmsAndComplexity.cpp generates a set of non-overlapping rectangular objects called "Oblongs" with random properties, including width, height, coordinates, and corner angles. The code ensures that these "Oblongs" (Rectangles) do not overlap by checking for intersections with previously generated ones. It then calculates the total occlusion angle created by all these rectangles and stores their data in a CSV file. The Python program (plane.py) reads this data and uses Matplotlib to create a graphical representation of the Rectangles on a corrdinate plane. The user can visualize the non-overlapping rectangles and analyze their positions.

Steps on how to use this code:
	1. The user should input "make run"
	2. The program is going to ask "Enter the number of rectangles: "
	3. The user can input the number he/she desires
	4. The program will give the user of the total occlusion angle
	5. The program will make a .cvv file that will contain the height, width, coordinates, and corner angles.
	6. Once that runs, the user will have to type "python3 plane.py" which will show the matplot of the rectangles
