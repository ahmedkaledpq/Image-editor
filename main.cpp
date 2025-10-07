//This C++ program is a simple image editor It lets you: 
//Flip images (horizontal/vertical) , Rotate (90°, 180°, 270°) , Convert to black & white , Convert to grayscale , Add a frame to an image , Blur images
//Invert colors (negative), It shows a menu, asks for the image file, applies the chosen operation and lets you save the result with a new name.
// Students details:
// student 1: seif mohamed , id: 20240269 , filters: invert image colors , rotate image , blur image and add a frame to an image 
// student 2: ahmed tamer , id:20240019 , filters: merge images and grayscale conversion
// student 3: ahmed khaled , id: 20240027 , filters: blackandwhite image and flip image and crop image and resize image
// section: s13
#include <iostream>
#include "Image_Class.h"


using namespace std;
void resizeImage(Image &image) {
    int newWidth, newHeight;

    cout << "Enter new width: ";
    cin >> newWidth;
    cout << "Enter new height: ";
    cin >> newHeight;

    if (newWidth <= 0 || newHeight <= 0) {
        cout << "Error: Invalid dimensions!" << endl;
        return;
    }

    Image resized(newWidth, newHeight);

  double x_ratio = static_cast<double>(image.width) / newWidth;
    double y_ratio = static_cast<double>(image.height) / newHeight;

    for (int j = 0; j < newHeight; ++j) {
        for (int i = 0; i < newWidth; ++i) {
            int srcX = static_cast<int>(i * x_ratio);
            int srcY = static_cast<int>(j * y_ratio);
            for (int k = 0; k < 3; ++k) {
                resized(i, j, k) = image(srcX, srcY, k);
            }
        }
    }

    cout << "Image resized successfully from " 
         << image.width << "x" << image.height 
         << " to " << newWidth << "x" << newHeight << "!\n";

    cout << "If you want to save, enter 1 else 0: ";
    int save;
    cin >> save;

    if (save == 1) {
        string filename;
        cout << "Enter the name of the new image with its extension: ";
        cin >> filename;
        resized.saveImage(filename);
        cout << "Image saved successfully!\n";
    } else {
        cout << "Image not saved.\n";
    }
}
void cropImage(Image &image) {
    int x, y, nWidth, nHeight;

    cout << "Enter starting x (left): ";
    cin >> x;
    cout << "Enter starting y (top): ";
    cin >> y;
    cout << "Enter new width: ";
    cin >> nWidth;
    cout << "Enter new height: ";
    cin >> nHeight;

    if (x < 0 || y < 0 || x + nWidth > image.width || y + nHeight > image.height) {
        cout << "Error: Crop dimensions exceed image boundaries!" << endl;
        return;
    }

    Image cropped(nWidth, nHeight);

    for (int j = 0; j < nHeight; ++j) {
        for (int i = 0; i < nWidth; ++i) {
            for (int k = 0; k < 3; ++k) { 
                cropped(i, j, k) = image(x + i, y + j, k);
            }
        }
    }

    cout << "Cropping done successfully!\n";

    cout << "If you want to save, enter 1 else 0: ";
    int save;
    cin >> save;

    if (save == 1) {
        string filename;
        cout << "Enter the name of the new image with its extension: ";
        cin >> filename;
        cropped.saveImage(filename);
        cout << "Image saved successfully!\n";
    } else {
        cout << "Image not saved.\n";
    }
}

