#pragma once

public delegate void SendPathData(System::String^ root_path, bool is_recursive);

public interface class IAddFolderView
{
public:
    virtual void AddPaths(System::String^ root_path, System::Collections::ArrayList^ image_names, bool is_recursive) = 0;
    event SendPathData^ NewFolderAdded;
};