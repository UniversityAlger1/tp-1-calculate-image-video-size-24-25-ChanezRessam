# Règle pour tester le fichier grayScaleImage
test_grayScaleImage:
	cd config/; gcc -c mainGrayScaleImage.c -o ../mainGrayScaleImage.o
	cd config/; gcc -c assert_with_message.c -o ../assert_with_message.o
	cd config/; gcc -c ../grayScaleImage.c -o ../grayScaleImage.o
	cd config/; gcc mainGrayScaleImage.o assert_with_message.o grayScaleImage.o -o ../grayScaleImageTest
	./grayScaleImageTest

# Règle pour tester le fichier ColoredBitmap
test_ColoredBitmap:
	cd config/; gcc -c mainColoredBitmap.c -o ../mainColoredBitmap.o
	cd config/; gcc -c assert_with_message.c -o ../assert_with_message.o
	cd config/; gcc -c ../coloredBitmap.c -o ../coloredBitmap.o
	cd config/; gcc mainColoredBitmap.o assert_with_message.o coloredBitmap.o -o ../coloredBitmapTest
	./coloredBitmapTest

# Règle pour tester le fichier video
test_video:
	cd config/; gcc -c mainVideo.c -o ../mainVideo.o
	cd config/; gcc -c assert_with_message.c -o ../assert_with_message.o
	cd config/; gcc -c ../video.c -o ../video.o
	cd config/; gcc mainVideo.o assert_with_message.o video.o -o ../videoTest
	./videoTest
