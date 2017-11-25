#include "AddFolderPresenter.h"
#include "Utilities.h"

#include <queue>

AddFolderPresenter::AddFolderPresenter(IAddFolderView ^ view, AnnotationModel * model) : m_view(view), m_model(model)
{
    m_view->NewFolderAdded += gcnew SendPathData(this, &AddFolderPresenter::OnNewFolderAdded);
}

AddFolderPresenter::~AddFolderPresenter()
{
}

void AddFolderPresenter::OnNewFolderAdded(System::String ^ root_path, bool is_recursive)
{
    using namespace System::Collections;
    System::Collections::ArrayList^ image_paths = gcnew ArrayList();
    GetImageFilesInFolder(root_path, image_paths, is_recursive);
    m_view->AddPaths(root_path, image_paths, is_recursive);
    m_model->AddFolder(MarshalString(root_path), is_recursive);
}

// TODO: This functionality should go to separate model class ?
void AddFolderPresenter::GetImageFilesInFolder(System::String ^ root_path, System::Collections::ArrayList^ image_names, bool recursive)
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
            if (IsImageExtension(info->Extension)) {
                file_path = file_path->Replace(root_path, L"");
                int pos = 0;
                while (file_path[pos] == '\\') pos++;
                file_path = file_path->Substring(pos);
                image_names->Add(file_path);
            }
        }

        // Recurse
        array<String^>^ dirs = Directory::GetDirectories(path);
        en = dirs->GetEnumerator();
        while (en->MoveNext()) {
            String^ dir_path = safe_cast<String^>(en->Current);
            q->Enqueue(dir_path);
        }
    }
}

bool AddFolderPresenter::IsImageExtension(System::String ^ ext)
{
    for each (System::String^ str in SUPPORTED_IMAGE_EXTENSIONS) {
        if (0 == System::String::Compare(str, ext)) {
            return true;
        }
    }
    return false;
}