/*
--> Name: CS112_A3_Part2B_S22_20230280_20231109_20231143.cpp
--> Purpose: A small program that make some photoshop edits on any image you want by only using its address,
             in this once there is 15 different filters that are : Gray Scale filter, Black and White filter,
             Invert image filter, Merge two images, Flip image filter, Rotation image filter, Darken and
             Lighten image filter, Crop filter, Adding frame to image filter, Detect edge filter, Resizing image,
             Blur filter, Natural Sunlight filter,Make image purple, Infrared image filter, and we will try to 
             not stop at this point and continue in the near future.

--> GitHub repository :- https://github.com/fatema123elfiky/filter
--> System Diagram :- https://drive.google.com/file/d/1QyjKZLBMoHb3qrM9BWxfDUu3Ig2p4_oC/view?usp=drive_link

--> Author of (1, 4, 7, 10, 13) filters: Fatema El-Zhraa Ahmed Mohamed El-Fiky.             (ID:20230280)         (Section : S22)
--> Email : fatmaelfeky922@gmail.com
--> GitHub : https://github.com/fatema123elfiky

--> Author of (2, 5, 8, 11, 14) filters: Aly El-Deen Yasser Aly.                            (ID:20231109)         (Section : S22)
--> Email : aibakgaming747@gmail.com
--> GitHub : https://github.com/Ali-EL-Badry

--> Author of (3, 6, 9, 12, 15) filters: Mohammed Atef Abd EL-Kader Bayomi.                 (ID:20231143)         (Section : S22)
--> Email : mohamed45452020@gmail.com
--> GitHub : https://github.com/Mohammed-Atef-20231143
# ======================================================================================================================================================================= #*/

// Defining libraries.
#include <bits/stdc++.h>
#include "Image_Class.h"
#include <fstream>
#include <limits.h>
#define ll long long
using namespace std;

// Defining some functions.
// To check the existence of image.
string validationpart1(string nameimage) {
    while (true) {
        ifstream file_stream(nameimage);
        try {
            if (file_stream.is_open())
                break;
            else
                throw std::runtime_error("File is not exist , pls enter again\n");
        }
        catch (const std::exception& e) {
            cout << "Please enter again a valid photo : ";
            getline(cin, nameimage);
        }
    }
    return nameimage;
}

// To check if the name of the photo is valid and extension.
string validationpart2(string nameOfSavedImage) {
    while (nameOfSavedImage.size() <= 4) {
        cout << "The name is too short enter again : ";
        getline(cin, nameOfSavedImage);
    }
    string extension = nameOfSavedImage.substr(nameOfSavedImage.size() - 4);

    while (extension != ".jpg" && extension != ".png" && extension != ".bmp" && extension != "jpeg") {
        cout << "Please enter the name of the image with correct extension and suitable size: ";
        getline(cin, nameOfSavedImage);
        while (nameOfSavedImage.size() <= 4) {
            cout << "The name is too short enter again : ";
            getline(cin, nameOfSavedImage);
        }
        extension = nameOfSavedImage.substr(nameOfSavedImage.size() - 4);
    }
    while (extension == "jpeg") {
        if (nameOfSavedImage[nameOfSavedImage.size() - 5] != '.' || nameOfSavedImage.size() <= 5) {
            cout << "Please enter the name of the image with correct extension and suitable size : ";
            getline(cin, nameOfSavedImage);
            while (nameOfSavedImage.size() <= 4) {
                cout << "The name is too short enter again : ";
                getline(cin, nameOfSavedImage);
            }
            string extension = nameOfSavedImage.substr(nameOfSavedImage.size() - 4);

            while (extension != ".jpg" && extension != ".png" && extension != ".bmp" && extension != "jpeg") {
                cout << "Please enter the name of the image with correct extension and suitable size : ";
                getline(cin, nameOfSavedImage);
                while (nameOfSavedImage.size() <= 4) {
                    cout << "The name is too short enter again : ";
                    getline(cin, nameOfSavedImage);
                }
                extension = nameOfSavedImage.substr(nameOfSavedImage.size() - 4);
            }
        }
        else {
            break;
        }
    }
    return nameOfSavedImage;
}

// To get from user the way he wants to save the image by
string savingWay(string originname) {
    cout << "Do you like to save in new image or the same one?\n [1] Save in new image.\n [2] Save in the same picture.\nEnter Your Choice: ";
    string choice;
    getline(cin, choice);
    while (choice != "1" && choice != "2") {
        cout << "Enter a valid choice : ";
        getline(cin, choice);
    }
    string nameOfSavedImage;
    if (choice == "1") {
        cout << "The filename should end with the extension (.jpg or.png or.bmp or.jpeg)\n";
        cout << "Enter the name of the new image: ";
        getline(cin, nameOfSavedImage);
        nameOfSavedImage = validationpart2(nameOfSavedImage);
    }
    else
        nameOfSavedImage = originname;
    return nameOfSavedImage;
}

// To get number and check on it.
ll get_num(ll condition, ll x = 0) {
    string num;
    while (true) {
        bool check = true;
        getline(cin, num);
        for (ll i = 0; i < num.length(); i++) {
            if (!isdigit(num[i])) {
                check = false;
                break;
            }
        }
        if (check && (stoll(num) + x <= condition)) {
            return stoll(num);
        }
        cout << "Please, Enter a right positive number that is inside the image: ";
    }
}

