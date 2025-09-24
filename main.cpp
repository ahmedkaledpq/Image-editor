#include <iostream>
#include "Image_Class.h"


using namespace std;





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

int main() {
    
    int choice;
    while(true){
      cout << "Menu:\n";
      
     
      cout << "1. Flip image colors\n";
      cout << "2. Rotate image\n";
      cout << "3. Exit\n";
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
                cout << "Image colors flipped successfully!\n";

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
            cout << "Exiting program.\n";
            return 0;
            
        default:
            cout << "Invalid choice!\n";
            break;
      }
    }
    return 0;
}