void blurImage(Image &image) {
   
    Image blurred(image.width, image.height);

    
    int r;
    cout << "Enter blur radius between 2 and 10: ";
    cin >> r;
    if (r < 2 || r > 10) {
        cout << "Invalid radius. Setting to default value of 5.\n";
        r = 5;
    }
    
    for (int x = 0; x < image.width; ++x) {
        for (int y = 0; y < image.height; ++y) {
            int sum_r = 0, sum_g = 0, sum_b = 0;
            int count = 0;

        
            for (int i = -r; i <= r; ++i) {
                for (int j = -r; j <= r; ++j) {
                    int nx = x + i;
                    int ny = y + j;

                    if (nx < 0 || nx >= image.width || ny < 0 || ny >= image.height)
                        continue;
                    
                   
                    sum_r += image(nx, ny, 0);
                    sum_g += image(nx, ny, 1);
                    sum_b += image(nx, ny, 2);
                    count++;
                }
            }

           
            blurred(x, y, 0) = sum_r / count;
            blurred(x, y, 1) = sum_g / count;
            blurred(x, y, 2) = sum_b / count;
        }
    }

    
    for (int x = 0; x < image.width; ++x) {
        for (int y = 0; y < image.height; ++y) {
            for (int k = 0; k < 3; ++k) {
                image(x, y, k) = blurred(x, y, k);
            }
        }
    }

    cout << "If you want to save, enter 1 else 0: ";
    int save;
    cin >> save;
    if (save == 1) {
        string s;
        cout << "Enter the name of the new image with its extension: ";
        cin >> s;
        image.saveImage(s);
        cout << "Image saved successfully!\n";
    } else {
        cout << "Image not saved.\n";
    }
}
void addDecoratedFrame(Image &image) {
   
         
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = (255, 0, 0); 
                 
            }
           
        }
    }
    
    
    for (int i = 0; i < image.width; ++i) {
        for (int j = image.height - 10; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = (255, 0, 0); 
                 
            }
           
        }
    }
    
    
    for (int i = 0; i < 10 ; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = (255, 0, 0); 
                 
            }
          
        }
    }
    
    
    for (int i = image.width - 10; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = (255, 0, 0); 
                 
            }
        }
    }
        

for (int i = 10; i < image.width - 10; ++i) {
    for (int j = 10; j < 15; ++j) {
        for (int k = 0; k < 3; ++k) {
            image(i, j, k) = 255; 
        }
    }
}

for (int i = 10; i < image.width - 10; ++i) {
    for (int j = image.height - 15; j < image.height - 10; ++j) {
        for (int k = 0; k < 3; ++k) {
            image(i, j, k) = 255; 
        }
    }
}

for (int i = 10; i < 15; ++i) {
    for (int j = 10; j < image.height - 10; ++j) {
        for (int k = 0; k < 3; ++k) {
            image(i, j, k) = 255;
        }
    }
}

for (int i = image.width - 15; i < image.width - 10; ++i) {
    for (int j = 10; j < image.height - 10; ++j) {
        for (int k = 0; k < 3; ++k) {
            image(i, j, k) = 255;
        }
    }
}

    
    cout << "If you want to save, enter 1 else 0: ";
    int save;
    cin >> save;
    if (save == 1) {
        string s;
        cout << "Enter the name of the new image with its extension: ";
        cin >> s;
        image.saveImage(s);
        cout << "Image saved successfully!\n";
    } else {
        cout << "Image not saved.\n";
    }
}
void addSimpleFrame(Image &image) {
    
    
    
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = (255, 0, 0); 
                 
            }
           
        }
    }
    
    
    for (int i = 0; i < image.width; ++i) {
        for (int j = image.height - 10; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = (255, 0, 0); 
                 
            }
           
        }
    }
    
    
    for (int i = 0; i < 10 ; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = (255, 0, 0); 
                 
            }
          
        }
    }
    
    
    for (int i = image.width - 10; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = (255, 0, 0); 
                 
            }
        }
    }
    
    cout << "If you want to save, enter 1 else 0: ";
    int save;
    cin >> save;
    if (save == 1) {
        string s;
        cout << "Enter the name of the new image with its extension: ";
        cin >> s;
        image.saveImage(s);
        cout << "Image saved successfully!\n";
    } else {
        cout << "Image not saved.\n";
    }
}
void flipImage(Image &image, const string &direction) {
    if(direction == "h") {
     for(int j = 0; j < image.height; ++j) {
            for(int i = 0; i < image.width / 2; ++i) {
                for(int k = 0; k < 3; ++k) {
                    swap(image(i, j, k), image(image.width - 1 - i, j, k));
                }
            }
        }
    } else if(direction == "v") {
        for(int i = 0; i < image.width; ++i) {
            for(int j = 0; j < image.height / 2; ++j) {
                for(int k = 0; k < 3; ++k) {
                    swap(image(i, j, k), image(i, image.height - 1 - j, k));
                }
            }
        }
    } else {
        cout << "Error: Unknown flip direction. Use 'h' for horizontal or 'v' for vertical." << endl;
        return;
    }

    cout << "If you want to save, enter 1 else 0: ";
    int save;
    cin >> save;
    if(save == 1){
        string s;
        cout << "Enter the name of the new image with its extension: ";
        cin >> s;
        image.saveImage(s);
        cout << "Image saved successfully!\n";
    } else {
        cout << "Image not saved.\n";
    }
}


