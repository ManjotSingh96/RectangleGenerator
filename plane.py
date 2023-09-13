import matplotlib.pyplot as plt
import matplotlib.patches as patches
import csv

# Initialize lists to store rectangle information
x_coords = []
y_coords = []
widths = []
heights = []

# Read rectangle data from the CSV file
with open('anglesForRectangle.csv', 'r') as csvfile:
    csvreader = csv.reader(csvfile)
    for row in csvreader:
        x = float(row[0])
        y = float(row[1])
        width = float(row[2])
        height = float(row[3])
        x_coords.append(x)
        y_coords.append(y)
        widths.append(width)
        heights.append(height)

# Create a figure and axis
fig, ax = plt.subplots()

# Add rectangles to the plot
for x, y, width, height in zip(x_coords, y_coords, widths, heights):
    rect = patches.Rectangle((x - width / 2, y - height / 2), width, height, linewidth=1, edgecolor='blue', facecolor='none')
    ax.add_patch(rect)

# Set axis labels and title
plt.xlabel('X Coordinate')
plt.ylabel('Y Coordinate')
plt.title('Rectangles on the Graph')

# Set axis limits based on the data
plt.xlim(min(x_coords) - max(widths), max(x_coords) + max(widths))
plt.ylim(min(y_coords) - max(heights), max(y_coords) + max(heights))

# Show the plot
plt.grid(True)
plt.show()