// ========================================================>> Filter 1: Grayscale Conversion <<======================================================== //

void grayscale_conversion(Image& image) {
    cout << "\n# ===== Welcome to the Grayscale Filter ===== #\n";

    // To get the degree of the gray color.
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int avg = 0;
            for (int k = 0; k < 3; k++)
                avg += image(i, j, k);

            avg = avg / 3;

            for (int k = 0; k < 3; k++)
                image(i, j, k) = avg;
        }
    }
}

// ========================================================>> Filter 2: Black and White <<======================================================== //

void black_and_white(Image& image) {
    cout << endl << "\n# ===== Welcome to Black and White Filter ===== #" << endl;

    // To make the dark point black and the light point white.
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int average = 0;
            for (int k = 0; k < 3; k++)
                average += image(i, j, k);
            if (average / 3 > 124) {
                image(i, j, 0) = 255;
                image(i, j, 1) = 255;
                image(i, j, 2) = 255;
            }
            else {
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 0;
            }
        }
    }
}

// ========================================================>> Filter 3: Invert Image <<======================================================== //

void invert_image(Image& image) {
    cout << endl << "\n# ===== Welcome to Invert Image Filter ===== #" << endl;

    // For inverting the image.
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = 255 - image(i, j, k);
            }
        }
    }
}

// ========================================================>> Filter 4: Merge two Images <<======================================================== //
void merge_filter(Image &image1){
    cout << "# ==== Welcome to Merge Two Image Filter ==== #\n\n";
    
    // To get image2 to merge it with image1.
    string name2;
    cout << "Please, Enter the second image:";
    getline(cin, name2);
    name2 = validationpart1(name2);
    Image image2(name2);

    // To see the user how he wants to merge.
    cout << "What do you prefer?\n [1] Crop the Two Images common Diminsion. \n [2] Resize one of them to fit the other\n Your choice is: ";
    string choice;
    getline(cin, choice);
    // To check the menu choice.
    while (choice != "1" && choice != "2") {
        cout << "pls enter a valid choice\n";
        getline(cin, choice);
    }

    // Define some needed variables.
    double WidthImage = 0, Length = 0; 
    string ans;
    Image res;

    // If he chooses crop.
    if (choice == "1") {
        // Comparing width.
        if (image1.width > image2.width) {
            WidthImage = image2.width;
        }
        else {
            WidthImage = image1.width;
        }

        // Comparing length.
        if (image1.height > image2.height) {
            Length = image2.height;
        }
        else {
            Length = image1.height;
        }
    }

    // If he chooses resize.
    else if (choice == "2") {
        // To see what user will choose.
        cout << "Choose: Which one do you want to fit the other?\n [1] the first image to the second one\n [2] The second image to the first one\nEnter your choice: ";
        getline(cin, ans);
        // For menu validation.
        while (ans != "1" && ans != "2"){
            cout << "enter a valid choice\n";
            getline(cin, ans);
        }

        // If he chooses the first image to the second one.
        double change_width, change_height;
        if (ans == "1"){
            change_width = double(image1.width) / double(image2.width);
            change_height = double(image1.height) / double(image2.height);

            // Resize image function.
            Image image3(image2.width, image2.height);
            for (double i = 0; i < image2.height; i++) {
                for (double j = 0; j < image2.width; j++) {
                    for (int k = 0; k < 3; k++)
                        image3(j, i, k) = image1(round(j * change_width), round(i * change_height), k);
                }
            }
            res = image3;
            WidthImage = image3.width;
            Length = image3.height;
        }

        // If he chooses the second image to the first one.
        else {
            change_width = double(image2.width) / double(image1.width);
            change_height = double(image2.height) / double(image1.height);

            // Resize image function.
            Image image3(image1.width, image1.height);
            for (double i = 0; i < image1.height; i++) {
                for (double j = 0; j < image1.width; j++) {
                    for (int k = 0; k < 3; k++)
                        image3(j, i, k) = image2(round(j * change_width), round(i * change_height), k);
                }
            }
            res = image3;
            WidthImage = image3.width;
            Length = image3.height;
        }
    } 

    // Defining some images.
    Image imagee(WidthImage, Length);
    Image main1;
    Image main2;

    // if crop ....
    if (choice == "1"){
        main1 = image1;
        main2 = image2;
    }

    // if resize ....
    else if (choice == "2"){
        if (ans == "1") {
            main1 = res;
            main2 = image2;
        }
        else if (ans == "2") {
            main1 = image1;
            main2 = res;
        }
    }

    // The idea of merge.
    for (int i = 0; i < imagee.width; i++){
        for (int j = 0; j < imagee.height; j++){
            for (int k = 0; k < 3; k++){
                if (j % 2 == 0) {
                    imagee(i, j, k) = main1(i, j, k);}
                else {
                    imagee(i, j, k) = main2(i, j, k);}
            }
        }
    }
    image1 = imagee;
}

// ========================================================>> Filter 5: Flip image <<======================================================== //