void convertToBlackAndWhite(Image &image, int threshold = 128) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned int avg = 0;

            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k);
            }
            avg /= 3;

            unsigned int bw = (avg > threshold) ? 255 : 0;

            image(i, j, 0) = bw;
            image(i, j, 1) = bw;
            image(i, j, 2) = bw;
        }
    }
      cout<<"if you wanna save enter 1 else 0: ";
    int save;
    cin>>save;
    if (save==1){
        string s;
        cout<<"enter the name of the new image with its extension: ";
        cin>>s;
      image.saveImage(s);
    }
    else{
        cout<<"image not saved\n";
    }
}



void flipcolor(Image &image) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = 255 - image(i, j, k);
            }
        }
    }
    cout<<"if you wanna save enter 1 else 0: ";
    int save;
    cin>>save;
    if (save==1){
        string s;
        cout<<"enter the name of the new image with its extension: ";
        cin>>s;
      image.saveImage(s);
    }
    else{
        cout<<"image not saved\n";
    }
}
void rotate90(Image &image) {
    Image rotated(image.height, image.width);
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
               rotated(image.height - 1 - j, i, k) = image(i, j, k);
               
            }
        }
    }
    cout<<"if you wanna save enter 1 else 0: ";
    int save;
    cin>>save;
    if (save==1){
        string s;
        cout<<"enter the name of the new image with its extension: ";
        cin>>s;
      rotated.saveImage(s);
    }
    else{
        cout<<"image not saved\n";
    }
}
void rotate180(Image &image) {
    Image rotated = Image(image.width, image.height);
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                rotated(image.width - 1 - i, image.height - 1 - j, k) = image(i, j, k);
            }
        }
    }
    
       cout<<"if you wanna save enter 1 else 0: ";
    int save;
    cin>>save;
    if (save==1){
        string s;
        cout<<"enter the name of the new image with its extension: ";
        cin>>s;
      rotated.saveImage(s);
    }
    else{
        cout<<"image not saved\n";
    }
}
void rotate270(Image &image) {
    Image rotated = Image(image.height, image.width);
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                
                
                 rotated(j, image.width - 1 - i, k) = image(i, j, k);
            }
        }
    }
    
    
   
        cout<<"if you wanna save enter 1 else 0: ";
    int save;
    cin>>save;
    if (save==1){
        string s;
        cout<<"enter the name of the new image with its extension: ";
        cin>>s;
      rotated.saveImage(s);
    }
    else{
        cout<<"image not saved\n";
    }
}
void convertToGrayscale(string& input_file,string& output_file) {
    Image image(input_file);
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned int avg = 0;
            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k);
            }
            avg /= 3;
            image(i, j, 0) = avg;
            image(i, j, 1) = avg;
            image(i, j, 2) = avg;
        }
    }
    image.saveImage(output_file);
}

