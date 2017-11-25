#pragma once

#include "IAddFolderView.h"
#include "AnnotationModel.h"

#pragma managed

public ref class AddFolderPresenter
{
public:
    AddFolderPresenter(IAddFolderView^ view, AnnotationModel * model);
    ~AddFolderPresenter();

    // Extensions supported in OpenCV
    static const array<System::String^>^ SUPPORTED_IMAGE_EXTENSIONS = gcnew array<System::String^>{".bmp",
        ".pbm", ".pgm", ".ppm",
        ".sr", ".ras",
        ".jpeg", ".jpg", ".jpe",
        ".jp2",
        ".tiff", ".tif",
        ".png"};
private:
    void OnNewFolderAdded(System::String^ root_path, bool is_recursive);
    void GetImageFilesInFolder(System::String ^ root_path, System::Collections::ArrayList^ image_names, bool recursive);
    bool IsImageExtension(System::String ^ ext);
private:
    IAddFolderView^ m_view;
    AnnotationModel * m_model;
};