void Flip_image(Image& image) {
    string choice;
    while (true) {

        // To Check the menu choices.
        while (true) {
            cout << "\n# ===== Welcome to Flip image Filter ===== #\n";
            cout << "How do you want to flip the image?\n [1] Horizontal flip.\n [2] Vertical flip.\n [3] Both flips. \nEnter Your Choice:";
            getline(cin, choice);

            bool check = false;
            for (int i = 1; i <= 3; i++) {         // Checking of answer.
                if (choice == to_string(i)) {
                    check = true;
                    break;
                }
            }

            if (check)
                break;
            cout << "Invalid Choice. Try Again." << endl << endl;
        }

        // Vertical Flip.
        if (choice == "2") {
            for (int i = 0; i < image.width; i++) {
                for (int j = 0; j < image.height / 2; j++) {
                    for (int k = 0; k < 3; k++) {
                        int v = image(i, j, k);
                        image(i, j, k) = image(i, image.height - j - 1, k);
                        image(i, image.height - j - 1, k) = v;
                    }
                }
            }
        }

        // Horizontal Flip.
        else if (choice == "1") {
            for (int i = 0; i < image.width / 2; i++) {
                for (int j = 0; j < image.height; j++) {
                    for (int k = 0; k < 3; k++) {
                        int v = image(i, j, k);
                        image(i, j, k) = image(image.width - i, j, k);
                        image(image.width - i, j, k) = v;
                    }
                }
            }
        }

        // Both Flip.
        else {
            for (int i = 0; i < image.width; i++) {
                for (int j = 0; j < image.height / 2; j++) {
                    for (int k = 0; k < 3; k++) {
                        int v = image(i, j, k);
                        image(i, j, k) = image(i, image.height - j - 1, k);
                        image(i, image.height - j - 1, k) = v;
                    }
                }
            }
            for (int i = 0; i < image.width / 2; i++) {
                for (int j = 0; j < image.height; j++) {
                    for (int k = 0; k < 3; k++) {
                        int v = image(i, j, k);
                        image(i, j, k) = image(image.width - i, j, k);
                        image(image.width - i, j, k) = v;
                    }
                }
            }
        }

        // To check if user wants to make another flip or not...
        cin.ignore(0, '\n');
        while (true) {
            cout << "Do you want to make another flip?\n [1] Yes.\n [2] No.\nEnter Your Choice :";
            string choice;
            getline(cin, choice);
            if (choice == "1")              // if yes ...
                break;

            else if (choice == "2")         // if no ...
                return;

            // If he enters an invalid choice
            cout << "Please choose a valid option " << endl;
        }
    }
}

// ========================================================>> Filter 6: Rotate Image <<======================================================== //

void rotate_image(Image &image) {

    cout << endl << "# ===== Welcome to Rotate Image Filter ===== #" << endl;
    Image image2(image.height, image.width);
    string choice;
    bool valid = false;

    // To check the menu choices.
    while (true) {
        cout << "\nYou want to rotate this image clockwise by : .........\n";
        cout << " [1] 90.\n [2] 180.\n [3] 270.\nEnter Your Choice: ";
        getline(cin, choice);
        bool check = false;
        for (int i = 1; i <= 3; i++) {         // Checking of answer.
            if (choice == to_string(i)) {
                check = true;
                break;
            }
        }

        if (check)
            break;
        cout << "Invalid Choice. Try Again." << endl << endl;
    }

    // 90 Degree clockwise Rotations.
    if (choice == "1") {
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image2(image.height - j, i, k) = image(i, j, k);
                }
            }
        }
    }

    // 180 Degree clockwise Rotations.
    else if (choice == "2") {
        for (int i = 0; i < image.width / 2; i++) {
            for (int j = 0; j < image.height; j++) {
                for (int k = 0; k < 3; k++) {
                    int v = image(i, j, k);
                    image(i, j, k) = image(image.width - i, j, k);
                    image(image.width - i, j, k) = v;
                }
            }
        }
        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height / 2; j++) {
                for (int k = 0; k < 3; k++) {
                    int v = image(i, j, k);
                    image(i, j, k) = image(i, image.height - j - 1, k);
                    image(i, image.height - j - 1, k) = v;
                }
            }
        }
        valid = true;
    }

    // 270 Degree clockwise Rotations.
    else if (choice == "3") {
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image2(j, i, k) = image(image.width - i, j, k);
                }
            }
        }
    }
    if (!valid)
        image = image2;
}

// =====================================================>> Filter 7: Lighten And Darken <<===================================================== //

void Lighten_Darken(Image& image) {
    // Validation for files and the saved name is missed.
    cout << "\n# ===== Welcome to lighten and darken filter ===== #\n";
    cout << "Please enter the image name:\n";
    cout << " [1] Darken filter.\n [2] Lighten filter.\nEnter Your Choice:\n";
    string choice11;
    getline(cin, choice11);

    // Validation.
    while (choice11 != "1" && choice11 != "2") {
        cout << "Enter a valid choice.\n";
        getline(cin, choice11);
    }

    // Darken filter.
    if (choice11 == "1") {
        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height; j++) {
                for (int k = 0; k < 3; k++)
                    image(i, j, k) = image(i, j, k) / 2;
            }
        }
    }

    // Lighten image.
    else {
        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height; j++) {
                for (int k = 0; k < 3; k++)
                    image(i, j, k) = min(image(i, j, k) * 2, 255);
            }
        }
    }
}