void Merge(Image& img) {
    string filename;
    cout << "Enter second image file: ";
    cin >> filename;
    Image img2(filename);
    cout << "Choose merge option:\n";
    cout << "1. Resize smaller image \n";
    cout << "2. Merge the common area\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        int newWidth = max(img.width, img2.width);
        int newHeight = max(img.height, img2.height);
        Image newimg1(newWidth, newHeight);
        Image newimg2(newWidth, newHeight);

        for (int y = 0; y < newHeight; y++) {
            for (int x = 0; x < newWidth; x++) {
                int oldX = x * img.width / newWidth;
                int oldY = y * img.height / newHeight;
                for (int c = 0; c < 3; c++) {
                    newimg1(x, y, c) = img(oldX, oldY, c);
                }
            }
        }

        for (int y = 0; y < newHeight; y++) {
            for (int x = 0; x < newWidth; x++) {
                int oldX = x * img2.width / newWidth;
                int oldY = y * img2.height / newHeight;
                for (int c = 0; c < 3; c++) {
                    newimg2(x, y, c) = img2(oldX, oldY, c);
                }
            }
        }

        for (int y = 0; y < newHeight; y++) {
            for (int x = 0; x < newWidth; x++) {
                for (int c = 0; c < 3; c++) {
                    newimg1(x, y, c) = (newimg1(x, y, c) + newimg2(x, y, c)) / 2;
                }
            }
        }

        img = newimg1;
    }
    else {
        int newWidth = min(img.width, img2.width);
        int newHeight = min(img.height, img2.height);

        for (int y = 0; y < newHeight; y++) {
            for (int x = 0; x < newWidth; x++) {
                for (int c = 0; c < 3; c++) {
                    img(x, y, c) = (img(x, y, c) + img2(x, y, c)) / 2;
                }
            }
        }
    }

    string output;
    cout << "Enter output filename (with extension): ";
    cin >> output;
    img.saveImage(output);
}
void Darken_Lighten(Image& img) {
    double percent;
    int bright;

    cout << "Choose option:\n";
    cout << "1. Lighten image\n";
    cout << "2. Darken image\n";
    cout << "Enter choice: ";
    cin >> bright;

    cout << "Enter percentage (0 - 100): ";
    cin >> percent;

    percent = percent / 100.0;

    for (int i = 0; i < img.width; i++) {
        for (int j = 0; j < img.height; j++) {
            for (int k = 0; k < 3; k++) {
                unsigned char px = img(i, j, k);
                if (bright == 1) {
                    img(i, j, k) = min(255, int(px + (255 - px) * percent));
                } else if (bright == 2) {
                    img(i, j, k) = max(0, int(px * (1 - percent)));
                }
            }
        }
    }
}
void edgeDetection(Image& image) {
    Image newImg(image.width, image.height);

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned int avg = 0;
            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k);
            }
            avg /= 3;
            image(i, j, 0) = avg;
            image(i, j, 1) = avg;
            image(i, j, 2) = avg;
        }
    }

    for (int i = 1; i < image.width - 1; ++i) {
        for (int j = 1; j < image.height - 1; ++j) {

            int current = image(i, j, 0);
            int right = image(i + 1, j, 0);
            int down = image(i, j + 1, 0);

            int gx = abs(current - right);
            int gy = abs(current - down);

            int K = sqrt(gx * gx + gy * gy);

            if (K > 30) {
                newImg(i, j, 0) = 0;
                newImg(i, j, 1) = 0;
                newImg(i, j, 2) = 0;
            } else {
                newImg(i, j, 0) = 255;
                newImg(i, j, 1) = 255;
                newImg(i, j, 2) = 255;
            }
        }
    }

    image = newImg;
}

