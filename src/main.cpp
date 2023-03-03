#include <iostream>
#include <SFML/Graphics.hpp>

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cout << "Please input at least one image as argument\n";
		return -1;
	}
	
	sf::Image img;
	char** imgASCII;
	sf::Color pixelColor;
	const char brightness[72] = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";
	// loading image before, so I can get size of image and loading after so 
	// I can write less code and tink less
	img.loadFromFile(argv[1]);

	// initializing array
	imgASCII = new char* [img.getSize().x];
	for (uint32_t i = 0; i < img.getSize().x; i++)
		imgASCII[i] = new char [img.getSize().y];

	// repeat for every image
	for (uint32_t i = 1; i < argc; i++)
	{
		// load image
		img.loadFromFile(argv[i]);

		// convert it to text pixel by pixel 
		for (uint32_t j = 0; j < img.getSize().x; j++)
		{
			for (uint32_t k	= 0; k < img.getSize().y; k++)
			{
				// converting r g b colors to gray 
				pixelColor = img.getPixel(j, k);
				int avgColor = ((int)pixelColor.r + (int)pixelColor.g + (int)pixelColor.b) / 3;
				// 70 / 255 is	ration of amount of ascii characters in my list
				// and maximum color value 
				imgASCII[j][k] = brightness[71 - static_cast<int>((float)avgColor * (71.f / 255.f))];
			}
		}
		// draw image using text
		for (uint32_t j = 0; j < img.getSize().y; j++)
		{
			for (uint32_t k = 0; k < img.getSize().x; k++)
			{
				std::cout << imgASCII[k][j];
			}
			std::cout << "\n";
		}
		
		system("sleep 0.033");
	}

	return 0;
}