// ========================================================>> Filter 8: Crop image filter <<======================================================== //

void crop_image(Image &img) {
    // To show the user image data.
    cout << endl << "# ===== Welcome to Crop Image Filter ===== #" << endl;
    cout << "Image Height is : " << img.height << endl;
    cout << "Image Width is : " << img.width << endl;

    // To take the crop image data from user.
    ll x, y, new_height, new_width;
    cout << "Please, Enter the X that you want to crop from : ";
    x = get_num(img.width);
    cout << "Please, Enter the Y that you want to crop from : ";
    y = get_num(img.height);
    cout << "Please, Enter the width of photo : ";
    new_width = get_num(img.width, x);
    cout << "Please, Enter the height of photo : ";
    new_height = get_num(img.height, y);

    // Crop functionality.
    Image image(new_width, new_height);
    ll image_width = 0;
    for (ll n = x; n < x + new_height; n++) {
        ll image_length = 0;
        for (ll m = y; m < y + new_width; m++) {
            for (ll k = 0; k < 3; k++)
                image(image_length, image_width, k) = img(m, n, k);
            image_length++;
        }
        image_width++;
    }
    img = image;
}

// ========================================================>> Filter 9: Adding a Frame to the Picture <<======================================================== //

void adding_a_frame(Image &image) {
    cout << "\n# ===== Welcome to the Adding a Frame to the Picture Filter ===== #\n";
    ll Min = min(image.height, image.width);
    Image image1(image.width + (Min * 0.02), image.height + (Min * 0.02));
    string ch_colour, frame;

    // Validate the color menu.
    while (true) {
        cout << "What colour do you want?\n"
            " [1] Red.                         [2] Blue.\n"
            " [3] Green.                       [4] Yellow.\n"
            " [5] Cyan.                        [6] Magenta.\n"
            " [7] White.                       [8] Black.\n"
            "Enter Your Choice:";
        getline(cin, ch_colour);

        bool check = false;
        for (int i = 1; i <= 8; i++) {         // Checking of answer.
            if (ch_colour == to_string(i)) {
                check = true;
                break;
            }
        }

        if (check)
            break;
        cout << "Invalid Choice. Try Again." << endl << endl;
    }

    cout << endl;

    // Validate the frame menu.
    while (true) {
        cout << "What frame do you want?\n"
            " [1] Simple frame.\n [2] Fancy frame.\n"
            "Enter Your Choice:";
        getline(cin, frame);

        bool check = false;
        for (int i = 1; i <= 2; i++) {         // Checking of answer.
            if (frame == to_string(i)) {
                check = true;
                break;
            }
        }

        if (check)
            break;
        cout << "Invalid Choice. Try Again." << endl << endl;
    }

    // Frame function.
    cout << endl;
    for (int i = 0; i < image1.width; ++i) {
        for (int j = 0; j < image1.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                if ((i <= (Min * 0.02) || j <= (Min * 0.02) || i >= image1.width - (Min * 0.02) || j >= image1.height - (Min * 0.02)) && (frame == "1" || frame == "2")) {         // Simple Frame.
                    if (ch_colour == "1") {
                        image1(i, j, 0) = 255;
                        image1(i, j, 1) = 0;
                        image1(i, j, 2) = 0;
                    }
                    else if (ch_colour == "2") {
                        image1(i, j, 0) = 0;
                        image1(i, j, 1) = 0;
                        image1(i, j, 2) = 255;
                    }
                    else if (ch_colour == "3") {
                        image1(i, j, 0) = 0;
                        image1(i, j, 1) = 255;
                        image1(i, j, 2) = 0;
                    }
                    else if (ch_colour == "4") {
                        image1(i, j, 0) = 255;
                        image1(i, j, 1) = 255;
                        image1(i, j, 2) = 0;
                    }
                    else if (ch_colour == "5") {
                        image1(i, j, 0) = 0;
                        image1(i, j, 1) = 255;
                        image1(i, j, 2) = 255;
                    }
                    else if (ch_colour == "6") {
                        image1(i, j, 0) = 255;
                        image1(i, j, 1) = 0;
                        image1(i, j, 2) = 255;
                    }
                    else if (ch_colour == "7") {
                        image1(i, j, 0) = 255;
                        image1(i, j, 1) = 255;
                        image1(i, j, 2) = 255;
                    }
                    else if (ch_colour == "8") {
                        image1(i, j, 0) = 0;
                        image1(i, j, 1) = 0;
                        image1(i, j, 2) = 0;
                    }
                }
                // Fancy Frame.
                else if (((i >= (Min * 0.02) && i <= (Min * 0.02) * 1.45) || (j >= (Min * 0.02) && j <= (Min * 0.02) * 1.45) || (i <= image1.width - (Min * 0.02) && i >= (image1.width - (Min * 0.02) * 1.45)) || (j <= image1.height - (Min * 0.02) && j >= (image1.height - (Min * 0.02) * 1.45))) && frame == "2") {
                    image1(i, j, k) = 235;
                }
                else if (((i >= (Min * 0.02) * 2 && i <= (Min * 0.02) * 2.25) || (j >= (Min * 0.02) * 2 && j <= (Min * 0.02) * 2.25) || (i <= image1.width - ((Min * 0.02) * 2) && i >= image1.width - ((Min * 0.02) * 2.25)) || (j <= image1.height - ((Min * 0.02) * 2) && j >= image1.height - ((Min * 0.02) * 2.25))) && frame == "2") {
                    image1(i, j, k) = 225;
                    image1(i, j, k) = 225;
                    image1(i, j, k) = 225;
                }
                else { image1(i, j, k) = image(i, j, k); }
            }
        }
    }
    image1 = image;
}

