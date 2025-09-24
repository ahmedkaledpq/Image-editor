#include <iostream>
#include "Image_Class.h"


using namespace std;



    Image rotatedImage(image.height, image.width);
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                rotatedImage(j, image.width - 1 - i, k) = image(i, j, k);
            }
        }
    }
    image = rotatedImage;
    image.saveImage("270.jpg");
}

int main() {
    
    
    return 0;
}
