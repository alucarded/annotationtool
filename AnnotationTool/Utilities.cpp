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
    int stride = colorImage.step;
    try {
        switch (colorImage.type())
        {
        case CV_8UC3: // non-grayscale images are correctly displayed here
           b = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, stride,
               System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
           break;
        case CV_8UC1: // grayscale images are incorrectly displayed here 
            b = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, stride,
               System::Drawing::Imaging::PixelFormat::Format8bppIndexed, ptr);
            break;
        default:
            b = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, stride,
                System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
            break;
        }
    } catch (System::ArgumentException^ e) {
        System::Windows::Forms::MessageBox::Show(
            e->Message,
            e->GetType()->Name, System::Windows::Forms::MessageBoxButtons::OK,
            System::Windows::Forms::MessageBoxIcon::Error);
    }
    return b;
}

void GetFilesInFolder(System::String ^ root_path, System::Collections::ArrayList^ files, const array<System::String^>^ supported, bool recursive)
{
    using System::String;
    using System::Collections::Queue;
    using namespace System::IO;

    // Search recursively
    Queue^ q = gcnew Queue();
    q->Enqueue(root_path);
    while (q->Count > 0) {
        String^ path = safe_cast<String^>(q->Dequeue());

        // Add all files
        array<String^>^ all_files = Directory::GetFiles(path);
        System::Collections::IEnumerator^ en = all_files->GetEnumerator();
        while (en->MoveNext()) {
            String^ file_path = safe_cast<String^>(en->Current);
            FileInfo ^ info = gcnew FileInfo(file_path);
            if (IsExtensionSupported(supported, info->Extension)) {
                file_path = file_path->Replace(root_path, L"");
                int pos = 0;
                while (file_path[pos] == '\\') pos++;
                file_path = file_path->Substring(pos);
                files->Add(file_path);
            }
        }

        if (!recursive) break;

        // Recurse
        array<String^>^ dirs = Directory::GetDirectories(path);
        en = dirs->GetEnumerator();
        while (en->MoveNext()) {
            String^ dir_path = safe_cast<String^>(en->Current);
            q->Enqueue(dir_path);
        }
    }
}

bool IsExtensionSupported(const array<System::String^>^ supported, System::String ^ ext)
{
    for each (System::String^ str in supported) {
        if (0 == System::String::Compare(str, ext)) {
            return true;
        }
    }
    return false;
}

array<System::String^>^ SupportedImageExtensions()
{
    array<System::String^>^ supported_image_extensions;
#ifdef OPENCV_IMAGE_LOAD
    // Extensions supported in OpenCV
    supported_image_extensions = gcnew array<System::String^>{".bmp",
        ".pbm", ".pgm", ".ppm",
        ".sr", ".ras",
        ".jpeg", ".jpg", ".jpe",
        ".jp2",
        ".tiff", ".tif",
        ".png"};
#else
    // TODO: this may be not complete - check
    supported_image_extensions = gcnew array<System::String^>{".bmp",
        ".emf",
        ".exif",
        ".jpeg", ".jpg", ".jpe",
        ".gif",
        ".tiff", ".tif",
        ".png",
        ".wmf"};
#endif
    return supported_image_extensions;
}