// ========================================================>> Filter 10 : Detect edges <<======================================================== //

void detect_edges(Image& image) {
    cout << "\n# ===== Welcome to detect edges filter ===== #\n";
    Image image2(image.width, image.height);

    // The idea of black and white filter.
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int average = 0;
            for (int k = 0; k < 3; k++)
                average += image(i, j, k);
            if (average / 3 > 124) {
                image(i, j, 0) = 255;
                image(i, j, 1) = 255;
                image(i, j, 2) = 255;
            }
            else {
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 0;
            }
        }
    }

    // The idea of the detecting.
    float avg = 0, avg2 = 0, avg3 = 0, avg4 = 0, avg5 = 0;
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            if (i == 0 && j == 0) {
                for (int k = 0; k < 3; k++)
                    avg += image(i, j, k);
                avg = avg / 3;
                for (int k = 0; k < 3; k++)
                    avg3 += image(i + 1, j, k);
                avg3 = avg3 / 3;
                for (int k = 0; k < 3; k++)
                    avg4 += image(i, j + 1, k);
                avg4 = avg4 / 3;
                if (fabs(avg - avg3) >= 127 || fabs(avg - avg4) >= 127) {
                    for (int k = 0; k < 3; k++)
                        image2(i, j, k) = 0;
                }

                else {
                    for (int k = 0; k < 3; k++)
                        image2(i, j, k) = 255;
                }
            }

            else if (i == 0 && j == image.height - 1) {
                for (int k = 0; k < 3; k++)
                    avg += image(i, j, k);
                avg = avg / 3;
                for (int k = 0; k < 3; k++)
                    avg3 += image(i + 1, j, k);
                avg3 = avg3 / 3;

                for (int k = 0; k < 3; k++)
                    avg4 += image(i, j - 1, k);
                avg4 = avg4 / 3;

                if (fabs(avg - avg3) >= 127 || fabs(avg - avg4) >= 127) {
                    for (int k = 0; k < 3; k++)
                        image2(i, j, k) = 0;
                }
                else {
                    for (int k = 0; k < 3; k++)
                        image2(i, j, k) = 255;
                }
            }

            else if (i == image.width - 1 && j == 0) {
                for (int k = 0; k < 3; k++)
                    avg += image(i, j, k);
                avg = avg / 3;
                for (int k = 0; k < 3; k++)
                    avg3 += image(i - 1, j, k);
                avg3 = avg3 / 3;

                for (int k = 0; k < 3; k++)
                    avg4 += image(i, j + 1, k);
                avg4 = avg4 / 3;
                
                if (fabs(avg - avg3) >= 127 || fabs(avg - avg4) >= 127) {
                    for (int k = 0; k < 3; k++)
                        image2(i, j, k) = 0;
                }

                else {
                    for (int k = 0; k < 3; k++)
                        image2(i, j, k) = 255;
                }
            }

            else if (i == image.width - 1 && j == image.height - 1) {
                for (int k = 0; k < 3; k++)
                    avg += image(i, j, k);
                avg = avg / 3;
                for (int k = 0; k < 3; k++)
                    avg3 += image(i + 1, j, k);
                avg3 = avg3 / 3;

                for (int k = 0; k < 3; k++)
                    avg4 += image(i, j - 1, k);
                avg4 = avg4 / 3;

                if (fabs(avg - avg3) >= 127 || fabs(avg - avg4) >= 127) {
                    for (int k = 0; k < 3; k++)
                        image2(i, j, k) = 0;
                }
                else {
                    for (int k = 0; k < 3; k++)
                        image2(i, j, k) = 255;
                }
            }

            else if (i == 0) {
                for (int k = 0; k < 3; k++)
                    avg += image(i, j, k);
                avg = avg / 3;

                for (int k = 0; k < 3; k++)
                    avg2 += image(i, j + 1, k);
                avg2 = avg2 / 3;

                for (int k = 0; k < 3; k++)
                    avg3 += image(i + 1, j, k);
                avg3 = avg3 / 3;

                for (int k = 0; k < 3; k++)
                    avg4 += image(i, j - 1, k);
                avg4 = avg4 / 3;

                if (fabs(avg - avg3) >= 127 || fabs(avg - avg4) >= 127 || fabs(avg - avg2) >= 127) {
                    for (int k = 0; k < 3; k++)
                        image2(i, j, k) = 0;
                }
                else {
                    for (int k = 0; k < 3; k++)
                        image2(i, j, k) = 255;
                }

            }
            else if (i == image.width - 1) {
                for (int k = 0; k < 3; k++)
                    avg += image(i, j, k);
                avg = avg / 3;

                for (int k = 0; k < 3; k++)
                    avg2 += image(i, j + 1, k);
                avg2 = avg2 / 3;

                for (int k = 0; k < 3; k++)
                    avg3 += image(i - 1, j, k);
                avg3 = avg3 / 3;

                for (int k = 0; k < 3; k++)
                    avg4 += image(i, j - 1, k);
                avg4 = avg4 / 3;

                if (fabs(avg - avg3) >= 127 || fabs(avg - avg4) >= 127 || fabs(avg - avg2) >= 127) {
                    for (int k = 0; k < 3; k++)
                        image2(i, j, k) = 0;
                }
                else {
                    for (int k = 0; k < 3; k++)
                        image2(i, j, k) = 255;
                }

            }
            else if (j == 0) {
                for (int k = 0; k < 3; k++)
                    avg += image(i, j, k);
                avg = avg / 3;

                for (int k = 0; k < 3; k++)
                    avg2 += image(i, j + 1, k);
                avg2 = avg2 / 3;

                for (int k = 0; k < 3; k++)
                    avg3 += image(i + 1, j, k);
                avg3 = avg3 / 3;

                for (int k = 0; k < 3; k++)
                    avg4 += image(i - 1, j, k);
                avg4 = avg4 / 3;

                if (fabs(avg - avg3) >= 127 || fabs(avg - avg4) >= 127 || fabs(avg - avg2) >= 127) {
                    for (int k = 0; k < 3; k++)
                        image2(i, j, k) = 0;
                }
                else {
                    for (int k = 0; k < 3; k++)
                        image2(i, j, k) = 255;
                }

            }
            else if (j == image.height - 1) {
                for (int k = 0; k < 3; k++)
                    avg += image(i, j, k);
                avg = avg / 3;

                for (int k = 0; k < 3; k++)
                    avg2 += image(i, j - 1, k);
                avg2 = avg2 / 3;

                for (int k = 0; k < 3; k++)
                    avg3 += image(i + 1, j, k);
                avg3 = avg3 / 3;

                for (int k = 0; k < 3; k++)
                    avg4 += image(i - 1, j, k);
                avg4 = avg4 / 3;

                if (fabs(avg - avg3) >= 127 || fabs(avg - avg4) >= 127 || fabs(avg - avg2) >= 127) {
                    for (int k = 0; k < 3; k++)
                        image2(i, j, k) = 0;
                }
                else {
                    for (int k = 0; k < 3; k++)
                        image2(i, j, k) = 255;
                }

            }
            else {
                for (int k = 0; k < 3; k++)
                    avg += image(i, j, k);
                avg = avg / 3;
                for (int k = 0; k < 3; k++)
                    avg2 += image(i - 1, j, k);
                avg2 = avg2 / 3;
                for (int k = 0; k < 3; k++)
                    avg3 += image(i + 1, j, k);
                avg3 = avg3 / 3;

                for (int k = 0; k < 3; k++)
                    avg4 += image(i, j + 1, k);
                avg4 = avg4 / 3;

                for (int k = 0; k < 3; k++)
                    avg5 += image(i, j - 1, k);
                avg5 = avg5 / 3;
                
                if (fabs(avg - avg2) >= 127 || fabs(avg - avg3) >= 127 || fabs(avg - avg3) >= 127 || fabs(avg - avg4) >= 127 || fabs(avg - avg5) >= 127) {
                    for (int k = 0; k < 3; k++)
                        image2(i, j, k) = 0;
                }
                else {
                    for (int k = 0; k < 3; k++)
                        image2(i, j, k) = 255;
                }
            }
            avg = 0, avg2 = 0, avg3 = 0, avg4 = 0, avg5 = 0;
        }
    }
    image = image2;
}

