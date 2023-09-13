#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <random>

using namespace std;

// Define a struct named 'Oblong' to represent rectangular objects with specified properties.
struct Oblong {
    double span, elevation; // The width and height of the oblong.
    double a, b; // Center 
    double corner; // Degrees of the corner 
};


double calcOblongCorner(const Oblong& tango) {
    double halfelevation = tango.elevation / 2;
    double halfspan = tango.span / 2;
    double ans = sqrt(halfspan * halfspan + halfelevation * halfelevation);
    return atan2(ans, sqrt(tango.a * tango.a + tango.b * tango.b)) * 180 * 2 / M_PI;
}


double arbitraryMinMax(double min, double max) {
    std::random_device rd;  // Seed generator
    std::mt19937 gen(rd()); // Mersenne Twister pseudo-random generator
    std::uniform_real_distribution<double> dis(min, max);

    return dis(gen);
}

bool doRectanglesOverlap(const Oblong& tango1, const Oblong& tango2) {
    double answerb = abs(tango1.b - tango2.b);
    double answera = abs(tango1.a - tango2.a);
    double semiWidthAggregate = (tango1.span + tango2.span) / 2;
    double semiElevationAggregate = (tango1.elevation + tango2.elevation) / 2;
    return answera <= semiWidthAggregate && answerb <= semiElevationAggregate;
}



int main() {
    int second;
    cout << "Enter the number of rectangles (n): ";
    cin >> second;

    srand(static_cast<unsigned>(time(nullptr)));

    vector<Oblong> oblong;

    for (int first = 0; first < second; ++first) {
        Oblong tango;
        tango.corner = arbitraryMinMax(0.0, 360.0);
        tango.a = arbitraryMinMax(-50.0, 50.0); 
        tango.b = arbitraryMinMax(-50.0, 50.0);      
        tango.elevation = arbitraryMinMax(1.0, 5.0); 
        tango.span = arbitraryMinMax(1.0, 5.0); 

        bool ifIntersecting = false;
        for (const Oblong& existingRect : oblong) {
            if (doRectanglesOverlap(tango, existingRect)) {
                ifIntersecting = true;
                break;
            }
        }

        if (!ifIntersecting) {
            oblong.push_back(tango);
        } else {
            --first; 
        }
    }

   std::ofstream outputFile("anglesForRectangle.csv");
    if (outputFile.is_open()) {


        // Write the rectangle data to the CSV file
        for (const Oblong& rect : oblong) {
            outputFile << rect.a << "," << rect.b << "," << rect.span << "," << rect.elevation << "," << rect.corner << std::endl;
        }
        outputFile.close();
        std::cout << "Rectangle data written to 'anglesForRectangle.csv'" << std::endl;
    } else {
        std::cerr << "Unable to open the output file." << std::endl;
    }

    double allinallCorner = 0.0;
    for (const Oblong& rect : oblong) {
        allinallCorner += calcOblongCorner(rect);
    }

    std::cout << "Total occlusion angle over all rectangles: " << allinallCorner << " degrees" << std::endl;

    return 0;
}

