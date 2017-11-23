#pragma once
#pragma unmanaged

#include <string>
#include <vector>
#include <unordered_map>

struct Annotation {
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

    void AddObject(const std::string& name, double aspect_ratio);
    void AddAnnotation(int x, int y, int w, int h);

    void SaveAnnotations(const std::string& path);
private:
    std::string m_project_name;
    std::string m_description;
    Mode m_mode;
    std::string m_current_object;
    std::string m_current_image_path;
    std::unordered_map<std::string, Object> m_objects;
    std::unordered_multimap<std::string, Annotation> m_image_annotations; // maps absolute image path to annotations
};