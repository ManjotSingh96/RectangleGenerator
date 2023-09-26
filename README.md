# Rectangle Generator and Visualizer

This program generates a set of non-overlapping rectangular objects called "Oblongs" with random properties, including width, height, coordinates, and corner angles. It then calculates the total occlusion angle created by all these rectangles and stores their data in a CSV file. The provided Python program reads this data and uses Matplotlib to create a graphical representation of the Rectangles on a coordinate plane. This allows users to visualize the non-overlapping rectangles and analyze their positions.

## Getting Started

These instructions will help you run the code and visualize the generated rectangles.

### Prerequisites

You will need a C++ compiler and Python with Matplotlib installed to run this code.

### Running the Code

1. Clone this repository to your local machine:

    ```shell
    git clone https://github.com/your_username/RectangleGenerator.git
    ```

2. Change to the project directory:

    ```shell
    cd RectangleGenerator
    ```

3. Compile and run the C++ program by entering the following command:

    ```shell
    make run
    ```

4. The program will prompt you with "Enter the number of rectangles: ". Input the desired number of rectangles and press Enter.

5. The program will display the total occlusion angle created by all the rectangles.

6. It will also generate a CSV file containing data about the rectangles, including their height, width, coordinates, and corner angles.

7. After running the C++ program, you can visualize the rectangles by executing the Python script:

    ```shell
    python3 plane.py
    ```

8. This will display a graphical representation of the non-overlapping rectangles on a coordinate plane.
