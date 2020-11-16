//============================================================================
// Name        : Dip1.cpp
// Author      : Ronny Haensch
// Version     : 2.0
// Copyright   : -
// Description : 
//============================================================================

#include "Dip1.h"

#include <stdexcept>

namespace dip1 {


/**
 * @brief function that performs some kind of (simple) image processing
 * @param img input image
 * @returns output image
 */
cv::Mat doSomethingThatMyTutorIsGonnaLike(const cv::Mat& img) {

	int L = 256;
	cv::Mat aux = img.clone();
	
	for(int i=0; i<img.rows; ++i)
	{
		for(int j=0; j<img.cols; ++j){
		
			aux.at<cv::Vec3d>(i, j)[0] = (L-1) -img.at<cv::Vec3d>(i, j)[0];
			aux.at<cv::Vec3d>(i, j)[1] = (L-1) -img.at<cv::Vec3d>(i, j)[1];
			aux.at<cv::Vec3d>(i, j)[2] = (L-1) -img.at<cv::Vec3d>(i, j)[2];
		}
	}
    return aux;
}





/******************************
      GIVEN FUNCTIONS
 ******************************/

/**
 * @brief function loads input image, calls processing function, and saves result
 * @param fname path to input image
 */
void run(const std::string &filename) {

    // window names
    std::string win1 = "Original image";
    std::string win2 = "Result";

    // some images
    cv::Mat inputImage, outputImage;

    // load image
    std::cout << "loading image" << std::endl;
    inputImage = cv::imread(filename);
    std::cout << "done" << std::endl;
    
    // check if image can be loaded
    if (!inputImage.data)
        throw std::runtime_error(std::string("ERROR: Cannot read file ") + filename);

    // show input image
    cv::namedWindow(win1.c_str());
    cv::imshow(win1.c_str(), inputImage);
    
    // do something (reasonable!)
    outputImage = doSomethingThatMyTutorIsGonnaLike(inputImage);
    
    // show result
    cv::namedWindow(win2.c_str());
    cv::imshow(win2.c_str(), outputImage);
    
    // save result
    cv::imwrite("result.jpg", outputImage);
    
    // wait a bit
    cv::waitKey(0);
}


}