int main() {
    
    int choice;
    while(true){
      cout << "Menu:\n";
      
      cout << "1. Invert image colors\n";
      cout << "2. Rotate image\n";
      cout << "3. BlackAndWhite\n";
      cout << "4. grey scale image \n";
      cout << "5. flipImage \n";
      cout << "6. Merge image \n";
      cout << "7. Add frame \n";
      cout << "8. Blur image \n";
      cout << "9. Crop Images \n";
      cout << "10. Resize Image \n";
      cout << "11. Darken or Lighten image \n";
      cout << "12. Edge detect for image \n" ;
      cout << "13. Exit\n";
      cout << "Your choice: ";
      cin >> choice;
      switch (choice) {
       

        case 1: {
            string filename;
            cout << "Enter image filename: ";
            cin >> filename;

            Image img(filename);
            if (img.imageData) {
                flipcolor(img);
                cout << "Image colors inverted successfully!\n";

            } else {
                cout << "Failed to load image.\n";
            }
            break;
        }

        case 2: {
           string filename;
           cout << "Enter image filename: ";
           cin >> filename;
           
           cout << "what angle do you want to rotate? (90, 180, 270): ";
           int angle;
              cin >> angle;
            
            if (angle ==90){
              Image img(filename);
              if (img.imageData) {
                  rotate90(img);
                  cout << "Image rotated successfully\n";
              }
            } 
            else if (angle==180){
                Image img(filename);
                if (img.imageData) {
                    rotate180(img);
                    cout << "Image rotated successfully\n";
                }
            }
            else if (angle==270){
                Image img(filename);
                if (img.imageData){
                    rotate270(img);
                    cout << "Image rotated successfully\n";
                }
            }
            break;
        }
    case 3:
        {
            string filename;
            cout << "Enter image filename: ";
            cin >> filename;

            Image img(filename);
            if (img.imageData) {
                convertToBlackAndWhite(img);
                cout << "Image converted to black and white successfully!\n";
            } else {
                cout << "Failed to load image.\n";
            }
            break;
        }
            return 0;
        
        case 4:
              {
            string file, newfile;
            cout << "which file you want to make it grey :" ;
            cin >> file  ;
            cout << "name the new file :" ;
            cin >> newfile;
            convertToGrayscale(file, newfile);
            cout << "Image saved successfully!\n";
                            break;

              }
        case 5:
            {
                string filename, direction;
                cout << "Enter image filename: ";
                cin >> filename;
                cout << "Enter flip direction (h for horizontal, v for vertical): ";
                cin >> direction;

                Image img(filename);
                if (img.imageData) {
                    flipImage(img, direction);
                    cout << "Image flipped successfully!\n";
                } else {
                    cout << "Failed to load image.\n";
                }
                break;
            }
        case 6:
            {
                string filename;
                cout << "Enter first image file: ";
                cin >> filename;
                Image input(filename);
                Merge(input);
                cout << "Image saved successfully!\n";
                return 0;
            }
        case 7:
              {    
                  string filename;
                cout << "Enter image filename: ";
                cin >> filename;

                Image img(filename);
                if (img.imageData) {
                    cout << "Select border type:\n";
                    cout << "1. Simple frame\n";
                    cout << "2. Decorated frame\n";
                    int borderChoice;
                    cin >> borderChoice;
                    
                    if (borderChoice == 1) {
                        addSimpleFrame(img);
                    } else if (borderChoice == 2) {
                        addDecoratedFrame(img);
                    } else {
                        cout << "Invalid choice, applying simple frame by default.\n";
                        addSimpleFrame(img);
                    }
                    cout << "Border added successfully!\n";
                } else {
                    cout << "Failed to load image.\n";
                }
                break;
              }
        case 8:
              {
                    string filename;
                cout << "Enter image filename: ";
                cin >> filename;

                Image img(filename);
                if (img.imageData) {
                    blurImage(img);
                    cout << "Image blurred successfully!\n";
                } else {
                    cout << "Failed to load image.\n";
                }
                break;
              }
        case 9:
            {
                string filename;
                cout << "Enter image filename: ";
                cin >> filename;

                Image img(filename);
                if (img.imageData) {
                    cropImage(img);
                } else {
                    cout << "Failed to load image.\n";
                }
                break;
                                return 0;

            }
        case 10:
            {
                string filename;
                cout << "Enter image filename: ";
                cin >> filename;

                Image img(filename);
                if (img.imageData) {
                    resizeImage(img);
                } else {
                    cout << "Failed to load image.\n";
                }
                break;
                                return 0;

            }
        case 11 :
            {
                string input, output;
                cout << "Enter input image name: ";
                cin >> input;
                Image img(input);
            
                cout << "Enter output image name: ";
                cin >> output;
            
                Darken_Lighten(img);
                img.saveImage(output);
                cout << "image saved successfully " << "\n" ;
                return 0;
            }
        case 12:
            {
                string input, output;
                cout << "Enter input image name: ";
                cin >> input;
            
                cout << "Enter output image name: ";
                cin >> output;
            
                Image img(input);
                edgeDetection(img);
            
                img.saveImage(output);
            
                cout << "image saved successfully " << "\n";
                return 0;
            }

          
        case 13:
            cout << "Exiting program.\n";
            return 0;
            
        default:
            cout << "Invalid choice!\n";
            break;
      }
    }
    return 0;
}
