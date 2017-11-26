#pragma once

#include <iostream>
#include <string>

#include <opencv2/core/core.hpp>

void MarshalString(System::String ^ s, std::string& os);
std::string MarshalString(System::String ^ s);
System::Drawing::Bitmap^ Mat2Bitmap(cv::Mat & colorImage);
void GetFilesInFolder(System::String ^ root_path, System::Collections::ArrayList^ files, const array<System::String^>^ supported, bool recursive);
bool IsExtensionSupported(const array<System::String^>^ supported, System::String ^ ext);
array<System::String^>^ SupportedImageExtensions();