#pragma once
#pragma unmanaged

#include <string>
#include <vector>
#include <unordered_map>

struct Annotation {
    Annotation() : m_object_name(), m_x(0), m_y(0), m_width(0), m_height(0) { }
    Annotation(const std::string& object_name, int x, int y, int w, int h)
        : m_object_name(object_name), m_x(x), m_y(y), m_width(w), m_height(h) { }
    std::string m_object_name;
    int m_x, m_y;
    int m_width, m_height;
};

class AnnotationModel
{
public:
    AnnotationModel();
    ~AnnotationModel();

    enum Mode {
        BOUNDING_BOX = 0
    };

    struct Object {
        Object() : m_name(), m_desc(), m_aspect_ratio(0.0) { }
        Object(std::string name, std::string desc, double aspect_ratio = 0.0)
            : m_name(name), m_desc(desc), m_aspect_ratio(aspect_ratio) { }

        std::string m_name;
        std::string m_desc;
        double m_aspect_ratio;
    };

    void GetAnnotationsForImage(const std::string& path, std::vector<Annotation>& annotations);
    void GetAspectRatio(const std::string& object_name, double & aspect_ratio);

    void SetProjectDetails(const std::string& name, const std::string& desc, int mode);
    void SetCurrentObject(const std::string& name);
    void SetImage(const std::string& name);

    void AddObject(const std::string& name, const std::string& desc, double aspect_ratio);
    void AddObject(const Object& obj);
    bool AddFolder(const std::string& path, bool is_recursive);
    void AddAnnotation(const std::string& img_path, const std::string& obj_name, int x, int y, int w, int h);
    void AddAnnotation(const std::string& img_path, const Annotation& annotation);
    void AddAnnotation(int x, int y, int w, int h);

    void SaveProject(const std::string& path);
    void LoadProject(const std::string& path);

    void Reset();
private:
    std::string m_project_name;
    std::string m_description;
    Mode m_mode;
    std::string m_current_object;
    std::string m_current_image_path;
    std::unordered_map<std::string, Object> m_objects;
    std::unordered_map<std::string, bool> m_folders;
    std::unordered_multimap<std::string, Annotation> m_image_annotations; // maps absolute image path to annotations
};