// ========================================================>> Filter 11: Resize Image filter <<======================================================== //

void resize_filter(Image &img) {
    // To show the user image data.
    cout << endl << "# ===== Welcome to Resize Image Filter ===== #" << endl;
    cout << "Image Height is : " << img.height << endl;
    cout << "Image Width is : " << img.width << endl;

    // To see, how would user enter the resize dimention of image.
    string choice;
    while (true) {
        cout << "What do you want new image to be? \n [1] With a new dimintion for the image.\n [2] Its size increase by a certain percentage.\nEnter Your Choice :";
        getline(cin, choice);
        if (choice == "1" || choice == "2")
            break;
        cout << endl << "Please, Enter a valid option!" << endl;
    }

    double image_width, image_height, change_width, change_height, percentage_change_w, percentage_change_h;
    // If he wants to enter new dimintion .
    if (choice == "1") {
        cout << "Please, Enter the new width of the image : ";
        image_width = get_num(LONG_LONG_MAX);
        cout << "Please, Enter the new height of the image : ";
        image_height = get_num(LONG_LONG_MAX);
    }

    // If he wants to increase the size of image by a certain percentage
    else {
        cout << "Please, Enter the percentage change of the image width (from 100%) : ";
        percentage_change_w = get_num(LONG_LONG_MAX);
        cout << "Please, Enter the percentage change of the image height (from 100%) : ";
        percentage_change_h = get_num(LONG_LONG_MAX);
        image_width = img.width * percentage_change_w / 100;
        image_height = img.height * percentage_change_h / 100;
    }

    // Percentage of change.
    change_width = img.width / image_width;
    change_height = img.height / image_height;

    // Resize image function.
    Image image(image_width, image_height);
    for (double i = 0; i < image_height; i++) {
        for (double j = 0; j < image_width; j++) {
            for (int k = 0; k < 3; k++)
                image(j, i, k) = img(round(j * change_width), round(i * change_height), k);
        }
    }
    img = image;
}

