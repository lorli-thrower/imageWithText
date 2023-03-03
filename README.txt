It's a converter of images to text.

build:
	linux:
		First install packages and libraries needed. Just use following command:
			sudo pacman -S sfml cmake make
		If you're using other distro rather then arch. Just install arch. Jk just use your pacakge manager. Package names most likely will be same or similar.
		After you installed all needed just create build directory to keep everything clear
			mkdir build && cd build
		Then just run
			cmake ..
		And 
			make
		It should create new file called imageWithText (or similar)
		Just run this file using 
			./imageWithText [ImageName][ImageName]...
	windows:
		Go to this link: https://releases.ubuntu.com/22.04.1/ubuntu-22.04.1-desktop-amd64.iso
		Create booting flash drive using installed file.
		Use flash drive to install linux.
		Follow linux installation instruction.
	
Usage:

./imageWithText {*}
Instead of {*} you can put infinite (up to 4294967295) images. It will draw them all one after another.
