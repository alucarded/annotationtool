#pragma once

public delegate void ObjectSet(System::String^ obj_name, double % aspect_ratio);
public delegate void ImageSet(System::String^ image_path);
public delegate void AnnotationAdded(int x, int y, int w, int h);
public delegate void ProjectLoaded(System::String^ file_path);

public interface class IAnnotationView
{
public:
    virtual void UpdateProject(System::String^ name, System::String^ description, int mode) = 0;
    virtual void AddObject(System::String^ name) = 0;
    virtual void AddPaths(System::String^ root_path, System::Collections::ArrayList^ image_names, bool is_recursive) = 0;
    virtual void DisplayImage(System::Drawing::Image^ image) = 0;
    event ObjectSet^ ObjectNodeSelected;
    event ImageSet^ ImageNodeSelected;
    event AnnotationAdded^ AnnotationDrawn;
    event ProjectLoaded^ ProjectLoadedEvent;
};