// ========================================================>> Filter 12: Blur Images <<======================================================== //

void blur_images(Image& image) {
    cout << "\n# ===== Welcome to the Blur Images Filter ===== #\n";
    ll r = 35, area = ((2 * r) + 1) * ((2 * r) + 1);

    // To build 3D prefix sum vector.
    vector<vector<vector<ll>>> pref(image.width, vector<vector<ll>>(image.height, vector<ll>(3)));
    for (int i = 0; i < image.width; ++i) {
        pref[i][0][0] = image(i, 0, 0);
        pref[i][0][1] = image(i, 0, 1);
        pref[i][0][2] = image(i, 0, 2);
    }
    for (int j = 0; j < image.height; ++j) {
        pref[0][j][0] = image(0, j, 0);
        pref[0][j][1] = image(0, j, 1);
        pref[0][j][2] = image(0, j, 2);
    }
    for (int i = 1; i < image.width; ++i) {
        for (int j = 1; j < image.height; ++j) {
            pref[i][j][0] = image(i, j, 0) + pref[i - 1][j][0] + pref[i][j - 1][0] - pref[i - 1][j - 1][0];
            pref[i][j][1] = image(i, j, 1) + pref[i - 1][j][1] + pref[i][j - 1][1] - pref[i - 1][j - 1][1];
            pref[i][j][2] = image(i, j, 2) + pref[i - 1][j][2] + pref[i][j - 1][2] - pref[i - 1][j - 1][2];
        }
    }

    // To blur image's pixels.
    ll sum = 0;
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                ll i1 = i + r, i2 = i - r - 1, j1 = j + r, j2 = j - r - 1;
                if (i1 >= image.width - 1) {
                    i1 = image.width - 1;
                }
                if (i2 <= 0) {
                    i2 = 0;
                }
                if (j1 >= image.height - 1) {
                    j1 = image.height - 1;
                }
                if (j2 <= 0) {
                    j2 = 0;
                }
                sum = pref[i1][j1][k] - pref[i2][j1][k] - pref[i1][j2][k] + pref[i2][j2][k];
                image(i, j, k) = sum / area;
            }
        }
    }
}

// ===================================================>> Filter 13: natural sunlight filter <<=================================================== //

void natural_sunlight(Image &image) {
    cout << "\n# ===== Welcome to the Natural Sunlight Filter ===== #\n";

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i, j, 2) *= 0.888;
            }
        }
    }
}

// =================================================>> Filter 14: Make photo more purple <<================================================= //

void look_purple(Image &image) {
    cout << "\n# ===== Welcome to the Look Purple Filter ===== #\n";
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            image(i, j, 1) *= 0.7;
        }
    }
}

// =================================================>> Filter 15: infrared pics Filter <<================================================= //

void infrared(Image &image) {
    cout << "\n# ===== Welcome to the Infrared Photography Filter ===== #\n";

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i, j, 0) = 252;
                image(i, j, 1) = 255 - image(i, j, 1);
                image(i, j, 2) = 255 - image(i, j, 2);
            }
        }
    }
}


// ===================================================================>> Main Application <<=================================================================== //

