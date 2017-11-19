#pragma once

#include <iostream>
#include <string>

#include <opencv2/core/core.hpp>

void MarshalString(System::String ^ s, std::string& os);
std::string MarshalString(System::String ^ s);
System::Drawing::Bitmap^ Mat2Bitmap(cv::Mat & colorImage);