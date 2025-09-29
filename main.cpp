//This C++ program is a simple image editor It lets you: 
//Flip images (horizontal/vertical) , Rotate (90°, 180°, 270°) , Convert to black & white , Convert to grayscale ,
//Invert colors (negative), It shows a menu, asks for the image file, applies the chosen operation and lets you save the result with a new name.
// Students details:
// student 1: seif mohamed , id: 20240269 , filters: invert image colors and rotate image
// student 2: ahmed tamer , id:20240019 , filters: merge images and grayscale conversion
// student 3: ahmed khaled , id: 20240027 , filters: blackandwhite image and flip image
// section: s13
#include <iostream>
#include "Image_Class.h"


using namespace std;
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
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {

                image(j, image.width - 1 - i, k) = image(i, j, k);
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
void rotate180(Image &image) {
    
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(image.width - 1 - i, image.height - 1 - j, k) = image(i, j, k);
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
void rotate270(Image &image) {
    for (int i = 0; i < image.height; ++i) {
        for (int j = 0; j < image.width; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(j, image.width - 1 - i, k) = image(i, j, k);
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

int main() {
    
    int choice;
    while(true){
      cout << "Menu:\n";
      
     
      cout << "1. Invert image colors\n";
      cout << "2. Rotate image\n";
      cout << "3. BlackAndWhite\n";
      cout << "4. grey scale image \n";
      cout << "5. flipImage \n";

      cout << "7. Exit\n";
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

                
        case 7:
            cout << "Exiting program.\n";
            return 0;
            
        default:
            cout << "Invalid choice!\n";
            break;
      }
    }
    return 0;
}
