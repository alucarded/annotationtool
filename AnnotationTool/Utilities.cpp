#include "Utilities.h"

void MarshalString(System::String ^ s, std::string& os) {
    using namespace System::Runtime::InteropServices;
    if (nullptr == s) {
        std::cerr << "Input System::String is null!" << std::endl;
        return;
    }
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    os = chars;
    Marshal::FreeHGlobal(System::IntPtr((void*)chars));
}

std::string MarshalString(System::String ^ s) {
    std::string ret;
    MarshalString(s, ret);
    return ret;
}

System::Drawing::Bitmap^ Mat2Bitmap(cv::Mat & colorImage) {
    System::IntPtr ptr(colorImage.ptr());
    System::Drawing::Bitmap^ b;
    switch (colorImage.type())
    {
    case CV_8UC3: // non-grayscale images are correctly displayed here
        b = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step,
            System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
        break;
    case CV_8UC1: // grayscale images are incorrectly displayed here 
        b = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step,
            System::Drawing::Imaging::PixelFormat::Format8bppIndexed, ptr);
        break;
    default:
        b = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step,
            System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
        break;
    }
    return b;
}