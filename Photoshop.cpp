#include <bits/stdc++.h>
#include <image_class.h>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc!= 2)
    {
        cout << "Usage: " << argv[0] << " <image_path>" << endl;
        return 1;
    }

    Image img(argv[1]);

    cout << img.get_width() << " " << img.get_height() << endl;

    for (int i = 0; i < img.get_width(); i++)
    {
        for (int j = 0; j < img.get_height(); j++)
        {
            cout << img.get_pixel(i, j) << " ";
        }
        cout << endl;
    }

    return 0;
}