int main() {
    // Showing what program do.
    cout << "# ===== Welcome To Baby Photoshop Application ===== #" << endl;
    cout << "--> A small program that make some photoshop edits on any image you want by only using its address," << endl;
    cout << "    in this once there is a 15 different filters that are : Grayscale filter, Black and White filter," << endl;
    cout << "    Invert image filter, Merge two image filter, Flipping image filter, Rotating image filter, Darken" << endl;
    cout << "    and Lighting image filter, Crop filter, Adding frame to image filter, Detect edge filter, Resizing" << endl;
    cout << "    image, Blur filter, Natural Sunlight filter,Make image purple, Infrared image filter, and we will " << endl;
    cout << "    try to not stop at this point and continue in near future ......" << endl;
    cout << "==============================================================================================================" << endl;
    string nameimage;
    cout << "The filename should end with the extension .jpg or.png or.bmp or.jpeg\n";
    cout << "Please, Enter the photo : ";
    getline(cin, nameimage);
    nameimage = validationpart1(nameimage);
    Image image(nameimage);
    
    // To keep the program running.
    while (true) {
        // Menu choice to check of it.
        bool checkkk = false;
        string choice_menu;
        while (true) {
            cout << "\nChoose One Of This Filters:-" << endl;
            cout << " [1] Grayscale Conversion.\n [2] Black and White Filter.\n [3] Invert Image Colours.\n [4] Merge Two Image.\n [5] Flip Image.\n [6] Rotating Image.\n";
            cout << " [7] Darken and lighting Image.\n [8] Crop Image.\n [9] Adding Frame to Image.\n [10] Detect edge Filter.\n [11] Resizing Image Filter.\n";
            cout << " [12] Blur Filter.\n [13] Natural Sunlight Filter.\n [14] Look Purple Filter.\n [15] Infrared Image Filter.\n";
            cout << " [16] Saving Image and Changing image. \n [17] Exit Application .\nEnter Your Choice : ";
            getline(cin, choice_menu);

            bool check = false;
            for (int i = 1; i <= 17; i++) {         // Checking of answer.
                if (choice_menu == to_string(i)) {
                    check = true;
                    break;
                }
            }

            if (check)
                break;
            cout << "Invalid Choice. Try Again." << endl << endl;
        }

        // Gray scale filter.
        if (choice_menu == "1")
            grayscale_conversion(image);

        // Black and White filter.
        else if (choice_menu == "2")
            black_and_white(image);

        // Invert Image filter.
        else if (choice_menu == "3")
            invert_image(image);

        // Merge Two Image Filters.
        else if (choice_menu == "4")
            merge_filter(image);

        // Flip filter.
        else if (choice_menu == "5")
            Flip_image(image);

        // Rotate filter.
        else if (choice_menu == "6")
            rotate_image(image);

        // Darken and lighten Image filter.
        else if (choice_menu == "7")
            Lighten_Darken(image);

        // Crop filter.
        else if (choice_menu == "8")
            crop_image(image);

        // Adding frame to image filter.
        else if (choice_menu == "9")
            adding_a_frame(image);

        // Detect edges in image.
        else if (choice_menu == "10")
            detect_edges(image);

        // Resize image filter.
        else if (choice_menu == "11")
            resize_filter(image);

        // Blur filter.
        else if (choice_menu == "12")
            blur_images(image);

        // Natural sunlight filter.
        else if (choice_menu == "13")
            natural_sunlight(image);

        // Make image purple filter.
        else if (choice_menu == "14")
            look_purple(image);

        // Infrared image filter.
        else if (choice_menu == "15")
            infrared(image);

        // To save the photo.
        else if (choice_menu == "16") {
            string saved = savingWay(nameimage);
            image.saveImage(saved);
            cout << endl << "Image saved in " << saved << " successfully." << endl << endl;
            checkkk = true;
        }

        // To exit the application.
        else if (choice_menu == "17") {
            while (true) {
                cout << "Did you saved your work?\nNote : If you dont save you will lose all your work.\n [1] Yes, I saved it.\n [2] No, I want to save it.\nEnter Your choice :";
                string end;
                getline(cin, end);
                if (end == "2") {
                    string saved = savingWay(nameimage);
                    image.saveImage(saved);
                    cout << endl << "Image saved in " << saved << " successfully." << endl << endl;
                    cout << endl << "# === Thanks For Using Our Application !! === #" << endl;
                    return 0;
                }

                else if (end == "1") {
                    cout << endl << "# === Thanks For Using Our Application !! === #" << endl;
                    return 0;
                }

                cout << "Please, Enter a valid option" << endl;
            }
        }

        // Continue a menu to see if user wants to continue or exit the program.
        while (true) {
            cout << "Do You Want To Continue?\n [1] Yes.\n [2] No.\nEnter Your Choice: ";
            string choice;
            getline(cin, choice);

            if (choice == "1")              // If he wants to continue.
                break;

            else if (choice == "2") {        // If he doesn't.
                if(!checkkk){
                    while (true) {
                        cout << "Did you saved your work?\nNote : If you dont save you will lose all your work.\n [1] Yes, I saved it.\n [2] No, I want to save it.\nEnter Your Choice :";
                        string end;
                        getline(cin, end);
                        if (end == "2") {
                            string saved = savingWay(nameimage);
                            image.saveImage(saved);
                            cout << endl << "Image saved in " << saved << " successfully." << endl << endl;
                            cout << endl << "# === Thanks For Using Our Application !! === #" << endl;
                            return 0;
                        }

                        else if (end == "1") {
                            cout << endl << "# === Thanks For Using Our Application !! === #" << endl;
                            return 0;
                        }

                        cout << "Please, Enter a valid option." << endl;
                    }
                }else{
                    cout << endl << "# === Thanks For Using Our Application !! === #" << endl;
                    return 0;
                }
            }
            // If he entered an invalid choice.
            cout << "Invalid Choice. Try Again." << endl;
        }
    
        if(checkkk){
            // To see if a user wants to change a photo or not.
            while (true) {
                cout << "Do You Want To Change Photo?\n [1] Yes.\n [2] No.\nEnter Your Choice: ";
                string choice1;
                getline(cin, choice1);

                if (choice1 == "1") {              // If he wants to.
                    cout << "The filename should end with the extension .jpg or.png or.bmp or.jpeg\n";
                    cout << "Please, Enter the photo :";
                    getline(cin, nameimage);
                    nameimage = validationpart1(nameimage);
                    Image image1(nameimage);
                    image = image1;
                    break;
                }

                else if (choice1 == "2")          // If he doesn't.
                    break;

                // If he entered an invalid choice.
                cout << "Invalid Choice. Try Again." << endl;
            }
        }

    }
    return 0;
}
